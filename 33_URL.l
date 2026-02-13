%{
#include <stdio.h>
%}

%%
(http|https)://[a-zA-Z0-9]+\.(com|in|org)
        { printf("Valid URL\n"); }

.+      { printf("Invalid URL\n"); }
%%

int yywrap(){ return 1; }

int main(){
    yylex();
    return 0;
}
