/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "Sintactico.y"



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




#line 97 "Sintactico.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   251

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    79,    81,    81,    81,    83,    83,    83,
      85,    86,    88,    89,    91,    92,    93,    95,   103,   103,
     105,   105,   105,   107,   107,   107,   108,   110,   111,   112,
     114,   116,   116,   116,   118,   118,   119,   120,   120,   120,
     121,   121,   122,   122,   123,   123,   124,   124,   125,   126,
     127,   129,   135,   138,   139,   138,   143,   143,   147,   147,
     149,   149,   154,   162,   151,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     187,   188,   190,   191,   193,   193,   195,   196,   197,   198,
     200,   200,   201,   203,   204,   205,   206,   207,   209,   211,
     213,   215,   217,   218,   220,   221,   223,   224,   226,   227,
     228
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OPOR", "OPAND", "OPRELACIONAL",
  "SUMRES", "OPBINARIO", "OPUNARIO", "OPBINLISTA", "ARROBA", "MASMAS",
  "ASIGNACION", "CORIZQ", "CORDER", "TIPOBASICO", "CONSTENTERA",
  "CONSTLOGICA", "CONSTREAL", "CONSTCARACTER", "CONSTCADENA", "COMA",
  "PARDER", "PARIZQ", "PUNTOYCOMA", "INICIOBLOQUE", "FINBLOQUE", "VAR",
  "SI", "SINO", "MIENTRAS", "LEER", "ESCRIBIR", "HASTA", "PRINCIPAL",
  "PROCEDIMIENTO", "DOSP", "INICIO", "FIN", "ENTONCES", "PARA", "HACER",
  "AVANRETR", "DOLAR", "LISTA", "IDENT", "$accept", "programa", "$@1",
  "bloque", "$@2", "$@3", "declar_variables_locales", "$@4",
  "variables_locales", "cuerpo_declar_variables", "lista_variables",
  "variable", "declar_subprogs", "declar_subprog", "$@5", "$@6",
  "cabecera_subprograma", "$@7", "$@8", "lista_parametros", "parametro",
  "sentencias", "$@9", "sentencia", "$@10", "$@11", "$@12", "$@13", "$@14",
  "$@15", "$@16", "asignacion", "si", "@17", "$@18", "mientras", "$@19",
  "entrada", "$@20", "salida", "$@21", "for", "$@22", "$@23", "expresion",
  "lista_expresiones", "lista_expresiones_cad", "exp_cad", "constante",
  "llamada_funcion", "$@24", "agregado", "agregado_enteros",
  "agregado_reales", "agregado_caracteres", "agregado_booleanos",
  "agregado_cadenas", "tipo", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF (-144)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-111)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -144,     8,   -22,  -144,   -12,  -144,  -144,     0,  -144,  -144,
       6,    17,    11,  -144,    39,     2,  -144,    22,    42,  -144,
      50,  -144,  -144,  -144,  -144,    62,    34,    48,   180,    44,
    -144,  -144,    22,    22,  -144,    22,    64,    -3,    19,   -12,
      67,    77,    86,    92,    85,  -144,  -144,   102,    93,  -144,
    -144,   105,   109,    65,   110,  -144,  -144,   124,   128,   130,
    -144,  -144,  -144,  -144,  -144,    22,  -144,  -144,   131,    95,
    -144,   142,    65,  -144,    65,    65,   218,  -144,  -144,  -144,
    -144,    65,  -144,   132,  -144,  -144,    65,  -144,    65,    22,
      24,   119,    22,   125,  -144,   197,   145,    -4,    -4,  -144,
    -144,  -144,  -144,  -144,   154,   148,   150,   151,   153,   162,
     155,    65,    65,    65,    65,    65,    65,    65,  -144,   175,
    -144,   183,   152,  -144,   223,   167,   173,   163,   159,   174,
      27,   185,    65,   189,  -144,   182,   181,   195,   198,   196,
    -144,   139,   106,   113,    70,    -4,   207,   208,   192,  -144,
    -144,  -144,    24,    65,     9,  -144,   200,    22,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,    65,   180,   180,  -144,
      99,  -144,  -144,   215,    22,  -144,  -144,   193,   216,    65,
    -144,  -144,   212,  -144,    87,  -144,   184,   180,  -144,  -144,
     180,  -144,   204,   219,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     4,     3,     9,     7,    19,
       0,     5,    13,   109,     0,     0,    11,     0,    31,    18,
       0,   108,     8,    10,    17,     0,     0,     0,    34,     0,
      21,    12,     0,     0,     6,     0,    17,     0,    31,     0,
       0,     0,     0,     0,     0,    36,    48,    23,     0,    15,
      14,     0,    90,     0,     0,    32,    35,     0,     0,     0,
      41,    58,    43,    60,    45,     0,    47,    26,     0,    31,
      50,     0,     0,    79,     0,     0,     0,    86,    87,    88,
      89,     0,    76,     0,    77,    49,     0,    38,     0,     0,
       0,     0,     0,     0,    92,    81,     0,    67,    66,    99,
     105,   101,   103,   107,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
      39,     0,     0,    85,    84,     0,    83,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
      65,    69,    72,    70,    71,    68,    73,    74,     0,    56,
      59,    61,     0,     0,     0,    24,     0,     0,    22,    80,
      91,    98,   100,   102,   104,   106,     0,    34,    34,    82,
       0,   110,    30,     0,     0,    27,    75,    52,     0,     0,
      25,    28,     0,    57,     0,    54,     0,    34,    62,    55,
      34,    63,     0,     0,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,   205,  -144,  -144,  -144,  -144,  -144,   230,
     -13,   -17,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -143,
    -144,   -36,  -144,   -69,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,   -52,   114,    96,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,    97
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,    18,     9,    10,    15,    16,
     128,    82,    11,    19,    20,    48,    30,    68,   173,   129,
     130,    27,    28,    38,    39,    40,   120,    41,    42,    43,
      44,    45,    58,   182,   187,    60,   168,    62,    89,    64,
      90,    66,   190,   192,    95,    96,   125,   126,    84,    46,
      72,   104,   105,   106,   107,   108,   109,    17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    83,    55,    12,    25,   116,   117,    12,     3,    53,
     171,    37,     4,     5,   175,    26,    26,    13,    51,    49,
      50,    13,    97,    98,    13,    73,    22,     8,   156,   110,
      74,   181,    75,    93,   119,    32,   121,    76,   124,    54,
      77,    78,    79,    80,   123,   -33,    14,    81,    91,   -29,
      14,   157,   -20,    14,    21,    33,  -110,   -33,   -16,   141,
     142,   143,   144,   145,   146,   147,    73,    24,   -33,    24,
     -16,    74,    26,    75,    34,    26,   122,   115,    76,   116,
     117,    77,    78,    79,    80,    29,    31,    52,    81,    47,
     111,   112,   113,   114,   115,    57,   116,   117,   177,   178,
     124,   170,   111,   112,   113,   114,   115,    59,   116,   117,
      24,   113,   114,   115,   176,   116,   117,    61,   189,   114,
     115,   191,   116,   117,    63,    65,    67,   184,   186,    70,
      69,    71,   179,   -33,    85,   111,   112,   113,   114,   115,
      26,   116,   117,   112,   113,   114,   115,    86,   116,   117,
      37,    37,    87,    88,    92,   127,   118,    26,   111,   112,
     113,   114,   115,   131,   116,   117,    94,   133,   134,   135,
      37,   136,   137,    37,   138,   153,   150,   140,   111,   112,
     113,   114,   115,   139,   116,   117,   111,   112,   113,   114,
     115,   151,   116,   117,   152,   154,   155,   148,   161,   162,
     111,   112,   113,   114,   115,   149,   116,   117,   -37,   158,
     -40,   -42,   -44,   160,   163,   164,   165,   117,   132,   166,
     -46,   188,   -53,    35,   174,    36,   111,   112,   113,   114,
     115,   167,   116,   117,    99,   100,   101,   102,   103,   180,
     183,   185,   193,   194,    56,    23,   159,     0,   169,     0,
       0,   172
};

static const yytype_int16 yycheck[] =
{
      17,    53,    38,     1,    17,     9,    10,     1,     0,    12,
       1,    28,    34,    25,   157,    32,    33,    15,    35,    32,
      33,    15,    74,    75,    15,     1,    24,    27,     1,    81,
       6,   174,     8,    69,    86,     1,    88,    13,    90,    42,
      16,    17,    18,    19,    20,    26,    44,    23,    65,    22,
      44,    24,    35,    44,    15,    21,    45,    38,    24,   111,
     112,   113,   114,   115,   116,   117,     1,    45,    26,    45,
      36,     6,    89,     8,    26,    92,    89,     7,    13,     9,
      10,    16,    17,    18,    19,    35,    24,    23,    23,    45,
       3,     4,     5,     6,     7,    28,     9,    10,   167,   168,
     152,   153,     3,     4,     5,     6,     7,    30,     9,    10,
      45,     5,     6,     7,   166,     9,    10,    31,   187,     6,
       7,   190,     9,    10,    32,    40,    24,   179,    41,    24,
      37,    22,    33,    38,    24,     3,     4,     5,     6,     7,
     157,     9,    10,     4,     5,     6,     7,    23,     9,    10,
     167,   168,    24,    23,    23,    36,    24,   174,     3,     4,
       5,     6,     7,    38,     9,    10,    24,    22,    14,    21,
     187,    21,    21,   190,    21,    12,    24,    22,     3,     4,
       5,     6,     7,    21,     9,    10,     3,     4,     5,     6,
       7,    24,     9,    10,    21,    36,    22,    22,    16,    18,
       3,     4,     5,     6,     7,    22,     9,    10,    28,    24,
      30,    31,    32,    24,    19,    17,    20,    10,    21,    11,
      40,    37,    29,    43,    24,    45,     3,     4,     5,     6,
       7,    39,     9,    10,    16,    17,    18,    19,    20,    24,
      24,    29,    38,    24,    39,    15,   132,    -1,   152,    -1,
      -1,   154
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    48,     0,    34,    25,    49,    50,    27,    52,
      53,    58,     1,    15,    44,    54,    55,   103,    51,    59,
      60,    15,    24,    55,    45,    56,    57,    67,    68,    35,
      62,    24,     1,    21,    26,    43,    45,    57,    69,    70,
      71,    73,    74,    75,    76,    77,    95,    45,    61,    56,
      56,    57,    23,    12,    42,    67,    49,    28,    78,    30,
      81,    31,    83,    32,    85,    40,    87,    24,    63,    37,
      24,    22,    96,     1,     6,     8,    13,    16,    17,    18,
      19,    23,    57,    90,    94,    24,    23,    24,    23,    84,
      86,    57,    23,    67,    24,    90,    91,    90,    90,    16,
      17,    18,    19,    20,    97,    98,    99,   100,   101,   102,
      90,     3,     4,     5,     6,     7,     9,    10,    24,    90,
      72,    90,    56,    20,    90,    92,    93,    36,    56,    65,
      66,    38,    21,    22,    14,    21,    21,    21,    21,    21,
      22,    90,    90,    90,    90,    90,    90,    90,    22,    22,
      24,    24,    21,    12,    36,    22,     1,    24,    24,    91,
      24,    16,    18,    19,    17,    20,    11,    39,    82,    92,
      90,     1,   103,    64,    24,    65,    90,    69,    69,    33,
      24,    65,    79,    24,    90,    29,    41,    80,    37,    69,
      88,    69,    89,    38,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    48,    47,    50,    51,    49,    53,    52,    52,
      54,    54,    55,    55,    56,    56,    56,    57,    58,    58,
      60,    61,    59,    63,    64,    62,    62,    65,    65,    65,
      66,    68,    67,    67,    70,    69,    69,    71,    72,    69,
      73,    69,    74,    69,    75,    69,    76,    69,    69,    69,
      69,    77,    78,    79,    80,    78,    82,    81,    84,    83,
      86,    85,    88,    89,    87,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      91,    91,    92,    92,    93,    93,    94,    94,    94,    94,
      96,    95,    95,    97,    97,    97,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   103,
     103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     0,     7,     0,     4,     0,
       2,     1,     3,     1,     3,     3,     1,     1,     2,     0,
       0,     0,     7,     0,     0,     8,     3,     3,     4,     1,
       3,     0,     3,     0,     0,     2,     1,     0,     0,     4,
       0,     2,     0,     2,     0,     2,     0,     2,     1,     3,
       3,     4,     6,     0,     0,    10,     0,     7,     0,     4,
       0,     4,     0,     0,    14,     3,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     5,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     4,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     2,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 79 "Sintactico.y"
           {abrirFicherosGCI();}
#line 1528 "Sintactico.tab.c"
    break;

  case 3:
#line 79 "Sintactico.y"
                                                  {cerrarFicherosGCI();}
#line 1534 "Sintactico.tab.c"
    break;

  case 4:
#line 81 "Sintactico.y"
                      { TS_InsertaMarca(); tabulacion++;}
#line 1540 "Sintactico.tab.c"
    break;

  case 5:
#line 81 "Sintactico.y"
                                                                                                   {if(cont_bloque==0){ fprintf(principal, "int main(){\n"); }}
#line 1546 "Sintactico.tab.c"
    break;

  case 6:
#line 81 "Sintactico.y"
                                                                                                                                                                                     { if(cont_bloque==0){fprintf(principal, "\n}\n"); } tabulacion--; TS_VaciarEntradas();}
#line 1552 "Sintactico.tab.c"
    break;

  case 7:
#line 83 "Sintactico.y"
                               { declarVar = 1; }
#line 1558 "Sintactico.tab.c"
    break;

  case 8:
#line 83 "Sintactico.y"
                                                                               { declarVar = 0; }
#line 1564 "Sintactico.tab.c"
    break;

  case 12:
#line 88 "Sintactico.y"
                                                          { listaGlobal=0; tipoGlobal=DESC; }
#line 1570 "Sintactico.tab.c"
    break;

  case 17:
#line 95 "Sintactico.y"
                 { 
		if(declarVar == 1) { TS_InsertaIdent(yyvsp[0]); generaDecVar(yyvsp[0]);}
		else if(declarPar == 1) { numParam++; TS_InsertaParamFormal(yyvsp[0]);}
		else if(leer==1){generaEntSal(1,yyvsp[0]);}
		else { TS_GetIdent(yyvsp[0], &yyval); }
		listaActual=yyvsp[0].lexema;
	}
#line 1582 "Sintactico.tab.c"
    break;

  case 20:
#line 105 "Sintactico.y"
                 {tabular();}
#line 1588 "Sintactico.tab.c"
    break;

  case 21:
#line 105 "Sintactico.y"
                                                   { subProg = 1; }
#line 1594 "Sintactico.tab.c"
    break;

  case 22:
#line 105 "Sintactico.y"
                                                                                                    { subProg = 0; fprintf(principal, "}\n");}
#line 1600 "Sintactico.tab.c"
    break;

  case 23:
#line 107 "Sintactico.y"
                                           { declarPar = 1; TS_InsertaSubprog(yyvsp[0]); fprintf(principal, "void %s(", yyvsp[0].lexema);}
#line 1606 "Sintactico.tab.c"
    break;

  case 24:
#line 107 "Sintactico.y"
                                                                                                                                                               { TS_ActualizaNparam(yyvsp[-5]); numParam = 0; declarPar = 0; GCI_DeclarPar(); fprintf(principal, "){\n");}
#line 1612 "Sintactico.tab.c"
    break;

  case 26:
#line 108 "Sintactico.y"
                                                                                 { TS_InsertaSubprog(yyvsp[-1]); fprintf(principal, "void %s(){\n", yyvsp[-1].lexema);}
#line 1618 "Sintactico.tab.c"
    break;

  case 30:
#line 114 "Sintactico.y"
                                      {actualizarTipo(yyvsp[-2]); listaGlobal=0;}
#line 1624 "Sintactico.tab.c"
    break;

  case 31:
#line 116 "Sintactico.y"
             { declarVar = 2; }
#line 1630 "Sintactico.tab.c"
    break;

  case 34:
#line 118 "Sintactico.y"
            { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } cont_bloque++;}
#line 1636 "Sintactico.tab.c"
    break;

  case 35:
#line 118 "Sintactico.y"
                                                                                                       {cont_bloque--;}
#line 1642 "Sintactico.tab.c"
    break;

  case 36:
#line 119 "Sintactico.y"
                     {fputs("\n", principal);}
#line 1648 "Sintactico.tab.c"
    break;

  case 37:
#line 120 "Sintactico.y"
          { decIf=1; insertaDesc(1); }
#line 1654 "Sintactico.tab.c"
    break;

  case 38:
#line 120 "Sintactico.y"
                                                     { decIf=0; eliminaDesc(); }
#line 1660 "Sintactico.tab.c"
    break;

  case 39:
#line 120 "Sintactico.y"
                                                                                {fputs("\n", principal);}
#line 1666 "Sintactico.tab.c"
    break;

  case 40:
#line 121 "Sintactico.y"
          { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } insertaDesc(2); insertaEtiqEntrada(); fputs("{\n", principal);}
#line 1672 "Sintactico.tab.c"
    break;

  case 41:
#line 121 "Sintactico.y"
                                                                                                                                                       {fputs("\n", principal);}
#line 1678 "Sintactico.tab.c"
    break;

  case 42:
#line 122 "Sintactico.y"
          { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } }
#line 1684 "Sintactico.tab.c"
    break;

  case 43:
#line 122 "Sintactico.y"
                                                                                        {fputs("\n", principal);}
#line 1690 "Sintactico.tab.c"
    break;

  case 44:
#line 123 "Sintactico.y"
          { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } }
#line 1696 "Sintactico.tab.c"
    break;

  case 45:
#line 123 "Sintactico.y"
                                                                                       {fputs("\n", principal);}
#line 1702 "Sintactico.tab.c"
    break;

  case 46:
#line 124 "Sintactico.y"
          { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } }
#line 1708 "Sintactico.tab.c"
    break;

  case 47:
#line 124 "Sintactico.y"
                                                                                    {fputs("\n", principal);}
#line 1714 "Sintactico.tab.c"
    break;

  case 48:
#line 125 "Sintactico.y"
                          {yyval.tipo = yyvsp[0].tipo; yyval.numDim = yyvsp[0].numDim;  funcionActual = -1; fputs("\n", principal);}
#line 1720 "Sintactico.tab.c"
    break;

  case 49:
#line 126 "Sintactico.y"
                                       {if(yyvsp[-2].numDim==0){printf("ERROR [Linea %d]: %s NO ES UNA LISTA\n", lineaActual, yyvsp[-2].lexema);}}
#line 1726 "Sintactico.tab.c"
    break;

  case 50:
#line 127 "Sintactico.y"
                                    {if(yyvsp[-1].numDim==0){printf("ERROR [Linea %d]: %s NO ES UNA LISTA\n", lineaActual, yyvsp[-1].lexema);}}
#line 1732 "Sintactico.tab.c"
    break;

  case 51:
#line 130 "Sintactico.y"
                { if(yyvsp[-3].tipo!=yyvsp[-1].tipo) {  printf("Error asign linea %d: Los tipos de la parte izquierda %d y derecha %d no coinciden.\n",lineaActual, yyvsp[-3].tipo, yyvsp[-1].tipo); }
		else if(!igualTam(yyvsp[-3],yyvsp[-1]))  { printf("Error asign linea %d: La parte izquierda y la parte derecha deben tener el mismo tamanyo.\n",lineaActual); } 
		else { if(decIf==1){ insertaCond(1); fputs("{\n", principal); decIf++; } 
				if(yyvsp[-3].numDim==0){genera(4,yyvsp[-3],yyvsp[-2],yyvsp[-1],yyvsp[0]);} else{} } }
#line 1741 "Sintactico.tab.c"
    break;

  case 52:
#line 136 "Sintactico.y"
        { if(yyvsp[-3].tipo != BOOLEANO) { printf("Error si linea %d: La expresion no es de tipo logico.\n", lineaActual);}
		yyval.lexema=yyvsp[-3].lexema; fputs("}\n", principal); insertaEtiqElse(); fputs("{}\n", principal); }
#line 1748 "Sintactico.tab.c"
    break;

  case 53:
#line 138 "Sintactico.y"
                                                        { if(yyvsp[-3].tipo != BOOLEANO) { printf("Error si linea %d: La expresion no es de tipo logico.\n", lineaActual);} yyval.lexema=yyvsp[-3].lexema;}
#line 1754 "Sintactico.tab.c"
    break;

  case 54:
#line 139 "Sintactico.y"
               {decElse=1; fputs("}\n", principal); insertaEtiqElse(); fputs("{\n", principal); decElse=0;}
#line 1760 "Sintactico.tab.c"
    break;

  case 55:
#line 140 "Sintactico.y"
                    {fputs("}\n", principal); insertaEtiqSalida(); fputs("{}\n", principal); }
#line 1766 "Sintactico.tab.c"
    break;

  case 56:
#line 143 "Sintactico.y"
                                            {insertaCond(2);}
#line 1772 "Sintactico.tab.c"
    break;

  case 57:
#line 144 "Sintactico.y"
        { if(yyvsp[-4].tipo != BOOLEANO) { printf("Error mientras linea %d: La expresion no es de tipo logico.\n", lineaActual);}
		yyval.lexema=yyvsp[-4].lexema; fputs("}\n", principal); insertaGotoEntrada(); insertaEtiqSalida(); fputs("{}\n", principal); }
#line 1779 "Sintactico.tab.c"
    break;

  case 58:
#line 147 "Sintactico.y"
               {leer=1;}
#line 1785 "Sintactico.tab.c"
    break;

  case 59:
#line 147 "Sintactico.y"
                                                    {leer=0;}
#line 1791 "Sintactico.tab.c"
    break;

  case 60:
#line 149 "Sintactico.y"
                  {escribir=1;}
#line 1797 "Sintactico.tab.c"
    break;

  case 61:
#line 149 "Sintactico.y"
                                                                 {escribir=0;}
#line 1803 "Sintactico.tab.c"
    break;

  case 62:
#line 154 "Sintactico.y"
                { if(yyvsp[-4].tipo != yyvsp[-2].tipo) { printf("ERROR [Linea %d]: LOS TIPOS DE LA ASIGNACION Y CONDICIÓN SON DISTINTOS.\n", lineaActual);}
			insertaDesc(2); 
			fprintf(principal, "%s=%s;\n", yyvsp[-7].lexema, yyvsp[-4].lexema);
			insertaEtiqEntrada(); fputs("{\n", principal);
			fprintf(principal, "int temp%d = %s == %s;\n", temp, yyvsp[-7].lexema, yyvsp[-2].lexema); temp++;
			insertaCond(2);
		}
#line 1815 "Sintactico.tab.c"
    break;

  case 63:
#line 162 "Sintactico.y"
                {	fprintf(principal, "%s++;\n", yyvsp[-9].lexema);
			fputs("}\n", principal);
			insertaGotoEntrada(); 
			insertaEtiqSalida(); 
			fputs("{}\n", principal);
			}
#line 1826 "Sintactico.tab.c"
    break;

  case 65:
#line 171 "Sintactico.y"
                                    { yyval.tipo = yyvsp[-1].tipo; yyval.numDim = yyvsp[-1].numDim;  yyval.lexema=yyvsp[-1].lexema;}
#line 1832 "Sintactico.tab.c"
    break;

  case 66:
#line 172 "Sintactico.y"
                             {TS_OpUnario(yyvsp[-1], yyvsp[0], &yyval); generarUnario(&yyval, yyvsp[-1], yyvsp[0]); }
#line 1838 "Sintactico.tab.c"
    break;

  case 67:
#line 173 "Sintactico.y"
                                          {TS_OpSumResUnario(yyvsp[-1], yyvsp[0], &yyval); generarUnario(&yyval, yyvsp[-1], yyvsp[0]); }
#line 1844 "Sintactico.tab.c"
    break;

  case 68:
#line 174 "Sintactico.y"
                                        {TS_OpMulDiv(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); generarBinario(&yyval,yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1850 "Sintactico.tab.c"
    break;

  case 69:
#line 175 "Sintactico.y"
                                   {TS_OpOrXor(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); generarBinario(&yyval,yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1856 "Sintactico.tab.c"
    break;

  case 70:
#line 176 "Sintactico.y"
                                           {TS_OpRel(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); generarBinario(&yyval,yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1862 "Sintactico.tab.c"
    break;

  case 71:
#line 177 "Sintactico.y"
                                     { TS_OpSumRes(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); generarBinario(&yyval,yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1868 "Sintactico.tab.c"
    break;

  case 72:
#line 178 "Sintactico.y"
                                    {TS_OpAnd(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); generarBinario(&yyval,yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1874 "Sintactico.tab.c"
    break;

  case 73:
#line 179 "Sintactico.y"
                                         {TS_OpBinListas(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); generarBinario(&yyval,yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1880 "Sintactico.tab.c"
    break;

  case 74:
#line 180 "Sintactico.y"
                                     {TS_OpBinArroba(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); generarBinario(&yyval,yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1886 "Sintactico.tab.c"
    break;

  case 75:
#line 181 "Sintactico.y"
                                                      {TS_OpTerciario(yyvsp[-4], yyvsp[-2], yyvsp[0], &yyval); generarTerciario(&yyval, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1892 "Sintactico.tab.c"
    break;

  case 76:
#line 182 "Sintactico.y"
                   { declarVar = 0; yyval.lexema=yyvsp[0].lexema;}
#line 1898 "Sintactico.tab.c"
    break;

  case 77:
#line 183 "Sintactico.y"
                    { yyval.tipo = yyvsp[0].tipo; yyval.numDim = yyvsp[0].numDim; yyval.lexema=yyvsp[0].lexema;}
#line 1904 "Sintactico.tab.c"
    break;

  case 78:
#line 184 "Sintactico.y"
                                 {yyval.tipo=yyvsp[-1].tipo; yyval.numDim=1; }
#line 1910 "Sintactico.tab.c"
    break;

  case 80:
#line 187 "Sintactico.y"
                                                     { numParam++; TS_CompruebaParametro(yyvsp[-2], numParam); strcat(yyval.lexema, ", "); strcat(yyvsp[-2].lexema, "&"); strcat(yyval.lexema, yyvsp[0].lexema);}
#line 1916 "Sintactico.tab.c"
    break;

  case 81:
#line 188 "Sintactico.y"
                     { numParam = 1; TS_CompruebaParametro(yyvsp[0], numParam);  }
#line 1922 "Sintactico.tab.c"
    break;

  case 84:
#line 193 "Sintactico.y"
                    {generaEntSal(2,yyvsp[0]);}
#line 1928 "Sintactico.tab.c"
    break;

  case 85:
#line 193 "Sintactico.y"
                                                        { yyvsp[0].tipo=STRING; generaEntSal(2,yyvsp[0]);}
#line 1934 "Sintactico.tab.c"
    break;

  case 86:
#line 195 "Sintactico.y"
                        { yyval.tipo = ENTERO; yyval.numDim = 0;  }
#line 1940 "Sintactico.tab.c"
    break;

  case 87:
#line 196 "Sintactico.y"
                      { yyval.tipo = BOOLEANO; yyval.numDim = 0;  }
#line 1946 "Sintactico.tab.c"
    break;

  case 88:
#line 197 "Sintactico.y"
                    { yyval.tipo = REAL; yyval.numDim = 0;  }
#line 1952 "Sintactico.tab.c"
    break;

  case 89:
#line 198 "Sintactico.y"
                        { yyval.tipo = CARACTER; yyval.numDim = 0; }
#line 1958 "Sintactico.tab.c"
    break;

  case 90:
#line 200 "Sintactico.y"
                               {funcionActual=TS_BuscarFuncion(yyvsp[-1]); }
#line 1964 "Sintactico.tab.c"
    break;

  case 91:
#line 200 "Sintactico.y"
                                                                                                          { TS_LlamadaFuncion(yyvsp[-5], &yyval); fprintf(principal, "%s(&%s);\n", yyvsp[-5].lexema, yyvsp[-2].lexema);}
#line 1970 "Sintactico.tab.c"
    break;

  case 92:
#line 201 "Sintactico.y"
                                         { TS_LlamadaFuncion(yyvsp[-3], &yyval); fprintf(principal, "%s();\n", yyvsp[-3].lexema);}
#line 1976 "Sintactico.tab.c"
    break;

  case 93:
#line 203 "Sintactico.y"
                            {yyval.tipo=ENTERO;}
#line 1982 "Sintactico.tab.c"
    break;

  case 94:
#line 204 "Sintactico.y"
                                          {yyval.tipo=REAL; }
#line 1988 "Sintactico.tab.c"
    break;

  case 95:
#line 205 "Sintactico.y"
                                              {yyval.tipo=CARACTER;}
#line 1994 "Sintactico.tab.c"
    break;

  case 96:
#line 206 "Sintactico.y"
                                             {yyval.tipo=BOOLEANO;}
#line 2000 "Sintactico.tab.c"
    break;

  case 97:
#line 207 "Sintactico.y"
                                           {yyval.tipo=CONSTCADENA;}
#line 2006 "Sintactico.tab.c"
    break;

  case 98:
#line 209 "Sintactico.y"
                                                          {strcat(yyval.lexema, yyvsp[-1].lexema); strcat(yyval.lexema, yyvsp[0].lexema);
														fprintf(principal, "insertItem(%s, %s);\n", listaActual, yyvsp[0].lexema);}
#line 2013 "Sintactico.tab.c"
    break;

  case 99:
#line 211 "Sintactico.y"
                                                      {fprintf(principal, "insertItem(%s, %s);\n", listaActual, yyvsp[0].lexema);}
#line 2019 "Sintactico.tab.c"
    break;

  case 100:
#line 213 "Sintactico.y"
                                                       {strcat(yyval.lexema, yyvsp[-1].lexema); strcat(yyval.lexema, yyvsp[0].lexema); 
													 fprintf(principal, "insertFirstFloat(%s);\n", yyvsp[0].lexema);}
#line 2026 "Sintactico.tab.c"
    break;

  case 101:
#line 215 "Sintactico.y"
                                                    {fprintf(principal, "insertFirstFloat(%s);\n", yyvsp[0].lexema);}
#line 2032 "Sintactico.tab.c"
    break;

  case 102:
#line 217 "Sintactico.y"
                                                               {strcat(yyval.lexema, yyvsp[-1].lexema); strcat(yyval.lexema, yyvsp[0].lexema);}
#line 2038 "Sintactico.tab.c"
    break;

  case 104:
#line 220 "Sintactico.y"
                                                            {strcat(yyval.lexema, yyvsp[-1].lexema); strcat(yyval.lexema, yyvsp[0].lexema);}
#line 2044 "Sintactico.tab.c"
    break;

  case 106:
#line 223 "Sintactico.y"
                                                          {strcat(yyval.lexema, yyvsp[-1].lexema); strcat(yyval.lexema, yyvsp[0].lexema);}
#line 2050 "Sintactico.tab.c"
    break;

  case 108:
#line 226 "Sintactico.y"
                        {listaGlobal=1; asignaTipoGlobal(yyvsp[0]); }
#line 2056 "Sintactico.tab.c"
    break;

  case 109:
#line 227 "Sintactico.y"
                             {asignaTipoGlobal(yyvsp[0]);}
#line 2062 "Sintactico.tab.c"
    break;


#line 2066 "Sintactico.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 230 "Sintactico.y"



/** Aqui incluimos el fichero generado por el ’lex’
*** que implementa la función ’yylex’
**/

#include "lex.yy.c"

