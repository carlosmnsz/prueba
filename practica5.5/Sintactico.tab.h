/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SINTACTICO_TAB_H_INCLUDED
# define YY_YY_SINTACTICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    OPOR = 258,
    OPAND = 259,
    OPRELACIONAL = 260,
    SUMRES = 261,
    OPBINARIO = 262,
    OPUNARIO = 263,
    OPBINLISTA = 264,
    ARROBA = 265,
    MASMAS = 266,
    ASIGNACION = 267,
    CORIZQ = 268,
    CORDER = 269,
    TIPOBASICO = 270,
    CONSTENTERA = 271,
    CONSTLOGICA = 272,
    CONSTREAL = 273,
    CONSTCARACTER = 274,
    CONSTCADENA = 275,
    COMA = 276,
    PARDER = 277,
    PARIZQ = 278,
    PUNTOYCOMA = 279,
    INICIOBLOQUE = 280,
    FINBLOQUE = 281,
    VAR = 282,
    SI = 283,
    SINO = 284,
    MIENTRAS = 285,
    LEER = 286,
    ESCRIBIR = 287,
    HASTA = 288,
    PRINCIPAL = 289,
    PROCEDIMIENTO = 290,
    DOSP = 291,
    INICIO = 292,
    FIN = 293,
    ENTONCES = 294,
    PARA = 295,
    HACER = 296,
    AVANRETR = 297,
    DOLAR = 298,
    LISTA = 299,
    IDENT = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTACTICO_TAB_H_INCLUDED  */
