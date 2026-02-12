#include <stdio.h>

int main() {
    char ch, next;
    FILE *fp = fopen("input.c", "r");

    if(fp == NULL) {
        printf("File not found\n");
        return 0;
    }

    while((ch = fgetc(fp)) != EOF) {

        if(ch == ' ' || ch == '\n' || ch == '\t')
            continue;

        if(ch == '/') {
            next = fgetc(fp);
            if(next == '/') {
                while(fgetc(fp) != '\n');
                continue;
            }
            else if(next == '*') {
                while(1) {
                    ch = fgetc(fp);
                    if(ch == '*' && fgetc(fp) == '/')
                        break;
                }
                continue;
            }
            else {
                ungetc(next, fp);
            }
        }

        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}
