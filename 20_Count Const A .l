%{
#include <stdio.h>
%}

%%
[0-9]+\.[0-9]+      { printf("Float Constant: %s\n", yytext); }
[0-9]+              { printf("Integer Constant: %s\n", yytext); }
\".*\"              ;   /* Ignore string literals */
.                   ;
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}
