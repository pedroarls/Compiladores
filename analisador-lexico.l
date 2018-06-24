/*Para ler somente um arquivo de entrada*/
%option noyywrap
%{
    /*definições de constantes manifestas*/
    int LT=0, LE=1, EQ=2, NE=3, GT=4, GE=5,
    IF=6, THEN=7, ELSE=8, ID=9, NUMBER=10, RELOP=11,
    BEGN=12, BOOLEAN=13, CHAR=14, DO=15, END=16, FALSO=17, ENDIF=18, ENDWHILE=19, EXIT=20, INTEGER=21, PROCEDURE=22,
    PROGRAM=23, REFERENCE=24, REPEAT=25, READ=26, RETURN=27, VERDADEIRO=28, TYPE=29, UNTIL=30,VALUE=31, WRITE=32, WHILE=33,
    
    TIPO = 34, BOOL=35, DEF_TIPO=36, CARACTERE=37, ATRIBUICAO=38, LIMITES=39,

    SUM=40, SUB=41, MULT=42, DIV=43, ARITOP=44,EXPO=45,BOOLOP=46,
    AND=47, OR=48, NOT=49;
%}

delim       [ \t\n]
ws          {delim}+
comentario  "/*".*"*/"
digit       [0-9]
letter      [a-zA-Z]
id          {letter}({letter}|{digit})*
negative    "-"{digit}+
positive    ("+")?{digit}+


limites {positive}{ws}?":"{ws}?{positive}

caractere   \'[A-Z]\'
terminais   [(),;''""{}\[\]:]

%%

{ws}            {}
{comentario}    {}

"begin"     {
                printf("Foi encontrado uma BEGIN. LEXEMA: %s\n", yytext);
                // return (BEGIN);
            }

 
"boolean"   {
                printf("Foi encontrado uma declaração de tipo boolean. LEXEMA: %s\n", yytext);
                // yylval= BOOLEAN;
                // return (TIPO);
            }

"char"      {
                printf("Foi encontrado uma declaração de tipo char. LEXEMA: %s\n", yytext);
                // yylval= CHAR;
                // return (TIPO);
            }

"do"        {
                printf("Foi encontrado um DO. LEXEMA: %s\n", yytext);
                // return (DO);  
            }


"if"        {
                printf("Foi encontrado IF. LEXEMA: %s\n",yytext);
                // return (IF);
            }

"else"      {
                printf("Foi encontrado ELSE. LEXEMA: %s\n", yytext);
                // return (ELSE);
    
            }

"end"       {
                printf("Foi encontrado um END. LEXEMA: %s\n",yytext);
                // return (END);

            }

"endif"     {
                printf("Foi encontrado um ENDIF. LEXEMA: %s\n",yytext);
                // return (ENDIF);

            }

"endwhile"  {
                 printf("Foi encontrado um ENDWHILE. LEXEMA: %s\n",yytext);
                // return (ENDWHILE);   
            }

"exit"      {
                 printf("Foi encontrado um EXIT. LEXEMA: %s\n",yytext);
                // return (EXIT);
            }

"false"     {
                printf("Foi encontrado um boolean. LEXEMA: %s\n", yytext);
                // yylval= FALSO;
                // return (BOOL);
            }

"integer"   {
                printf("Foi encontrado uma declaração de tipo inteiro. LEXEMA: %s\n", yytext);
                // yylval= INTEGER;
                // return (TIPO);
            }

"not"       {
                printf("Foi encontrado um operador not. LEXEMA: %s\n", yytext);
                // yylval= NOT;
                // return (BOOLOP);
            }


"procedure" {
                 printf("Foi encontrado um PROCEDURE. LEXEMA: %s\n",yytext);
                // return (PROCEDURE);
            }

"program"   {
                 printf("Foi encontrado um PROGRAM. LEXEMA: %s\n",yytext);
                // return (PROGRAM);
            }

"reference" {
                 printf("Foi encontrado um REFERENCE. LEXEMA: %s\n",yytext);
                // return (REFERENCE);
            }

"repeat"    {
                 printf("Foi encontrado um REPEAT. LEXEMA: %s\n",yytext);
                // return (REPEAT);
            }

"read"      {
                 printf("Foi encontrado um READ. LEXEMA: %s\n",yytext);
                // return (READ);
            }

"return"    {
                 printf("Foi encontrado um RETURN. LEXEMA: %s\n",yytext);
                // return (RETURN);
            }

"then"      {
                printf("Foi encontrado THEN. LEXEMA: %s\n", yytext);
                // return (THEN);
            }

"true"      {
                printf("Foi encontrado um boolean. LEXEMA: %s\n", yytext);
                // yylval= VERDADEIRO;
                // return (BOOL);
            } 


"type"      {
                printf("Foi encontrado um type. LEXEMA: %s\n", yytext);
                // return (TYPE);
            }

"until"     {
                 printf("Foi encontrado um UNTIL. LEXEMA: %s\n",yytext);
                // return (UNTIL);
            }

"value"     {
                 printf("Foi encontrado um VALUE. LEXEMA: %s\n",yytext);
                // return (VALUE);
            }

"write"     {
                 printf("Foi encontrado um WRITE. LEXEMA: %s\n",yytext);
                // return (WRITE);
            }

"while"     {
                 printf("Foi encontrado um WHILE. LEXEMA: %s\n",yytext);
                // return (WHILE);
            }


"<"         {
                printf("Foi encontrado RELOP. LEXEMA: %s\n", yytext);
                // return (LT);

            }

">"         {
                printf("Foi encontrado RELOP. LEXEMA: %s\n", yytext);
                // return (GT);
            }

"<="        {
                printf("Foi encontrado RELOP. LEXEMA: %s\n", yytext);
                // return (LE);

            }

">="        {
                printf("Foi encontrado RELOP. LEXEMA: %s\n", yytext);
                // return (GE);

            }

"="         {
                printf("Foi encontrado RELOP. LEXEMA: %s\n", yytext);
                // return (EQ);

            }

":="         {
                printf("Foi encontrada uma atribuicao. LEXEMA: %s\n", yytext);
                // return (ATRIBUICAO);

            }

"not="      {
                printf("Foi encontrado RELOP. LEXEMA: %s\n", yytext);
                // return (NE);
            }

"/"         {
                printf("Foi encontrado um operador de divisao. LEXEMA: %s\n", yytext);
                // yylval= DIV;
                // return (ARITOP);
            }

"*"         {
                printf("Foi encontrado um operador de multiplicacao. LEXEMA: %s\n", yytext);
                // yylval= MULT;
                // return (ARITOP);
            }

"+"         {
                printf("Foi encontrado um operador de adicao. LEXEMA: %s\n", yytext);
                // yylval= SUM;
                // return (ARITOP);
            }

"-"         {
                printf("Foi encontrado um operador de subtracao. LEXEMA: %s\n", yytext);
                // yylval= SUB;
                // return (ARITOP);
            }

"**"        {
                printf("Foi encontrado um operador de exponenciacao. LEXEMA: %s\n", yytext);
                // return (EXPO);
            }

"|"         {
                printf("Foi encontrado um operador or. LEXEMA: %s\n", yytext);
                // yylval= OR;
                // return (BOOLOP);
            }

"&"         {
                printf("Foi encontrado um operador and. LEXEMA: %s\n", yytext);
                // yylval= AND;
                // return (BOOLOP);
            }

{id}        {   
                printf("Foi encontrado um identificador. LEXEMA: %s\n", yytext);
                // return (ID);
            }

{negative}  {
                printf("Foi encontrado um numero inteiro negativo.LEXEMA: %s\n",yytext);
            }

{positive}  {
                printf("Foi encontrado um numero inteiro positivo. LEXEMA: %s\n",yytext);
            }



{caractere} {
                 printf("Foi encontrado um caractere. LEXEMA: %s\n", yytext);
                // return (NE);

            }

{limites}       {
                     printf("Foi encontrada uma definição de limites. LEXEMA: %s\n", yytext);
                }

{terminais}     {
                    printf("Foi encontrado um terminal. LEXEMA: %s\n", yytext);

                }

.       {
            printf("Caractere nao reconhecido: %s\n",yytext);
        }


%%
int main(void)
{
    yylex();
    return 0;
}

