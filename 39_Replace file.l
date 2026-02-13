%{
#include <stdio.h>
%}

%%
hello      { printf("HI"); }
.|\n       { printf("%s", yytext); }
%%

int yywrap(){ return 1; }

int main(){
    yylex();
    return 0;
}
