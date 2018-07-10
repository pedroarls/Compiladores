/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 54 "bas.y" /* yacc.c:1909  */

		// typedef struct{
		// 	int tipo;
		// 	union{
		// 		int iValue;
		// 		char character;
		// 	}
		// }expressao;

		int iValue;
		char* sIndex;


#line 172 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
