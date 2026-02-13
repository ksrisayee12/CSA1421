%{
#include <stdio.h>
%}

%%
\+[0-9]+      { printf("Positive Number: %s\n", yytext); }
-[0-9]+       { printf("Negative Number: %s\n", yytext); }
[0-9]+        { printf("Positive Number: %s\n", yytext); }
[ \t\n]+      ;
.             ;
%%

int yywrap(){ return 1; }

int main(){
    yylex();
    return 0;
}
