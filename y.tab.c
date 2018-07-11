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

	int ehProcedimento,ehChamadaProcedimento,contErros, pTipo,limiteInferior, limiteSuperior,decVar=0;
	int contParametros = 0;
	char *procedimentoAtual,*identificadorAtual;
	char *tipoFuncao;
	char *tipoRetornolAtual;

	void instala(char *sym_name ){
		simbolo_t atributo;

		strcpy(atributo.nome,sym_name);
		atributo.tipo = pTipo;
		Instala(sym_name,atributo);
	}

	void verifica(char *sym_name){ 
		int r; 
		r = Recupera_Entrada(sym_name); 
		if((r==0) && (decVar == 1)){ 
			printf("\nVariável utilizada e não declarada anteriormente!"); 
			yyerror(sym_name); 
		} 
		else if(decVar == 0) 
			instala(sym_name); 
    } 

	void verificaChamadaProcedimento(){
		
		simbolo_t simbolo;
		simbolo_t procedimento;

		if(ehChamadaProcedimento){
			simbolo = RecuperaSimbolo(identificadorAtual);
			procedimento = RecuperaSimbolo(procedimentoAtual);
			if(simbolo.tipo != procedimento.procedimento.tipo_parametro[contParametros]){
				printf("\n\nErro semântico.Tipo de parametro errado.\n\n");
				yyerror(" ");
			}
		}
		

		if(ehChamadaProcedimento){
			contParametros = contParametros + 1;
		}
	}
	
	void verificaQuantidadeParam(){
		simbolo_t simbolo;

		simbolo = RecuperaSimbolo(procedimentoAtual);
		
		if(simbolo.procedimento.numero_parametros != contParametros){
			printf("\n\nErro semântico.Quantidade de parametros errada.\n\n");
			yyerror(" ");
		}
	}

	void adicionaParametro(int modo, int tipo, char* identificador){
		if(ehProcedimento){
			setProcedimento(procedimentoAtual);
			adicionar_parametro(procedimentoAtual,modo, tipo, identificador);
		}

	}

	void setValor(char* X, int valor){
		setValorInt(strdup(X), valor);
	}

	void verificaAtribuicao(){
		simbolo_t simbolo;

		simbolo = RecuperaSimbolo(identificadorAtual);

		if(simbolo.tipo == PROCEDURE){
			printf("\n\nImpossivel realizar atribuicao a procedimento.\n\n");
			yyerror(" ");
		}
	}

	int getValor_int(char *X){
		getValorInteiro(X);
	}

	void verificaLimitesInteiros(int num){
		if(num < -32768 || num>32767){
			printf("\n\nInteiro fora da faixa permitida.\n\n");
			yyerror(" ");
		}
	}

	void verificaLimites(){
		if(limiteInferior < 0){
			printf("\n\nErro no limite inferior.\n\n");
			yyerror(" ");
		}

		if(limiteSuperior < 0){
			printf("\n\nErro no limite superior.\n\n");
			yyerror(" ");
		}


		if(limiteSuperior<limiteInferior){
			printf("\n\nErro nos limites. Limite superior deve ser maior ou igual ao inferior \n\n");
			yyerror(" ");
		}

	}


#line 189 "y.tab.c" /* yacc.c:339  */

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
#line 124 "bas.y" /* yacc.c:355  */

		int iValue;
		char* sIndex;
		char const_char;

#line 339 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 356 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   335

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

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
       0,   201,   201,   204,   204,   207,   207,   210,   211,   214,
     215,   216,   219,   219,   222,   223,   224,   225,   228,   231,
     234,   237,   240,   243,   246,   249,   252,   255,   255,   255,
     261,   262,   265,   268,   269,   272,   273,   274,   275,   278,
     281,   282,   285,   288,   289,   292,   293,   296,   299,   300,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     315,   315,   321,   324,   327,   328,   331,   334,   337,   340,
     343,   346,   347,   350,   353,   354,   357,   358,   358,   361,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   383,   384,   387,
     391,   394,   399,   400,   403
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
  "$accept", "partida", "program", "$@1", "bloco", "$@2", "declaracoes",
  "declaracao", "decl_de_var", "$@3", "tipo", "M0", "M1", "M2",
  "def_de_tipo", "nome_do_tipo", "definicao_de_tipo", "limites",
  "tipo_definido", "decl_de_proc", "proc_cab", "$@4", "$@5", "pro_corpo",
  "emit_return", "lista_de_parametros", "tipo_retornado", "parametro",
  "modo", "nome_do_proc", "lista_de_comandos", "lista_de_ids", "vazio",
  "espec_de_parametros", "comando", "comando_de_atribuicao", "$@6",
  "comando_while", "comando_repeat", "comando_if", "comando_read",
  "comando_write", "comando_return", "comando_exit", "rotulo", "variavel",
  "chamada_ou_indexacao", "chamada_de_proc", "indices", "$@7", "variavel2",
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

#define YYPACT_NINF -130

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-130)))

#define YYTABLE_NINF -80

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,  -130,    15,  -130,  -130,  -130,  -130,    22,  -130,  -130,
      99,  -130,    29,    41,    51,  -130,    67,    69,    30,  -130,
    -130,  -130,  -130,  -130,    61,    80,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,    65,  -130,  -130,  -130,  -130,  -130,   273,
      59,    51,  -130,  -130,   221,    51,  -130,    51,   221,   221,
    -130,    73,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,    76,  -130,    81,  -130,    85,    91,    -6,  -130,    92,
    -130,    31,    51,  -130,   221,  -130,  -130,  -130,   221,   221,
    -130,  -130,   194,  -130,  -130,  -130,  -130,    94,  -130,   273,
    -130,   261,   261,   221,  -130,   116,   273,   102,  -130,   101,
     221,   100,  -130,    51,  -130,  -130,  -130,   227,   285,  -130,
    -130,  -130,  -130,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   -11,   175,   273,  -130,  -130,   221,   221,
     261,   106,  -130,  -130,  -130,   113,  -130,   273,   221,   221,
      23,    90,   156,   126,    48,    64,    35,     7,    95,    95,
    -130,  -130,  -130,   261,   261,   120,   129,    -1,  -130,  -130,
       4,   274,   285,   221,   273,    12,   106,  -130,  -130,    -8,
    -130,    12,  -130,   105,   261,    19,  -130,  -130,  -130,  -130,
    -130,    -1,  -130,   131,  -130,  -130,  -130,    51,   273,  -130,
      21,  -130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    47,     0,     2,    47,    20,     1,    47,     8,    47,
      47,    18,     0,    14,     0,   104,    15,    16,     0,     9,
      12,    10,    17,    11,    47,     0,    38,    25,     5,     4,
      47,    22,     7,     0,    47,    26,    31,    32,    27,     0,
       0,     0,    47,    47,     0,     0,    47,     0,     0,     0,
      47,    47,    43,    50,    51,    52,    53,    54,    55,    56,
      57,     0,    60,    75,    58,    77,     0,    74,    47,    13,
      45,    47,     0,   100,     0,   103,   102,   101,     0,     0,
      94,    72,     0,    95,    97,    99,    98,    71,    69,     0,
      66,    68,    67,     0,    47,     0,     0,     0,    73,     0,
       0,     0,    19,     0,    47,    28,    42,     0,    82,    93,
      47,    47,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,    59,     0,     0,
      76,     0,    21,    46,    30,    47,    96,     0,     0,     0,
      83,    87,    84,    85,    86,    88,    89,    90,    91,    92,
      47,    47,    44,    61,    78,     0,     0,     0,    49,    29,
      47,    80,    81,     0,     0,     0,     0,    41,    40,     0,
      33,     0,    64,     0,    63,     0,    14,    15,    16,    23,
      24,     0,    48,     0,    47,    62,    34,     0,     0,    39,
       0,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,  -130,  -130,    82,  -130,   125,  -130,  -130,  -130,
     -89,    -4,     0,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,    58,  -130,  -130,   -17,  -130,  -130,
     -83,  -130,     6,  -130,   -82,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,   -38,   -36,  -130,  -130,  -130,
    -130,    70,  -130,  -130,  -129,  -130,   -10
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    29,    39,     7,    18,    19,    33,
      20,    10,   101,     4,    21,    30,   132,   155,    22,    23,
      24,    43,   135,    35,    36,   169,    25,   170,   171,   105,
      51,    69,    11,   159,    52,    53,    97,    54,    55,    56,
      57,    58,    59,    60,    61,    80,    81,    64,    65,    99,
      66,    82,    83,    84,    85,    86,    87
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    62,   156,    63,    31,    12,   123,     5,   150,    90,
       8,   172,   167,     1,   127,     6,    26,   -71,    94,   168,
     181,   -70,   176,   182,   -79,    -3,    40,   185,   191,    67,
      37,    70,    28,    94,    28,    88,    15,   180,    71,    72,
       8,    13,    89,   152,   177,   178,    93,    95,    94,    14,
      94,    62,   -35,    63,   160,    15,   121,   122,    62,    32,
      63,    27,   106,    16,    17,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   102,    15,   179,    26,   -36,    67,
     -37,   175,   183,   120,   121,   122,    67,    62,    34,    63,
     125,    38,    41,   133,   118,   119,   120,   121,   122,    62,
      68,    63,    94,    96,   -72,   190,   137,   138,   139,    13,
      37,   119,   120,   121,   122,    67,    98,    14,    91,    92,
     103,   100,   126,    15,   -79,   128,    62,    67,    63,   129,
     131,    16,    17,   115,   116,   117,   118,   119,   120,   121,
     122,   158,    77,   157,   107,   122,   163,   164,   108,   109,
      62,   165,    63,   104,    67,    27,   166,   184,   187,    42,
     173,    27,   134,   124,   186,     0,   102,     0,     0,     0,
     130,   117,   118,   119,   120,   121,   122,   189,    67,   151,
     188,     0,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,     0,     0,     0,   153,   154,
     116,   117,   118,   119,   120,   121,   122,     0,   161,   162,
       0,   110,   111,   112,     0,   113,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,     0,     0,     0,
       0,   111,   112,   174,   113,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    15,    73,     0,     0,     0,
       0,    74,     0,     0,     0,    75,    76,    77,   136,     0,
      78,     0,     0,     0,   111,   112,     0,   113,    79,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    44,     0,
       0,     0,    45,     0,     0,     0,     0,    46,    47,    48,
       0,     0,     0,     0,    49,    50,     0,    15,   111,   112,
       0,   113,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   112,     0,   113,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   113,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122
};

static const yytype_int16 yycheck[] =
{
      10,    39,   131,    39,    14,     9,    89,     1,    19,    47,
       4,     7,    13,    12,    96,     0,    10,    23,    29,    20,
      28,    27,    10,    31,    30,     3,    30,     8,     7,    39,
      24,    41,     3,    29,     3,    45,    24,   166,    42,    43,
      34,    10,    46,   125,    32,    33,    50,    51,    29,    18,
      29,    89,    11,    89,   137,    24,    49,    50,    96,    29,
      96,    71,    72,    32,    33,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    68,    24,   165,    71,    11,    89,
      11,   164,   171,    48,    49,    50,    96,   125,    27,   125,
      94,    11,    27,   103,    46,    47,    48,    49,    50,   137,
      41,   137,    29,    27,    23,   188,   110,   111,   112,    10,
     104,    47,    48,    49,    50,   125,    31,    18,    48,    49,
      28,    30,     6,    24,    30,    23,   164,   137,   164,    28,
      30,    32,    33,    43,    44,    45,    46,    47,    48,    49,
      50,   135,    36,    30,    74,    50,   150,   151,    78,    79,
     188,    31,   188,    71,   164,   165,    27,    52,    27,    34,
     160,   171,   104,    93,   181,    -1,   160,    -1,    -1,    -1,
     100,    45,    46,    47,    48,    49,    50,   187,   188,     4,
     184,    -1,    -1,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,    -1,   128,   129,
      44,    45,    46,    47,    48,    49,    50,    -1,   138,   139,
      -1,    17,    37,    38,    -1,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    37,    38,   163,    40,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    24,    25,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    36,    31,    -1,
      39,    -1,    -1,    -1,    37,    38,    -1,    40,    47,    42,
      43,    44,    45,    46,    47,    48,    49,    50,     5,    -1,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    14,    15,    16,
      -1,    -1,    -1,    -1,    21,    22,    -1,    24,    37,    38,
      -1,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    38,    -1,    40,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    54,    55,    66,    85,     0,    59,    85,    56,
      64,    85,    64,    10,    18,    24,    32,    33,    60,    61,
      63,    67,    71,    72,    73,    79,    85,   109,     3,    57,
      68,   109,    29,    62,    27,    76,    77,    85,    11,    58,
      64,    27,    59,    74,     5,     9,    14,    15,    16,    21,
      22,    83,    87,    88,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   103,   109,    41,    84,
     109,    64,    64,    25,    30,    34,    35,    36,    39,    47,
      98,    99,   104,   105,   106,   107,   108,   109,   109,    64,
      98,   104,   104,    64,    29,    64,    27,    89,    31,   102,
      30,    65,    85,    28,    57,    82,   109,   104,   104,   104,
      17,    37,    38,    40,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    83,   104,    64,     6,    87,    23,    28,
     104,    30,    69,   109,    77,    75,    31,    64,    64,    64,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
      19,     4,    87,   104,   104,    70,   107,    30,    85,    86,
      83,   104,   104,    64,    64,    31,    27,    13,    20,    78,
      80,    81,     7,    65,   104,    83,    10,    32,    33,    63,
     107,    28,    31,    63,    52,     8,    80,    27,    64,   109,
      83,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    56,    55,    58,    57,    59,    59,    60,
      60,    60,    62,    61,    63,    63,    63,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    74,    75,    73,
      76,    76,    77,    78,    78,    79,    79,    79,    79,    80,
      81,    81,    82,    83,    83,    84,    84,    85,    86,    86,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      89,    88,    90,    91,    92,    92,    93,    94,    95,    96,
      97,    98,    98,    99,   100,   100,   101,   102,   101,   103,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   105,   105,   106,
     106,   107,   108,   108,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     6,     0,     5,     4,     1,     1,
       1,     1,     0,     4,     1,     1,     1,     1,     1,     1,
       1,     6,     1,     4,     3,     1,     2,     0,     0,     7,
       5,     1,     1,     1,     3,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     4,     1,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     4,     7,     6,     6,    10,     2,     2,     2,     2,
       1,     1,     1,     2,     1,     1,     3,     0,     4,     1,
       4,     4,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1
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
        case 3:
#line 204 "bas.y" /* yacc.c:1646  */
    {decVar=1;}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 207 "bas.y" /* yacc.c:1646  */
    {}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 207 "bas.y" /* yacc.c:1646  */
    {}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 219 "bas.y" /* yacc.c:1646  */
    { }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 219 "bas.y" /* yacc.c:1646  */
    { }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 222 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[0].iValue); pTipo=(yyvsp[0].iValue);}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 223 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[0].iValue); pTipo=(yyvsp[0].iValue);}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 224 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[0].iValue); pTipo=(yyvsp[0].iValue);}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 225 "bas.y" /* yacc.c:1646  */
    {}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 240 "bas.y" /* yacc.c:1646  */
    {(yyval.sIndex) = strdup((yyvsp[0].sIndex));}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 246 "bas.y" /* yacc.c:1646  */
    {limiteInferior = (yyvsp[-2].iValue); limiteSuperior= (yyvsp[0].iValue); verificaLimites();}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 252 "bas.y" /* yacc.c:1646  */
    {ehProcedimento = 0;}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 255 "bas.y" /* yacc.c:1646  */
    {pTipo = (yyvsp[0].iValue);}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 255 "bas.y" /* yacc.c:1646  */
    { 	procedimentoAtual = strdup(identificadorAtual);
																		ehProcedimento = 1;
																	}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 278 "bas.y" /* yacc.c:1646  */
    {adicionaParametro((yyvsp[-3].iValue),(yyvsp[-2].iValue),strdup((yyvsp[0].sIndex)));}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 281 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[0].iValue);}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 282 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[0].iValue);}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 285 "bas.y" /* yacc.c:1646  */
    {(yyval.sIndex) = strdup((yyvsp[0].sIndex));}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 311 "bas.y" /* yacc.c:1646  */
    {verificaQuantidadeParam();ehChamadaProcedimento=0;contParametros=0;}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 315 "bas.y" /* yacc.c:1646  */
    {verificaAtribuicao();}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 315 "bas.y" /* yacc.c:1646  */
    {
																					verificaLimitesInteiros((yyvsp[0].iValue));
																					setValor(strdup((yyvsp[-3].sIndex)),(yyvsp[0].iValue));
																				}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 346 "bas.y" /* yacc.c:1646  */
    {(yyval.sIndex) = strdup((yyvsp[0].sIndex));}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 347 "bas.y" /* yacc.c:1646  */
    {}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 357 "bas.y" /* yacc.c:1646  */
    {verificaChamadaProcedimento();}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 358 "bas.y" /* yacc.c:1646  */
    {ehChamadaProcedimento=1;verificaChamadaProcedimento();}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 358 "bas.y" /* yacc.c:1646  */
    {verificaChamadaProcedimento();}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 361 "bas.y" /* yacc.c:1646  */
    {(yyval.sIndex) = strdup((yyvsp[0].sIndex));}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 367 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = ((yyvsp[-2].iValue) != (yyvsp[0].iValue));}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 368 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[-2].iValue) < (yyvsp[0].iValue);}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 369 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[-2].iValue) > (yyvsp[0].iValue);}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 370 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[-2].iValue) >= (yyvsp[0].iValue);}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 371 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[-2].iValue) <= (yyvsp[0].iValue);}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 372 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[-2].iValue) + (yyvsp[0].iValue);}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 373 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[-2].iValue) - (yyvsp[0].iValue);}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 374 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[-2].iValue) * (yyvsp[0].iValue);}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 375 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[-2].iValue) / (yyvsp[0].iValue);}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 376 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = pow((yyvsp[-2].iValue),(yyvsp[0].iValue));}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 377 "bas.y" /* yacc.c:1646  */
    {}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 378 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = getValor_int((yyvsp[0].sIndex));}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 379 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[0].iValue);}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 380 "bas.y" /* yacc.c:1646  */
    {(yyval.iValue) = (yyvsp[-1].iValue);}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 383 "bas.y" /* yacc.c:1646  */
    {}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 387 "bas.y" /* yacc.c:1646  */
    {
							(yyval.iValue) = (yyvsp[0].iValue);
							
						}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 391 "bas.y" /* yacc.c:1646  */
    {}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 394 "bas.y" /* yacc.c:1646  */
    {
							(yyval.iValue) = (yyvsp[0].iValue);
						}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 403 "bas.y" /* yacc.c:1646  */
    {
						(yyval.sIndex) = strdup((yyvsp[0].sIndex));
						identificadorAtual = strdup((yyvsp[0].sIndex));
						verificaChamadaProcedimento();
						verifica((yyvsp[0].sIndex)); 
						instala((yyvsp[0].sIndex));
						
					}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1902 "y.tab.c" /* yacc.c:1646  */
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
#line 413 "bas.y" /* yacc.c:1906  */

extern int contLinhas;
extern YYSTYPE yylval;

void yyerror(char *s) {
	printf("\n\nFoi encontrado um erro proximo a linha: %d\n", contLinhas);
	Imprime_Tabela();
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
	// imprimir_procedimentos();


  return 0;
}
