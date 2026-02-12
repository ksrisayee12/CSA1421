%{
#include <stdio.h>

int macros = 0;
int headers = 0;
%}

%%
"#define"          { macros++; }
"#include"         { headers++; }
.|\n               ;
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    printf("Number of Macros: %d\n", macros);
    printf("Number of Header Files: %d\n", headers);
    return 0;
}
