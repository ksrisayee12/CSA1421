%{
#include <stdio.h>
#include <stdlib.h>

int a, b;
%}

%%
[0-9]+   { a = atoi(yytext); }

"+"      {
            scanf("%d", &b);
            printf("Result = %d\n", a + b);
         }

"-"      {
            scanf("%d", &b);
            printf("Result = %d\n", a - b);
         }

"*"      {
            scanf("%d", &b);
            printf("Result = %d\n", a * b);
         }

"/"      {
            scanf("%d", &b);
            if(b != 0)
                printf("Result = %d\n", a / b);
            else
                printf("Division by zero error\n");
         }

.|\n     ;
%%

int yywrap(){ return 1; }

int main(){
    printf("Enter expression (example: 5+3):\n");
    yylex();
    return 0;
}
