%{
#include <stdio.h>

int comment_count = 0;
FILE *fp;
%}

%%
"//".*                 { comment_count++; }
"/*"([^*]|\*+[^*/])*\*+/"  { comment_count++; }

.|\n                   { fprintf(fp,"%s", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    fp = fopen("output.c", "w");
    yylex();
    fclose(fp);
    printf("Number of comment lines: %d\n", comment_count);
    return 0;
}
