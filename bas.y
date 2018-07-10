%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include "tabela.h"

	int yydebug = 0; /* For Debugging */

	int yylex();
	void yyerror(char *s);

	int contErros, pTipo;
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

%}

%union{
		int iValue;
		char* sIndex;
		char const_char;
};

%token BGN
%token DO
%token IF
%token END
%token ENDIF
%token ENDWHILE
%token EXIT
%token <iValue>INTEGER
%token <iValue>PROCEDURE
%token PROGRAM
%token REFERENCE
%token REPEAT
%token READ
%token RETURN
%token THEN
%token <iValue>TYPE
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
%token <iValue>BOOLEAN
%token <iValue>CHAR
%token <iValue>FALSO
%token <iValue>VERDADEIRO
%token <iValue> NUMERO

%left OR
%left AND
%left <iValue>NOT
%left NE
%left EQ
%left LE
%left LT
%left GT
%left GE
%left <iValue>SUM
%left <iValue>SUB
%left <iValue>MULT
%left <iValue>DIV
%right EXP
%left UMINUS

%start partida

%type <sIndex> identificador
%type <sIndex> nome_do_proc
%type <iValue> expr
%type <iValue> inteiro
%type <iValue> int_ou_char
%type <iValue> constante
%type <iValue> booleano
%type <sIndex> variavel
%type <sIndex> nome_do_tipo
%type <sIndex> variavel2

// %type <expressao> expr 

//Não pode aninhar else's
%nonassoc ELSE

%%
partida: program
	;

program : PROGRAM M2 declaracoes M0 bloco
			;

bloco   : BGN{} lista_de_comandos M0 END{}
		;

declaracoes : declaracoes M0 declaracao PONTOVIRGULA
		| vazio
		;

declaracao : decl_de_var
		 | def_de_tipo
		 | decl_de_proc
		 ;

decl_de_var : tipo { } DOISPONTOS lista_de_ids { }
		;

tipo : INTEGER {pTipo=$1;}
 | BOOLEAN {pTipo=$1;}
 | CHAR {pTipo=$1;}
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

nome_do_tipo : identificador {$$ = strdup($1);}
		 ;

definicao_de_tipo : APARENTESE limites FPARENTESE tipo
				;

limites : inteiro DOISPONTOS inteiro
	;

tipo_definido : identificador
			;

decl_de_proc : proc_cab pro_corpo
		 ;

proc_cab : tipo_retornado PROCEDURE {pTipo = $2;} M0 nome_do_proc espec_de_parametros 
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

nome_do_proc : identificador {$$ = strdup($1);}
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

comando_de_atribuicao : variavel {verificaAtribuicao();} ATRIBUICAO expr 	{
																				verificaLimitesInteiros($4);
																				setValor(strdup($1),$4);
																			}
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

variavel : identificador {$$ = strdup($1);}
	 | chamada_ou_indexacao {}
	 ;

chamada_ou_indexacao : indices FPARENTESE
				 ;

chamada_de_proc : identificador
					| chamada_ou_indexacao{}
					;

indices : variavel2 APARENTESE  expr
	| indices VIRGULA expr
	;

variavel2 : identificador {$$ = strdup($1);}
		;

expr : expr OR M0 expr
 | expr AND M0 expr
 | NOT expr 
 | expr NE expr
 | expr LT expr
| expr GT expr
| expr GE expr
 | expr LE expr
 | expr SUM expr 	{$$ = $1 + $3;}
 | expr SUB expr 	{$$ = $1 - $3;}
 | expr MULT expr	{$$ = $1 * $3;}
 | expr DIV expr	{$$ = $1 / $3;}
 | expr EXP expr	{$$ = pow($1,$3);}
 | SUB expr %prec UMINUS {}
 | variavel { $$ = getValor_int($1);
 			}
 | constante {$$ = $1;}
 | APARENTESE expr FPARENTESE {$$ = $2;}
 ;

constante : int_ou_char {}
		| booleano
		;

int_ou_char : inteiro	{
							$$ = $1;
							
						}
		| CONST_CHAR {}
		;

inteiro : NUMERO 	{
						$$ = $1;
					}
	;

booleano : VERDADEIRO
	 | FALSO
	 ;

identificador : ID	{
						$$ = strdup($1);
						identificadorAtual = strdup($1);
						instala($1);
					}
			;

%%
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
