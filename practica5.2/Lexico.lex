%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Sintactico.tab.h"

%}

%option noyywrap

%%

"programa"						{ return(PRINCIPAL); }
"procedimiento"                 { return(PROCEDIMIENTO);}
"entonces"                      { return(ENTONCES);}
"inicio"                        { return(INICIO);}
"fin"                           { return(FIN);}
"hasta_aumento"					{ return(HASTA); }
"hasta_decremento"				{ return(HASTA); }
"entrada"						{ return(LEER); }
"salida"						{ return(ESCRIBIR); }
"mientras"						{ return(MIENTRAS); }
"si"							{ return(SI); }
"sino"							{ return(SINO); }
"<<"                            { yylval.lexema=strdup(yytext); return (AVANRETR);}
">>"                            { yylval.lexema=strdup(yytext); return (AVANRETR);}
"$"                             { yylval.lexema=strdup(yytext); return (DOLAR);}
"@"                             { yylval.lexema=strdup(yytext); return (ARROBA);}
"++"                            { yylval.lexema=strdup(yytext); return (MASMAS);}
":"                             { yylval.lexema=strdup(yytext); return (DOSP);}
"="								{ yylval.lexema=strdup(yytext); return(ASIGNACION); }
"{"								{ yylval.lexema=strdup(yytext); return(INICIOBLOQUE); }
"}"								{ yylval.lexema=strdup(yytext); return(FINBLOQUE); }
"var"							{ return(VAR); }
"entero"						{ yylval.tipo = ENTERO; return(TIPOBASICO); }
"real"							{ yylval.tipo = REAL; return(TIPOBASICO); }
"caracter"						{ yylval.tipo = CARACTER; return(TIPOBASICO); }
"logico"						{ yylval.tipo = BOOLEANO; return(TIPOBASICO); }
"lista"                         { return(LISTA);}
"["								{ yylval.lexema=strdup(yytext); return(CORIZQ); }
"]"								{ yylval.lexema=strdup(yytext); return(CORDER); }
","								{ yylval.lexema=strdup(yytext); return(COMA); }
"("								{ yylval.lexema=strdup(yytext); return(PARIZQ); }
")"								{ yylval.lexema=strdup(yytext); return(PARDER); }
";"								{ yylval.lexema=strdup(yytext); return(PUNTOYCOMA); }
"+"								{ yylval.lexema=strdup(yytext); return(SUMRES); }
"-"								{ yylval.lexema=strdup(yytext); return(SUMRES); }
"*"								{ yylval.lexema=strdup(yytext); yylval.atrib = 0; return(OPBINARIO); }
"/"								{ yylval.lexema=strdup(yytext); yylval.atrib = 1; return(OPBINARIO); }
"=="							{ yylval.lexema=strdup(yytext); yylval.atrib = 0; return(OPRELACIONAL); }
"!="							{ yylval.lexema=strdup(yytext); yylval.atrib = 1; return(OPRELACIONAL); }
"<="							{ yylval.lexema=strdup(yytext); yylval.atrib = 2; return(OPRELACIONAL); }
">="							{ yylval.lexema=strdup(yytext); yylval.atrib = 3; return(OPRELACIONAL); }
"<"								{ yylval.lexema=strdup(yytext); yylval.atrib = 4; return(OPRELACIONAL); }
">"								{ yylval.lexema=strdup(yytext); yylval.atrib = 5; return(OPRELACIONAL); }
"&&"							{ yylval.lexema=strdup(yytext); return(OPAND); }
"||"							{ yylval.lexema=strdup(yytext); return(OPOR); }
"!"								{ yylval.lexema=strdup(yytext); yylval.atrib = 0; return(OPUNARIO); } 
"#"								{ yylval.lexema=strdup(yytext); yylval.atrib = 1; return(OPUNARIO); }
"?"								{ yylval.lexema=strdup(yytext); yylval.atrib = 2; return(OPUNARIO); }
"--"                            { yylval.lexema=strdup(yytext); yylval.atrib = 0; return(OPBINLISTA);}
"%"                             { yylval.lexema=strdup(yytext); yylval.atrib = 1; return(OPBINLISTA);}
"**"                            { yylval.lexema=strdup(yytext); yylval.atrib = 2; return(OPBINLISTA);}
"verdadero"						{ yylval.atrib = 0; yylval.lexema = strdup(yytext); return(CONSTLOGICA); }
"falso" 						{ yylval.atrib = 1; yylval.lexema = strdup(yytext); return(CONSTLOGICA); }
[a-zA-Z]([a-zA-Z]|[0-9]|_)*		{ yylval.lexema = strdup(yytext); return(IDENT); }
[0-9]+							{ yylval.atrib = 2; yylval.lexema = strdup(yytext); return(CONSTENTERA); }
[0-9]*\.([0-9]+)?				{ yylval.atrib = 1; yylval.lexema = strdup(yytext); return(CONSTREAL); }
"'"[^"'"]"'"					{ yylval.atrib = 0; yylval.lexema = strdup(yytext); return(CONSTCARACTER); }
"\""[^"'"]+"\""					{ yylval.atrib = 3; yylval.lexema = strdup(yytext); return(CONSTCADENA); }

\n								{ lineaActual++; }
\t								{ ; }
[ \t]							{ ; }
\r								{ ; }
.  								{ printf("[Linea %d] *** lexic error : %s\n",yylineno,yytext); }

%%
