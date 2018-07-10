/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "bas.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include "tabela.h"

	int yydebug = 0; /* For Debugging */

	int yylex();
	void yyerror(char *s);

	int contErros, pTipo,limiteInferior, limiteSuperior;
	char *identificadorAtual;
	char *tipoFuncao;
	char *tipoRetornolAtual;

	void instala(char *sym_name ){
		simbolo_t atributo;

		strcpy(atributo.nome,sym_name);
		atributo.tipo = pTipo;
		Instala(sym_name,atributo);
	}

	void setValor(char* X, int valor){
		setValorInt(strdup(X), valor);
	}

	void iniciaBloco(){
		Entrada_Bloco();
	}

	void finalizaBloco(){
		Saida_Bloco();
	}

	void verificaAtribuicao(){
		simbolo_t simbolo;

		simbolo = RecuperaSimbolo(identificadorAtual);

		if(simbolo.tipo == PROCEDURE){
			yyerror(" ");
		}
	}

	int getValor_int(char *X){
		getValorInteiro(X);
	}

	void verificaLimitesInteiros(int num){
		if(num < -32768 || num>32767){
			yyerror(" ");
		}
	}

	void verificaLimites(){
		if(limiteInferior < 0){
			yyerror(" ");
		}

		if(limiteSuperior < 0){
			yyerror(" ");
		}


		if(limiteSuperior<limiteInferior){
			yyerror(" ");
		}


	}


#line 142 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BGN = 258,
    DO = 259,
    IF = 260,
    END = 261,
    ENDIF = 262,
    ENDWHILE = 263,
    EXIT = 264,
    INTEGER = 265,
    PROCEDURE = 266,
    PROGRAM = 267,
    REFERENCE = 268,
    REPEAT = 269,
    READ = 270,
    RETURN = 271,
    THEN = 272,
    TYPE = 273,
    UNTIL = 274,
    VALUE = 275,
    WRITE = 276,
    WHILE = 277,
    ATRIBUICAO = 278,
    ID = 279,
    CONST_CHAR = 280,
    LIMITES = 281,
    DOISPONTOS = 282,
    VIRGULA = 283,
    PONTOVIRGULA = 284,
    APARENTESE = 285,
    FPARENTESE = 286,
    BOOLEAN = 287,
    CHAR = 288,
    FALSO = 289,
    VERDADEIRO = 290,
    NUMERO = 291,
    OR = 292,
    AND = 293,
    NOT = 294,
    NE = 295,
    EQ = 296,
    LE = 297,
    LT = 298,
    GT = 299,
    GE = 300,
    SUM = 301,
    SUB = 302,
    MULT = 303,
    DIV = 304,
    EXP = 305,
    UMINUS = 306,
    ELSE = 307
  };
#endif
/* Tokens.  */
#define BGN 258
#define DO 259
#define IF 260
#define END 261
#define ENDIF 262
#define ENDWHILE 263
#define EXIT 264
#define INTEGER 265
#define PROCEDURE 266
#define PROGRAM 267
#define REFERENCE 268
#define REPEAT 269
#define READ 270
#define RETURN 271
#define THEN 272
#define TYPE 273
#define UNTIL 274
#define VALUE 275
#define WRITE 276
#define WHILE 277
#define ATRIBUICAO 278
#define ID 279
#define CONST_CHAR 280
#define LIMITES 281
#define DOISPONTOS 282
#define VIRGULA 283
#define PONTOVIRGULA 284
#define APARENTESE 285
#define FPARENTESE 286
#define BOOLEAN 287
#define CHAR 288
#define FALSO 289
#define VERDADEIRO 290
#define NUMERO 291
#define OR 292
#define AND 293
#define NOT 294
#define NE 295
#define EQ 296
#define LE 297
#define LT 298
#define GT 299
#define GE 300
#define SUM 301
#define SUB 302
#define MULT 303
#define DIV 304
#define EXP 305
#define UMINUS 306
#define ELSE 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 77 "bas.y" /* yacc.c:355  */

		int iValue;
		char* sIndex;
		char const_char;

#line 292 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 309 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   292

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   153,   153,   156,   159,   159,   162,   163,   166,   167,
     168,   171,   171,   174,   175,   176,   177,   180,   183,   186,
     189,   192,   195,   198,   201,   204,   207,   207,   210,   211,
     214,   217,   218,   221,   222,   223,   224,   227,   230,   231,
     234,   237,   238,   241,   242,   245,   248,   249,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   264,   264,
     270,   273,   276,   277,   279,   282,   285,   288,   291,   294,
     295,   298,   301,   302,   305,   306,   309,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   328,   329,   332,   333,   336,   340,   343,   348,
     349,   352
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BGN", "DO", "IF", "END", "ENDIF",
  "ENDWHILE", "EXIT", "INTEGER", "PROCEDURE", "PROGRAM", "REFERENCE",
  "REPEAT", "READ", "RETURN", "THEN", "TYPE", "UNTIL", "VALUE", "WRITE",
  "WHILE", "ATRIBUICAO", "ID", "CONST_CHAR", "LIMITES", "DOISPONTOS",
  "VIRGULA", "PONTOVIRGULA", "APARENTESE", "FPARENTESE", "BOOLEAN", "CHAR",
  "FALSO", "VERDADEIRO", "NUMERO", "OR", "AND", "NOT", "NE", "EQ", "LE",
  "LT", "GT", "GE", "SUM", "SUB", "MULT", "DIV", "EXP", "UMINUS", "ELSE",
  "$accept", "partida", "program", "bloco", "$@1", "declaracoes",
  "declaracao", "decl_de_var", "$@2", "tipo", "M0", "M1", "M2",
  "def_de_tipo", "nome_do_tipo", "definicao_de_tipo", "limites",
  "tipo_definido", "decl_de_proc", "proc_cab", "$@3", "pro_corpo",
  "emit_return", "lista_de_parametros", "tipo_retornado", "parametro",
  "modo", "nome_do_proc", "lista_de_comandos", "lista_de_ids", "vazio",
  "espec_de_parametros", "comando", "comando_de_atribuicao", "$@4",
  "comando_while", "comando_repeat", "comando_if", "comando_read",
  "comando_write", "comando_return", "comando_exit", "rotulo", "variavel",
  "chamada_ou_indexacao", "chamada_de_proc", "indices", "variavel2",
  "expr", "constante", "int_ou_char", "inteiro", "booleano",
  "identificador", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -137

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-137)))

#define YYTABLE_NINF -77

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,  -137,    22,  -137,  -137,  -137,  -137,  -137,  -137,     5,
    -137,  -137,    13,     9,  -137,    25,    39,  -137,    43,  -137,
    -137,  -137,  -137,  -137,    59,    47,  -137,  -137,   124,  -137,
    -137,  -137,    60,  -137,  -137,  -137,  -137,  -137,    35,     9,
    -137,     9,    35,    35,  -137,    72,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,    79,  -137,   103,  -137,   -15,
      98,    34,    95,     9,  -137,  -137,  -137,    35,  -137,  -137,
    -137,    35,    35,  -137,  -137,   178,  -137,  -137,  -137,  -137,
     107,  -137,   124,  -137,   212,   212,    35,  -137,   138,   124,
     127,    35,  -137,    35,  -137,   125,  -137,     5,     9,   198,
     236,  -137,  -137,  -137,  -137,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    20,   159,   124,  -137,  -137,
      35,   212,   212,   130,  -137,     9,  -137,   134,  -137,  -137,
     124,    35,    35,    50,   133,    65,   242,    29,    70,    93,
      17,   104,   104,  -137,  -137,  -137,   212,   119,  -137,  -137,
    -137,    31,  -137,  -137,    -1,   225,   236,    35,   124,   136,
     141,  -137,  -137,    99,  -137,    10,  -137,   113,   212,    19,
      10,   119,    31,  -137,  -137,  -137,  -137,   142,  -137,  -137,
    -137,  -137,  -137,     9,   124,  -137,    11,  -137
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    45,     0,     2,    45,    19,     1,    45,     7,    45,
      17,     4,    13,     0,   101,    14,    15,     3,     0,     8,
      11,     9,    16,    10,    45,     0,    36,    24,     0,    45,
      21,     6,     0,    45,    25,    29,    30,    26,     0,     0,
      45,     0,     0,     0,    45,    45,    41,    48,    49,    50,
      51,    52,    53,    54,    55,     0,    58,    73,    56,     0,
       0,    72,     0,     0,    45,    45,    97,     0,   100,    99,
      98,     0,     0,    91,    70,     0,    92,    94,    96,    95,
      69,    67,     0,    64,    66,    65,     0,    45,     0,     0,
       0,     0,    71,     0,    45,    12,    43,    45,     0,     0,
      79,    90,    45,    45,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,    57,
       0,    75,    74,     0,    18,     0,    45,    45,    40,    93,
       0,     0,     0,    80,    84,    81,    82,    83,    85,    86,
      87,    88,    89,    45,    45,    42,    59,     0,    20,    44,
      28,     0,    47,    27,    45,    77,    78,     0,     0,     0,
       0,    39,    38,     0,    31,     0,    62,     0,    61,     0,
       0,     0,     0,    46,    13,    14,    15,     0,    45,    60,
      22,    23,    32,     0,     0,    37,     0,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,  -137,    73,  -137,   139,  -137,  -137,  -137,  -118,
     -19,    30,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,    84,  -137,  -137,    26,  -137,  -137,   -77,  -137,
       8,  -137,   -86,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,   -27,   -26,  -137,  -137,  -137,    80,  -137,
    -137,  -136,  -137,    -9
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    17,    28,     7,    18,    19,    32,    20,
       9,   123,     4,    21,    29,   148,   159,    22,    23,    24,
      65,    34,    35,   163,    25,   164,   165,   127,    45,    95,
      10,   153,    46,    47,    90,    48,    49,    50,    51,    52,
      53,    54,    55,    73,    74,    58,    59,    60,    75,    76,
      77,    78,    79,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    56,    57,   119,    30,   115,   166,     1,    11,     5,
      62,   160,     8,    91,    83,    12,    92,    26,   187,    61,
     174,    82,     6,    13,   -33,    86,    88,   179,    87,    14,
      81,   145,    36,    14,    14,   181,   -34,    15,    16,   143,
      87,     8,   175,   176,   161,    97,    98,   177,    87,    87,
     -35,   162,   180,   154,    96,    56,    57,   -69,    37,    14,
      66,   -68,    56,    57,   -76,    67,   113,   114,   117,    68,
      69,    70,    31,    61,    71,   110,   111,   112,   113,   114,
      61,   169,    72,   130,   131,   132,    33,    63,    27,   128,
      56,    57,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    87,   124,    56,    57,    26,    89,   186,    61,   108,
     109,   110,   111,   112,   113,   114,   149,   111,   112,   113,
     114,    61,    84,    85,   157,   158,   -70,   172,    93,    38,
     173,    56,    57,    39,    36,   152,    94,   -76,    40,    41,
      42,   112,   113,   114,   118,    43,    44,    99,    14,    61,
     120,   100,   101,   125,   114,    70,    27,    56,    57,   184,
     147,    27,   124,   144,   151,   178,   116,   170,   171,   183,
     126,   121,    64,   122,   185,    61,   107,   108,   109,   110,
     111,   112,   113,   114,   167,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   102,   103,   104,   182,   105,
     146,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     150,   155,   156,     0,     0,   103,   104,     0,   105,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   129,
       0,     0,     0,     0,     0,   103,   104,   168,   105,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   103,
     104,     0,   105,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   104,     0,   105,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   105,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   109,   110,   111,
     112,   113,   114
};

static const yytype_int16 yycheck[] =
{
       9,    28,    28,    89,    13,    82,     7,    12,     3,     1,
      29,   147,     4,    28,    41,    10,    31,     9,     7,    28,
      10,    40,     0,    18,    11,    44,    45,     8,    29,    24,
      39,   117,    24,    24,    24,   171,    11,    32,    33,    19,
      29,    33,    32,    33,    13,    64,    65,   165,    29,    29,
      11,    20,   170,   130,    63,    82,    82,    23,    11,    24,
      25,    27,    89,    89,    30,    30,    49,    50,    87,    34,
      35,    36,    29,    82,    39,    46,    47,    48,    49,    50,
      89,   158,    47,   102,   103,   104,    27,    27,    97,    98,
     117,   117,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    29,    94,   130,   130,    97,    27,   184,   117,    44,
      45,    46,    47,    48,    49,    50,   125,    47,    48,    49,
      50,   130,    42,    43,   143,   144,    23,    28,    30,     5,
      31,   158,   158,     9,   126,   127,    41,    30,    14,    15,
      16,    48,    49,    50,     6,    21,    22,    67,    24,   158,
      23,    71,    72,    28,    50,    36,   165,   184,   184,   178,
      30,   170,   154,     4,    30,    52,    86,    31,    27,    27,
      97,    91,    33,    93,   183,   184,    43,    44,    45,    46,
      47,    48,    49,    50,   154,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    17,    37,    38,   172,    40,
     120,    42,    43,    44,    45,    46,    47,    48,    49,    50,
     126,   131,   132,    -1,    -1,    37,    38,    -1,    40,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    31,
      -1,    -1,    -1,    -1,    -1,    37,    38,   157,    40,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    37,
      38,    -1,    40,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    38,    -1,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    45,    46,    47,
      48,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    54,    55,    65,    83,     0,    58,    83,    63,
      83,     3,    10,    18,    24,    32,    33,    56,    59,    60,
      62,    66,    70,    71,    72,    77,    83,   106,    57,    67,
     106,    29,    61,    27,    74,    75,    83,    11,     5,     9,
      14,    15,    16,    21,    22,    81,    85,    86,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   106,    63,    27,    58,    73,    25,    30,    34,    35,
      36,    39,    47,    96,    97,   101,   102,   103,   104,   105,
     106,   106,    63,    96,   101,   101,    63,    29,    63,    27,
      87,    28,    31,    30,    41,    82,   106,    63,    63,   101,
     101,   101,    17,    37,    38,    40,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    81,   101,    63,     6,    85,
      23,   101,   101,    64,    83,    28,    56,    80,   106,    31,
      63,    63,    63,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,    19,     4,    85,   101,    30,    68,   106,
      75,    30,    83,    84,    81,   101,   101,    63,    63,    69,
     104,    13,    20,    76,    78,    79,     7,    64,   101,    81,
      31,    27,    28,    31,    10,    32,    33,    62,    52,     8,
      62,   104,    78,    27,    63,   106,    81,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    57,    56,    58,    58,    59,    59,
      59,    61,    60,    62,    62,    62,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    73,    72,    74,    74,
      75,    76,    76,    77,    77,    77,    77,    78,    79,    79,
      80,    81,    81,    82,    82,    83,    84,    84,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    87,    86,
      88,    89,    90,    90,    91,    92,    93,    94,    95,    96,
      96,    97,    98,    98,    99,    99,   100,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   102,   102,   103,   103,   104,   105,
     105,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     0,     5,     4,     1,     1,     1,
       1,     0,     4,     1,     1,     1,     1,     1,     1,     1,
       6,     1,     4,     3,     1,     2,     0,     6,     5,     1,
       1,     1,     3,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     4,     1,     3,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     4,
       7,     6,     6,    10,     2,     2,     2,     2,     1,     1,
       1,     2,     1,     1,     3,     3,     1,     4,     4,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 4:
#line 159 "bas.y" /* yacc.c:1646  */
    {}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 159 "bas.y" /* yacc.c:1646  */
    {}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 171 "bas.y" /* yacc.c:1646  */
    { }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 171 "bas.y" /* yacc.c:1646  */
    { }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 174 "bas.y" /* yacc.c:1646  */
    {pTipo=(yyvsp[0].iValue);}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 175 "bas.y" /* yacc.c:1646  */
    {pTipo=(yyvsp[0].iValue);}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 176 "bas.y" /* yacc.c:1646  */
    {pTipo=(yyvsp[0].iValue);}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 192 "bas.y" /* yacc.c:1646  */
    {(yyval.sIndex) = strdup((yyvsp[0].sIndex));}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 198 "bas.y" /* yacc.c:1646  */
    {limiteInferior = (yyvsp[-2].iValue); limiteSuperior= (yyvsp[0].iValue); verificaLimites();}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 207 "bas.y" /* yacc.c:1646  */
    {pTipo = (yyvsp[0].iValue);}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 234 "bas.y" /* yacc.c:1646  */
    {(yyval.sIndex) = strdup((yyvsp[0].sIndex));}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 264 "bas.y" /* yacc.c:1646  */
    {verificaAtribuicao();}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 264 "bas.y" /* yacc.c:1646  */
    {
																				verificaLimitesInteiros((yyvsp[0].iValue));
																				setValor(strdup((yyvsp[-3].sIndex)),(yyvsp[0].iValue));
																			}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 294 "bas.y" /* yacc.c:1646  */
    {(yyval.sIndex) = strdup((yyvsp[0].sIndex));}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 295 "bas.y" /* yacc.c:1646  */
    {}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 302 "bas.y" /* yacc.c:1646  */
    {}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 309 "bas.y" /* yacc.c:1646  */
    {(yyval.sIndex) = strdup((yyvsp[0].sIndex));}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 320 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[-2].iValue) + (yyvsp[0].iValue);}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 321 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[-2].iValue) - (yyvsp[0].iValue);}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 322 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[-2].iValue) * (yyvsp[0].iValue);}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 323 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[-2].iValue) / (yyvsp[0].iValue);}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 324 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = pow((yyvsp[-2].iValue),(yyvsp[0].iValue));}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 325 "bas.y" /* yacc.c:1646  */
    {}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 326 "bas.y" /* yacc.c:1646  */
    { (yyval.iValue) = getValor_int((yyvsp[0].sIndex));
 			}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 328 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[0].iValue);}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 329 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[-1].iValue);}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 332 "bas.y" /* yacc.c:1646  */
    {}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 336 "bas.y" /* yacc.c:1646  */
    {
							(yyval.iValue) = (yyvsp[0].iValue);
							
						}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 340 "bas.y" /* yacc.c:1646  */
    {}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 343 "bas.y" /* yacc.c:1646  */
    {
						(yyval.iValue) = (yyvsp[0].iValue);
					}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 352 "bas.y" /* yacc.c:1646  */
    {
						(yyval.sIndex) = strdup((yyvsp[0].sIndex));
						identificadorAtual = strdup((yyvsp[0].sIndex));
						instala((yyvsp[0].sIndex));
					}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1750 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 359 "bas.y" /* yacc.c:1906  */

extern int contLinhas;
extern YYSTYPE yylval;

void yyerror(char *s) {
	printf("\n\nFoi encontrado um erro proximo a linha: %d\n", contLinhas);
	exit(1);
}

int main(void) {
	iniciaListaNO();

	printf("%d ",contLinhas);
  	int executou= yyparse();


	if(!executou){//É 0 se executou
		 printf("\nPrograma sintaticamente correto!\n");
	}

	printf("\n\n");
	Imprime_Tabela();

  return 0;
}
