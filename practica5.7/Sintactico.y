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

bloque : INICIOBLOQUE { TS_InsertaMarca(); tabulacion++;} declar_variables_locales declar_subprogs {if(cont_bloque==0){ fprintf(principal, "int main(){\n"); imprimirInits();}} sentencias FINBLOQUE { if(cont_bloque==0){fprintf(principal, "\n}\n"); } tabulacion--; TS_VaciarEntradas();} ;

declar_variables_locales : VAR { declarVar = 1; } variables_locales PUNTOYCOMA { declarVar = 0; } | ;

variables_locales : variables_locales cuerpo_declar_variables
	| cuerpo_declar_variables  ;

cuerpo_declar_variables : tipo lista_variables PUNTOYCOMA { listaGlobal=0; tipoGlobal=DESC; }
	| error ;

lista_variables : variable COMA lista_variables 
	| variable error lista_variables
	| variable ;

variable : IDENT { 
		if(declarVar == 1) { TS_InsertaIdent($1); generaDecVar($1);}
		else if(declarPar == 1) { numParam++; TS_InsertaParamFormal($1);}
		else if(leer==1){generaEntSal(1,$1);}
		else { TS_GetIdent($1, &$$); }
		listaActual=$1.lexema;
	} ;

declar_subprogs : declar_subprogs declar_subprog | ;

declar_subprog : {tabular();} cabecera_subprograma { subProg = 1; } INICIO sentencias FIN PUNTOYCOMA{ subProg = 0; fprintf(principal, "}\n");} ;

cabecera_subprograma : PROCEDIMIENTO IDENT { declarPar = 1; TS_InsertaSubprog($2); fprintf(principal, "void %s(", $2.lexema);} PARIZQ lista_parametros PARDER  { TS_ActualizaNparam($1); numParam = 0; declarPar = 0; GCI_DeclarPar(); fprintf(principal, "){\n");} PUNTOYCOMA
						| PROCEDIMIENTO IDENT PUNTOYCOMA { TS_InsertaSubprog($2); fprintf(principal, "void %s(){\n", $2.lexema);};

lista_parametros : parametro PUNTOYCOMA lista_parametros 
	| parametro error PUNTOYCOMA lista_parametros
	| parametro ;

parametro : lista_variables DOSP tipo {actualizarTipo($1); listaGlobal=0;};

sentencias : { declarVar = 2; } sentencia sentencias | ;

sentencia : { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } cont_bloque++;} bloque {cont_bloque--;}
	| asignacion {fputs("\n", principal);}
	| { decIf=1; insertaDesc(1); } si PUNTOYCOMA { decIf=0; eliminaDesc(); }{fputs("\n", principal);}
	| { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } insertaDesc(2); insertaEtiqEntrada(); fputs("{\n", principal);} mientras {fputs("\n", principal);}
	| { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } } entrada {fputs("\n", principal);}
	| { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } } salida {fputs("\n", principal);}
	| { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } } for {fputs("\n", principal);}
	| llamada_funcion {$$.tipo = $1.tipo; $$.numDim = $1.numDim;  funcionActual = -1; fputs("\n", principal);}
	| variable AVANRETR PUNTOYCOMA {if($1.numDim==0){printf("ERROR [Linea %d]: %s NO ES UNA LISTA\n", lineaActual, $1.lexema);}}
	| DOLAR variable PUNTOYCOMA {if($2.numDim==0){printf("ERROR [Linea %d]: %s NO ES UNA LISTA\n", lineaActual, $2.lexema);}};

asignacion : variable ASIGNACION expresion PUNTOYCOMA
		{ if($1.tipo!=$3.tipo) {  printf("Error asign linea %d: Los tipos de la parte izquierda %d y derecha %d no coinciden.\n",lineaActual, $1.tipo, $3.tipo); }
		else if(!igualTam($1,$3))  { printf("Error asign linea %d: La parte izquierda y la parte derecha deben tener el mismo tamanyo.\n",lineaActual); } 
		else { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } 
				if($1.numDim==0){genera(4,$1,$2,$3,$4);} else{} } };

si : SI PARIZQ expresion PARDER ENTONCES sentencia 
	{ if($3.tipo != BOOLEANO) { printf("Error si linea %d: La expresion no es de tipo logico.\n", lineaActual);}
		$$.lexema=$3.lexema; fputs("}\n", principal); insertaEtiqElse(); fputs("{}\n", principal); }
	| SI PARIZQ expresion PARDER ENTONCES sentencia { if($3.tipo != BOOLEANO) { printf("Error si linea %d: La expresion no es de tipo logico.\n", lineaActual);} $$.lexema=$3.lexema;}
	  SINO {decElse=1; fputs("}\n", principal); insertaEtiqElse(); fputs("{\n", principal); decElse=0;} 
	  sentencia {fputs("}\n", principal); insertaEtiqSalida(); fputs("{}\n", principal); $$.lexema=$3.lexema;};
	
		
mientras : MIENTRAS PARIZQ expresion PARDER {insertaCond(2);} sentencia PUNTOYCOMA
	{ if($3.tipo != BOOLEANO) { printf("Error mientras linea %d: La expresion no es de tipo logico.\n", lineaActual);}
		$$.lexema=$3.lexema; fputs("}\n", principal); insertaGotoEntrada(); insertaEtiqSalida(); fputs("{}\n", principal); } ;

entrada : LEER {leer=1;} lista_variables PUNTOYCOMA {leer=0;} ;

salida : ESCRIBIR {escribir=1;} lista_expresiones_cad PUNTOYCOMA {escribir=0;};

for : PARA variable DOSP ASIGNACION expresion 
        HASTA expresion HACER
        INICIO
		{ if($5.tipo != $7.tipo) { printf("ERROR [Linea %d]: LOS TIPOS DE LA ASIGNACION Y CONDICIÓN SON DISTINTOS.\n", lineaActual);}
			insertaDesc(2); 
			fprintf(principal, "%s=%s;\n", $2.lexema, $5.lexema);
			insertaEtiqEntrada(); fputs("{\n", principal);
			fprintf(principal, "int temp%d = %s == %s;\n", temp, $2.lexema, $7.lexema); temp++;
			insertaCond(2);
		} 
		sentencia
		{	fprintf(principal, "%s++;\n", $2.lexema);
			fputs("}\n", principal);
			insertaGotoEntrada(); 
			insertaEtiqSalida(); 
			fputs("{}\n", principal);
			}
        FIN PUNTOYCOMA
		;

expresion : PARIZQ expresion PARDER { $$.tipo = $2.tipo; $$.numDim = $2.numDim;  $$.lexema=$2.lexema;}
	| OPUNARIO expresion {TS_OpUnario($1, $2, &$$); generarUnario(&$$, $1, $2); }
	| SUMRES expresion %prec OPUNARIO {TS_OpSumResUnario($1, $2, &$$); generarUnario(&$$, $1, $2); }
	| expresion OPBINARIO expresion {TS_OpMulDiv($1, $2, $3, &$$); generarBinario(&$$,$1, $2, $3); }
	| expresion OPOR expresion {TS_OpOrXor($1, $2, $3, &$$); generarBinario(&$$,$1, $2, $3); }
	| expresion OPRELACIONAL expresion {TS_OpRel($1, $2, $3, &$$); generarBinario(&$$,$1, $2, $3); }
	| expresion SUMRES expresion { TS_OpSumRes($1, $2, $3, &$$); generarBinario(&$$,$1, $2, $3); }
	| expresion OPAND expresion {TS_OpAnd($1, $2, $3, &$$); generarBinario(&$$,$1, $2, $3); }
	| expresion OPBINLISTA expresion {TS_OpBinListas($1, $2, $3, &$$); generarBinario(&$$,$1, $2, $3); }
	| expresion ARROBA expresion {TS_OpBinArroba($1, $2, $3, &$$); generaArroba(&$$, $1, $3);}
	| expresion ARROBA expresion MASMAS expresion { $$.numDim=1; TS_OpTerciario($1, $3, $5, &$$); generaArrobaMasMas($$, $1, $3, $5);}
	| variable { declarVar = 0; $$.lexema=$1.lexema;}
	| constante { $$.tipo = $1.tipo; $$.numDim = $1.numDim; $$.lexema=$1.lexema;}
	| CORIZQ agregado CORDER {$$.tipo=$2.tipo; $$.numDim=1; }
	| error ;

lista_expresiones : expresion COMA lista_expresiones { numParam++; TS_CompruebaParametro($1, numParam); strcat($$.lexema, ", "); strcat($1.lexema, "&"); strcat($$.lexema, $3.lexema);}
	| expresion  { numParam = 1; TS_CompruebaParametro($1, numParam);  } ;

lista_expresiones_cad : exp_cad COMA lista_expresiones_cad 
	| exp_cad ;

exp_cad : expresion {generaEntSal(2,$1);} | CONSTCADENA { $1.tipo=STRING; generaEntSal(2,$1);};

constante : CONSTENTERA { $$.tipo = ENTERO; $$.numDim = 0;  }
	| CONSTLOGICA { $$.tipo = BOOLEANO; $$.numDim = 0;  }
	| CONSTREAL { $$.tipo = REAL; $$.numDim = 0;  }
	| CONSTCARACTER { $$.tipo = CARACTER; $$.numDim = 0; };

llamada_funcion : IDENT PARIZQ {funcionActual=TS_BuscarFuncion($1); } lista_expresiones PARDER PUNTOYCOMA { TS_LlamadaFuncion($1, &$$); fprintf(principal, "%s(&%s);\n", $1.lexema, $4.lexema);}
	| IDENT PARIZQ PARDER PUNTOYCOMA { TS_LlamadaFuncion($1, &$$); fprintf(principal, "%s();\n", $1.lexema);} ;

agregado : agregado_enteros {$$.tipo=ENTERO;}
			| agregado_reales {$$.tipo=REAL; }
			| agregado_caracteres {$$.tipo=CARACTER;}
			| agregado_booleanos {$$.tipo=BOOLEANO;}
			| agregado_cadenas {$$.tipo=CONSTCADENA;};

agregado_enteros :	agregado_enteros COMA CONSTENTERA {strcat($$.lexema, $2.lexema); strcat($$.lexema, $3.lexema);
														fprintf(principal, "insertItem(%s, %s);\n", listaActual, $3.lexema);}
					| CONSTENTERA {fprintf(principal, "insertItem(%s, %s);\n", listaActual, $1.lexema);};

agregado_reales :	agregado_reales COMA CONSTREAL {strcat($$.lexema, $2.lexema); strcat($$.lexema, $3.lexema); 
													 fprintf(principal, "insertFirstFloat(%s);\n", $3.lexema);}
					| CONSTREAL {fprintf(principal, "insertFirstFloat(%s);\n", $1.lexema);};

agregado_caracteres :	agregado_caracteres COMA CONSTCARACTER {strcat($$.lexema, $2.lexema); strcat($$.lexema, $3.lexema);}
					| CONSTCARACTER;

agregado_booleanos :	agregado_booleanos COMA CONSTLOGICA {strcat($$.lexema, $2.lexema); strcat($$.lexema, $3.lexema);}
					| CONSTLOGICA;

agregado_cadenas :	agregado_cadenas COMA CONSTCADENA {strcat($$.lexema, $2.lexema); strcat($$.lexema, $3.lexema);}
					| CONSTCADENA;

tipo : LISTA TIPOBASICO {listaGlobal=1; asignaTipoGlobal($2); }
		| TIPOBASICO {asignaTipoGlobal($1);}
		| error;

%%


/** Aqui incluimos el fichero generado por el ’lex’
*** que implementa la función ’yylex’
**/

#include "lex.yy.c"

