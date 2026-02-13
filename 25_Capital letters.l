%{
#include <stdio.h>
%}

%%
[A-Z]+      { printf("Capital Word: %s\n", yytext); }
.|\n        ;
%%

int yywrap() { return 1; }

int main() {
    yylex();
    return 0;
}
