#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char str[]) {
    char keywords[6][10] = {"int","float","if","else","while","return"};
    for(int i=0;i<6;i++)
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    return 0;
}

int main() {
    char ch, buffer[20];
    int i = 0;

    FILE *fp = fopen("input.c", "r");

    if(fp == NULL) {
        printf("File not found\n");
        return 0;
    }

    while((ch = fgetc(fp)) != EOF) {

        /* Ignore spaces, tabs, new lines */
        if(ch == ' ' || ch == '\n' || ch == '\t')
            continue;

        /* Ignore single-line comments */
        if(ch == '/') {
            char next = fgetc(fp);
            if(next == '/') {
                while(fgetc(fp) != '\n');
                continue;
            } else {
                ungetc(next, fp);
                printf("Operator: /\n");
            }
        }

        /* Identifier or Keyword */
        if(isalpha(ch)) {
            buffer[i++] = ch;
            while(isalnum(ch = fgetc(fp)))
                buffer[i++] = ch;
            buffer[i] = '\0';
            i = 0;
            ungetc(ch, fp);

            if(isKeyword(buffer))
                printf("Keyword: %s\n", buffer);
            else
                printf("Identifier: %s\n", buffer);
        }

        /* Constant */
        else if(isdigit(ch)) {
            buffer[i++] = ch;
            while(isdigit(ch = fgetc(fp)))
                buffer[i++] = ch;
            buffer[i] = '\0';
            i = 0;
            ungetc(ch, fp);
            printf("Constant: %s\n", buffer);
        }

        /* Operators */
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='=')
            printf("Operator: %c\n", ch);
    }

    fclose(fp);
    return 0;
}
