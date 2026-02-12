%{
#include <stdio.h>

int lines = 0;
int words = 0;
int chars = 0;
%}

%%

[ \t]+        ;

\n            { lines++; }

[a-zA-Z0-9_]+ { words++; chars += yyleng; }

.             { chars++; }

%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);
    return 0;
}
