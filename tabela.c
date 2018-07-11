#include <string.h>
#include <stdio.h>
#include "tabela.h"

#define NMax 10 /* numero maximo de niveis */

int escopo[10];
int nivel;  /* guarda o nivel atual */
int L;      /* indice do ultimo elemento da Tabela de Simbolos */

void iniciaListaNO()
{
	L = 1;    /* Considera-se que a primeira posicao da tabela eh a de indice 1. */
	nivel = 1;           /* O primeiro nivel eh o 1 */
	escopo[nivel] = L;   /* escopo[1] contem o indice do primeiro elemento */
}

/************  Funcao que define os erros provaveis de ocorrer **********/

void Erro(int num)
{
	switch (num) {
		case 1: printf("\nTabela de Simbolos cheia\n"); break;
		case 2: printf("\nItem nao foi encontrado\n"); break;
		case 3: //printf("\nItem ja foi inserido\n"); break;
		default: ;
	}
}

/******************* Funcao de entrada num bloco ********************/

 void Entrada_Bloco()
{
	nivel++;
	if (nivel > NMax) Erro(1);
	else escopo[nivel] = L;
}

/******************** Funcao de saida de um bloco ***********************/

 void Saida_Bloco()
{
	L = escopo[nivel];
	nivel--;
}

/****************  Funcao que pesquisa item na tabela*******************/
/* Pesquisa o simbolo "X" e retorna o indice da Tabela de simbolos onde ele se encontra */

int Recupera_Entrada(char* X)
{
	int K; /* percorre a lista */
	K = L;

	while (K > 1)
	{
        K--;
        if( !strcmp(X, tabela_simbolos[K].nome ) ) return K;		// X foi encontrado
	}
    	/*Erro(2);*/
	return 0;
}

/***************  Funcao que instala o item na tabela*****************/
/* Instala o simbolo "X" com os atributos na Tabela de Simbolos */

 void Instala(char* X, simbolo_t atribut)
{
	int K;
	K = L;
	
	while (K > escopo[nivel]) {
        K--;
        if( !strcmp(X, tabela_simbolos[K].nome) ) {	// X ja pertence a tabela
			Erro(3);
			return;
		}
	}
	
	tabela_simbolos[L] = atribut;
	tabela_simbolos[L].ehProcedimento = 0;
	tabela_simbolos[L].procedimento.numero_parametros = 0;
	L++;
}

/******  Funcao que imprime alguns atributos da tabela de simbolos***********/

void Imprime_Tabela()
{
	int i;
	printf("Tabela de Simbolos:\n");
	printf("===================\n\n");
	printf("INDICE\t\tTIPO\t\tNOME\t\tVALOR\n");
	printf("======\t\t====\t\t====\t\t====\n");
	for (i = 1; i < L ; i++ )
	{
		printf("%d\t\t%d\t\t%s\t\t%d\n", i, tabela_simbolos[i].tipo, tabela_simbolos[i].nome,tabela_simbolos[i].valor_inteiro);
	}
}


/****** ********/

int getValorInteiro(char *X){
	int K;// X foi encontrado
	K = L;
	
	while (K > escopo[nivel]) {
        K--;
        if( !strcmp(X, tabela_simbolos[K].nome) ) {	// X ja pertence a tabela
			return tabela_simbolos[K].valor_inteiro;
		}
	}

	return 0;
}


void setValorInt(char* X, int valor){
	int K;
	K = L;
	
	while (K > escopo[nivel]) {
        K--;
        if( !strcmp(X, tabela_simbolos[K].nome) ) {	// X ja pertence a tabela
			tabela_simbolos[K].valor_inteiro = valor;
		}
	}
}


simbolo_t RecuperaSimbolo(char* X){
	int K; /* percorre a lista */
	K = L;

	simbolo_t s;

	strcpy(s.nome,"Simbolo nao encontrado.\n");
	s.tipo = -1;

	while (K > 1)
	{
        K--;
        if( !strcmp(X, tabela_simbolos[K].nome ) ) return tabela_simbolos[K];		// X foi encontrado
	}
    
	return s;
}

void setProcedimento(char* X){
	int K; /* percorre a lista */
	K = L;

	simbolo_t s;

	strcpy(s.nome,"Simbolo nao encontrado.\n");
	s.tipo = -1;

	while (K > 1)
	{
        K--;
        if( !strcmp(X, tabela_simbolos[K].nome ) ) 
			tabela_simbolos[K].ehProcedimento = 1;		
	}
}

void adicionar_parametro(char* X, int modo, int tipo, char* nome_parametro){
	int K; /* percorre a lista */
	K = L;
	int posicaoParametro;

	simbolo_t s;

	strcpy(s.nome,"Simbolo nao encontrado.\n");
	s.tipo = -1;

	while (K > 1)
	{
        K--;
        if( !strcmp(X, tabela_simbolos[K].nome ) ) {
	 		posicaoParametro = tabela_simbolos[K].procedimento.numero_parametros;
			
	// 		//coloca o nome do parametro
			// strcpy(tabela_simbolos[K].procedimento.parametro[posicaoParametro], strdup(nome_parametro));
			tabela_simbolos[K].procedimento.tipo_parametro[posicaoParametro] = tipo; //coloca o tipo do parametro
			tabela_simbolos[K].procedimento.numero_parametros = tabela_simbolos[K].procedimento.numero_parametros +1;
			return;
		}
	}
    
	printf("\nSimbolo nao encontrado. Procedimento: %s\n",strdup(X));
	return;
}

void imprimir_procedimentos(){
	int i,j;
	procedimento_t procedimentoAtual;
	printf("\n\nTabela de Procedimentos:\n");
	printf("===================\n\n");
	printf("INDICE\t\tTIPO\n");
	printf("======\t\t====\n");
	for (i = 1; i < L ; i++ )
	{
		if(tabela_simbolos[i].ehProcedimento){
			for(j=0; j<tabela_simbolos[i].procedimento.numero_parametros;j++){
				procedimentoAtual = tabela_simbolos[i].procedimento;
				printf("%d\t\t%d\n", j, procedimentoAtual.tipo_parametro[j]);
			}
		}
	}
}