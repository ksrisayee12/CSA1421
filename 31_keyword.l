%{
#include <stdio.h>
%}

%%
"int"|"float"|"char"|"void"|"return"|"if"|"else"
        { printf("Keyword: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*
        { printf("Identifier: %s\n", yytext); }

[ \t\n]+ ;

. ;
%%

int yywrap(){ return 1; }

int main(){
    yylex();
    return 0;
}
