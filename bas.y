%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	// #include "tabela.h"

	int yydebug = 0; /* For Debugging */

	int yylex();
	void yyerror(char *s);

	int contErros;

	//int instala(char* nome){
		//nome = YYSTYPE;
		//valor =
		//tipo = bool, char, int ...
	//}



	// void install( char *sym_name, simbolo_t atribut ){
	// 	Instala(sym_name,atribut);
	// }

%}

%union{
		int iValue;
		char* sIndex;

};

%token BGN
%token DO
%token IF
%token END
%token ENDIF
%token ENDWHILE
%token EXIT
%token INTEGER
%token PROCEDURE
%token PROGRAM
%token REFERENCE
%token REPEAT
%token READ
%token RETURN
%token THEN
%token TYPE
%token UNTIL
%token VALUE
%token WRITE
%token WHILE
%token ATRIBUICAO
%token <sIndex> ID
%token CONST_CHAR
%token LIMITES
%token DOISPONTOS
%token VIRGULA
%token PONTOVIRGULA
%token APARENTESE
%token FPARENTESE
%token BOOLEAN
%token CHAR
%token FALSO
%token VERDADEIRO
%token <iValue> NUMERO

%left LT
%left GT
%left LE
%left GE
%left EQ
%left NE
%left DIV
%left MULT
%left SUM
%left SUB
%left OR
%left AND
%left NOT
%left UMINUS
%right EXP

//Não pode aninhar else's
%nonassoc ELSE

%%
partida: program {
					printf("\nFuncionou no yacc: %d\n",yylval.iValue);
				}
	;

program : PROGRAM M2 declaracoes M0 bloco
			;

bloco   : BGN lista_de_comandos M0 END
		;

declaracoes : declaracoes M0 declaracao PONTOVIRGULA
		| vazio
		;

declaracao : decl_de_var
		 | def_de_tipo
		 | decl_de_proc
		 ;

decl_de_var : tipo DOISPONTOS lista_de_ids
		;

tipo : INTEGER
 | BOOLEAN
 | CHAR
 | tipo_definido
 ;

M0 : vazio
 ;

M1 : vazio
 ;

M2 : vazio
 ;

def_de_tipo : TYPE nome_do_tipo M0 EQ M1 definicao_de_tipo
			;

nome_do_tipo : identificador
		 ;

definicao_de_tipo : APARENTESE limites FPARENTESE tipo
				;

limites : inteiro DOISPONTOS inteiro
	;

tipo_definido : identificador
			;

decl_de_proc : proc_cab pro_corpo
		 ;

proc_cab : tipo_retornado PROCEDURE M0 nome_do_proc espec_de_parametros
	 ;

pro_corpo : DOISPONTOS declaracoes M0 bloco emit_return
		| emit_return
		;

emit_return : vazio
		;

lista_de_parametros : parametro
				| lista_de_parametros VIRGULA parametro
				;

tipo_retornado : INTEGER
			 | BOOLEAN
			 | CHAR
			 | vazio
			 ;

parametro : modo tipo DOISPONTOS identificador
		;

modo : VALUE
 | REFERENCE
 ;

nome_do_proc : identificador
		 ;

lista_de_comandos : comando
				| lista_de_comandos PONTOVIRGULA M0 comando
				;

lista_de_ids : identificador
		 | lista_de_ids VIRGULA identificador
		 ;

vazio :
	;

espec_de_parametros : APARENTESE lista_de_parametros FPARENTESE
				| vazio
				;

comando : comando_de_atribuicao
	| comando_while
	| comando_repeat
	| comando_if
	| comando_read
	| comando_write
	| comando_return
	| comando_exit
	| chamada_de_proc
	| rotulo DOISPONTOS comando
	;

comando_de_atribuicao : variavel ATRIBUICAO expr
					;

comando_while : WHILE M0 expr DO M0 lista_de_comandos ENDWHILE
			;

comando_repeat : REPEAT M0 lista_de_comandos UNTIL M0 expr
			 ;

comando_if : IF expr THEN M0 lista_de_comandos ENDIF
		 | IF expr THEN M0 lista_de_comandos M1 ELSE M0 lista_de_comandos ENDIF

comando_read : READ variavel
		 ;

comando_write : WRITE expr
			;

comando_return :  RETURN expr
			 ;

comando_exit : EXIT identificador
		 ;

rotulo : identificador
	 ;

variavel : identificador
	 | chamada_ou_indexacao
	 ;

chamada_ou_indexacao : indices FPARENTESE
				 ;

chamada_de_proc : identificador
					| chamada_ou_indexacao
					;

indices : variavel2 APARENTESE  expr
	| indices VIRGULA expr
	;

variavel2 : identificador
		;

expr : expr OR M0 expr
 | expr AND M0 expr
 | NOT expr
 | expr NE expr
 | expr LT expr
| expr GT expr
| expr GE expr
 | expr LE expr
 | expr SUM expr
 | expr SUB expr
 | expr MULT expr
 | expr DIV expr
 | expr EXP expr
 | SUB expr %prec UMINUS
 | variavel
 | constante
 | APARENTESE expr FPARENTESE
 ;

constante : int_ou_char
		| booleano
		;

int_ou_char : inteiro
		| CONST_CHAR
		;

inteiro : NUMERO
	;

booleano : VERDADEIRO
	 | FALSO
	 ;

identificador : ID {
	printf("okokok");
//install($1.nome,$1);
}
			;

%%
extern int contLinhas;
extern YYSTYPE yylval;
void yyerror(char *s) {
	printf("\nFoi encontrado um erro proximo a linha: %d\n", contLinhas);
}

int main(void) {
	printf("%d ",contLinhas);
  int executou= yyparse();

	if(!executou){//É 0 se executou
		 printf("\nPrograma sintaticamente correto!\n");
	}

  return 0;
}
