/*Para ler somente um arquivo de entrada*/
%option noyywrap
%{
    #include "y.tab.h"
    #include <string.h>
    #include <stdio.h>

    void yyerror(char *c);

    int contLinhas=1;

    /*definições de constantes manifestas*/
%}

delim       [ \t]
ws          {delim}+
comentario  "/*".*"*/"
digit       [0-9]
letter      [a-zA-Z]
id          {letter}({letter}|{digit})*
numero      {digit}+
caractere   \'[A-Z]\'

%%

{ws}            {ECHO;}
{comentario}    {ECHO;}

"begin"         {
                    ECHO;
                    return (BGN);
                }


"boolean"       {
                    ECHO;
                    yylval.iValue = BOOLEAN;
                    return (BOOLEAN);
                }

"char"          {
                    ECHO;
                    yylval.iValue = CHAR;
                    return (CHAR);
                }

"do"            {
                    ECHO;
                    return (DO);
                }


"if"            {
                    ECHO;
                    return (IF);
                }

"else"          {
                    ECHO;
                    return (ELSE);

                }

"end"           {
                    ECHO;
                    return (END);
                }

"endif"         {
                    ECHO;
                    return (ENDIF);

                }

"endwhile"      {
                    ECHO;
                    return (ENDWHILE);
                }

"exit"          {
                    ECHO;
                    return (EXIT);
                }

"false"         {
                    ECHO;
                    return (FALSO);
                }

"integer"       {
                    ECHO;
                    yylval.iValue = INTEGER;
                    return (INTEGER);
                }

"not"           {
                    ECHO;
                    return (NOT);
                }


"procedure"     {
                    ECHO;
                    return (PROCEDURE);
                }

"program"       {
                    ECHO;
                    return (PROGRAM);
                }

"reference"     {
                    ECHO;
                    return (REFERENCE);
                }

"repeat"        {
                    ECHO;
                    return (REPEAT);
                }

"read"          {
                    ECHO;
                    return (READ);
                }

"return"        {
                    ECHO;
                    return (RETURN);
                }

"then"          {
                    ECHO;
                    return (THEN);
                }

"true"          {
                    ECHO;
                    return (VERDADEIRO);
                }


"type"          {
                    ECHO;
                    return (TYPE);
                }

"until"         {
                    ECHO;
                    return (UNTIL);
                }

"value"         {
                    ECHO;
              	    return (VALUE);
                }

"write"         {
                    ECHO;
                    return (WRITE);
                }

"while"         {
                    ECHO;
                    return (WHILE);
                }


"<"             {
                    ECHO;
                    return (LT);
                }

">"             {
                    ECHO;
                    return (GT);
                }

"<="            {
                    ECHO;
                    return (LE);

                }

">="            {
                    ECHO;
                    return (GE);
                }

"="             {
                    ECHO;
                    return (EQ);
                }

":="            {  
                    ECHO;
                    return (ATRIBUICAO);
                }

"not="          {
                    ECHO;
                    return (NE);
                }

"/"             {
                    ECHO;
                    return (DIV);
                }

"*"             {
                    ECHO;
                    return (MULT);
                }

"+"             {
                    ECHO;
                    return (SUM);
                }

"-"             {
                    ECHO;
                    return (SUB);
                }

"**"            {
                    ECHO;
                    return (EXP);
                }

"|"             {
                    ECHO;
                    return (OR);
                }

"&"             {
                    ECHO;
                    return (AND);
                }

{id}            {
                    ECHO;
                    yylval.sIndex = yytext;
                    return (ID);
                }

{numero}        {
                    ECHO;
                    return (NUMERO);
                }


{caractere}     {
                    ECHO;
                    return (CONST_CHAR);

                }

[:]             {
                    ECHO;
			        return DOISPONTOS;
		        }

[,]             {
                    ECHO;
			        return VIRGULA;
		        }

[;]             {
                    ECHO;
			        return PONTOVIRGULA;
		        }

[(]             {
                    ECHO;
			        return APARENTESE;
		        }

[)]             {
                    ECHO;
			        return FPARENTESE;
		        }

"\n"            {
                    ECHO;
    			    contLinhas++;
                    printf("%d ", contLinhas);
    		    }

.               {
                    // ECHO;
                    printf("\nErro lexico na linha %d.\n",contLinhas);
                    exit(1);
                }
%%

//int main(void)
//{
//    yylex();
//    return 0;
//}
