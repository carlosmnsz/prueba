%{


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "GCI.c"

/* 
** La siguiente declaracion permite que ’yyerror’ se pueda invocar desde el
** fuente de lex (prueba.l)
*/


int yylex();
void yyerror(const char*);
/* 
** La siguiente variable se usará para conocer el numero de la línea
** que se esta leyendo en cada momento. También es posible usar la variable
** ’yylineno’ que también nos muestra la línea actual. Para ello es necesario
** invocar a flex con la opción ’-l’ (compatibilidad con lex).
*/



%}

%define parse.error verbose

%left OPOR
%left OPAND
%left OPRELACIONAL
%left SUMRES
%left OPBINARIO
%right OPUNARIO
%left OPBINLISTA
%left ARROBA
%left MASMAS

%token ASIGNACION
%token CORIZQ
%token CORDER
%token TIPOBASICO
%token CONSTENTERA 
%token CONSTLOGICA 
%token CONSTREAL 
%token CONSTCARACTER 
%token CONSTCADENA 
%token COMA 
%token PARDER 
%token PARIZQ 
%token PUNTOYCOMA 
%token INICIOBLOQUE 
%token FINBLOQUE 
%token VAR 
%token SI 
%token SINO 
%token MIENTRAS 
%token LEER 
%token ESCRIBIR 
%token HASTA 
%token PRINCIPAL 
%token PROCEDIMIENTO
%token DOSP
%token INICIO
%token FIN
%token ENTONCES
%token PARA
%token HACER
%token AVANRETR
%token DOLAR
%token LISTA
%token IDENT 

%%

/***********************  PRODUCCIONES  **************************/

programa : {abrirFicherosGCI();} PRINCIPAL bloque {cerrarFicherosGCI();};

bloque : INICIOBLOQUE { TS_InsertaMarca(); } declar_variables_locales declar_subprogs sentencias FINBLOQUE { imprimeTS(); TS_VaciarEntradas();} ;

declar_variables_locales : VAR { declarVar = 1; } variables_locales PUNTOYCOMA { declarVar = 0; } | ;

variables_locales : variables_locales cuerpo_declar_variables
	| cuerpo_declar_variables  ;

cuerpo_declar_variables : tipo lista_variables PUNTOYCOMA {listaGlobal=0; tipoGlobal=DESC; }
	| error ;

lista_variables : variable COMA lista_variables 
	| variable error lista_variables
	| variable ;

variable : IDENT { 
		if(declarVar == 1) { TS_InsertaIdent($1); generaDecVar($1);}
		else if(declarPar == 1) { numParam++; TS_InsertaParamFormal($1); }
		else { TS_GetIdent($1, &$$); }  
	} ;

declar_subprogs : declar_subprogs declar_subprog | ;

declar_subprog : cabecera_subprograma { subProg = 1; } INICIO sentencias FIN PUNTOYCOMA{ subProg = 0; fprintf(principal, "}\n");} ;

cabecera_subprograma : PROCEDIMIENTO IDENT { declarPar = 1; TS_InsertaSubprog($2); fprintf(principal, "void %s(", $2.lexema);} PARIZQ lista_parametros PARDER  { TS_ActualizaNparam($1); numParam = 0; declarPar = 0; GCI_DeclarPar(); fprintf(principal, "){\n");} PUNTOYCOMA
						| PROCEDIMIENTO IDENT PUNTOYCOMA { TS_InsertaSubprog($2); fprintf(principal, "void %s(){\n", $2.lexema);};

lista_parametros : parametro PUNTOYCOMA lista_parametros 
	| parametro error PUNTOYCOMA lista_parametros
	| parametro ;

parametro : lista_variables DOSP tipo {actualizarTipo($1); generaDecPar($1); listaGlobal=0;};

sentencias : { declarVar = 2; } sentencia sentencias | ;

sentencia : { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } } bloque
	| asignacion 
	| { decIf=1; insertaDesc(1); } si PUNTOYCOMA { decIf=0; eliminaDesc(); }
	| { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } insertaDesc(2); insertaEtiqEntrada(); fputs("{\n", principal);} mientras PUNTOYCOMA
	| { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } } entrada PUNTOYCOMA
	| { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } } salida PUNTOYCOMA
	| repetir_hasta PUNTOYCOMA 
	| llamada_funcion PUNTOYCOMA {$$.tipo = $1.tipo; $$.numDim = $1.numDim;  funcionActual = -1;}
	| variable AVANRETR PUNTOYCOMA {if($1.numDim==0){printf("ERROR [Linea %d]: %s NO ES UNA LISTA\n", lineaActual, $1.lexema);}}
	| DOLAR variable PUNTOYCOMA {if($2.numDim==0){printf("ERROR [Linea %d]: %s NO ES UNA LISTA\n", lineaActual, $2.lexema);}};

asignacion : variable ASIGNACION expresion PUNTOYCOMA
		{ if($1.tipo!=$3.tipo) {  printf("Error asign linea %d: Los tipos de la parte izquierda %d y derecha %d no coinciden.\n",lineaActual, $1.tipo, $3.tipo); }
		else if(!igualTam($1,$3))  { printf("Error asign linea %d: La parte izquierda y la parte derecha deben tener el mismo tamanyo.\n",lineaActual); } 
		else { { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } genera(4,$1,$2,$3,$4); } } };

si : SI PARIZQ expresion PARDER ENTONCES sentencia 
	{ if($3.tipo != BOOLEANO) { printf("Error si linea %d: La expresion no es de tipo logico.\n", lineaActual);}
		$$.lexema=$3.lexema; fputs("}\n", principal); insertaEtiqElse(); fputs("{}\n", principal); }
	| SI PARIZQ expresion PARDER ENTONCES sentencia { if($3.tipo != BOOLEANO) { printf("Error si linea %d: La expresion no es de tipo logico.\n", lineaActual);} $$.lexema=$3.lexema;}
	  SINO {decElse=1; fputs("}\n", principal); insertaEtiqElse(); fputs("{\n", principal); decElse=0;} 
	  sentencia {fputs("}\n", principal); insertaEtiqSalida(); fputs("{}\n", principal); };
	
		
		

mientras : MIENTRAS PARIZQ expresion PARDER {insertaCond(2);} sentencia
	{ if($3.tipo != BOOLEANO) { printf("Error mientras linea %d: La expresion no es de tipo logico.\n", lineaActual);}
		$$.lexema=$3.lexema; fputs("}\n", principal); insertaGotoEntrada(); insertaEtiqSalida(); fputs("{}\n", principal); } ;

entrada : LEER lista_variables {generaEntSal(1,$2);};

salida : ESCRIBIR lista_expresiones_cad {generaEntSal(2,$2);};

repetir_hasta : PARA variable DOSP ASIGNACION expresion 
                HASTA expresion HACER
                INICIO
                sentencias  
                FIN
		{ if($5.tipo != BOOLEANO) { printf("Error until linea %d: La expresion no es de tipo logico.\n", lineaActual);}
		  if($7.tipo != BOOLEANO) { printf("Error until linea %d: La expresion no es de tipo logico.\n", lineaActual);}} ;

expresion : PARIZQ expresion PARDER { $$.tipo = $2.tipo; $$.numDim = $2.numDim;  $$.lexema=$2.lexema;}
	| OPUNARIO expresion {TS_OpUnario($1, $2, &$$); generarUnario(&$$, $1, $2); }
	| SUMRES expresion %prec OPUNARIO {TS_OpSumResUnario($1, $2, &$$); generarUnario(&$$, $1, $2); }
	| expresion OPBINARIO expresion {TS_OpMulDiv($1, $2, $3, &$$); generarBinario(&$$,$1, $2, $3); }
	| expresion OPOR expresion {TS_OpOrXor($1, $2, $3, &$$); generarBinario(&$$,$1, $2, $3); }
	| expresion OPRELACIONAL expresion {TS_OpRel($1, $2, $3, &$$); generarBinario(&$$,$1, $2, $3); }
	| expresion SUMRES expresion { TS_OpSumRes($1, $2, $3, &$$); generarBinario(&$$,$1, $2, $3); }
	| expresion OPAND expresion {TS_OpAnd($1, $2, $3, &$$); generarBinario(&$$,$1, $2, $3); }
	| expresion OPBINLISTA expresion {TS_OpBinListas($1, $2, $3, &$$); generarBinario(&$$,$1, $2, $3); }
	| expresion ARROBA expresion {TS_OpBinArroba($1, $2, $3, &$$); generarBinario(&$$,$1, $2, $3); }
	| expresion ARROBA expresion MASMAS expresion {TS_OpTerciario($1, $3, $5, &$$);}
	| variable { declarVar = 0; $$.lexema=$1.lexema;}
	| constante { $$.tipo = $1.tipo; $$.numDim = $1.numDim; $$.lexema=$1.lexema;}
	| CORIZQ agregado CORDER {$$.tipo=$2.tipo; $$.numDim=1; }
	| error ;

lista_expresiones : expresion COMA lista_expresiones  { numParam++; TS_CompruebaParametro($1, numParam); }
	| expresion  { numParam = 1; TS_CompruebaParametro($1, numParam); } ;

lista_expresiones_cad : exp_cad COMA lista_expresiones_cad
	| exp_cad {$$.lexema=$1.lexema;};

exp_cad : expresion | CONSTCADENA {$$.lexema=$1.lexema;};

constante : CONSTENTERA { $$.tipo = ENTERO; $$.numDim = 0;  }
	| CONSTLOGICA { $$.tipo = BOOLEANO; $$.numDim = 0;  }
	| CONSTREAL { $$.tipo = REAL; $$.numDim = 0;  }
	| CONSTCARACTER { $$.tipo = CARACTER; $$.numDim = 0; } ;

llamada_funcion : IDENT PARIZQ {funcionActual=TS_BuscarFuncion($1);} lista_expresiones PARDER { TS_LlamadaFuncion($1, &$$); }
	| IDENT PARIZQ PARDER { TS_LlamadaFuncion($1, &$$); } ;

agregado : agregado_enteros {$$.tipo=ENTERO;}
			| agregado_reales {$$.tipo=REAL; }
			| agregado_caracteres {$$.tipo=CARACTER;}
			| agregado_booleanos {$$.tipo=BOOLEANO;}
			| agregado_cadenas {$$.tipo=CONSTCADENA;};

agregado_enteros :	agregado_enteros COMA CONSTENTERA
					| CONSTENTERA;

agregado_reales :	agregado_reales COMA CONSTREAL {}
					| CONSTREAL {};

agregado_caracteres :	agregado_caracteres COMA CONSTCARACTER
					| CONSTCARACTER;

agregado_booleanos :	agregado_booleanos COMA CONSTLOGICA
					| CONSTLOGICA;

agregado_cadenas :	agregado_cadenas COMA CONSTCADENA
					| CONSTCADENA;

tipo : LISTA TIPOBASICO {listaGlobal=1; asignaTipoGlobal($2); }
		| TIPOBASICO {asignaTipoGlobal($1); }
		| error;

%%


/** Aqui incluimos el fichero generado por el ’lex’
*** que implementa la función ’yylex’
**/

#include "lex.yy.c"

