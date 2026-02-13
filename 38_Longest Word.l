%{
#include <stdio.h>
#include <string.h>

int max = 0;
char longest[100];
%}

%%
[a-zA-Z]+ {
              if(yyleng > max){
                  max = yyleng;
                  strcpy(longest, yytext);
              }
           }

.|\n      ;
%%

int yywrap(){ return 1; }

int main(){
    yylex();
    printf("Longest word: %s\n", longest);
    printf("Length: %d\n", max);
    return 0;
}
