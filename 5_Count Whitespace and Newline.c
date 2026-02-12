#include <stdio.h>

int main() {
    char ch;
    int spaces = 0, newlines = 0;

    FILE *fp = fopen("input.c", "r");

    if(fp == NULL) {
        printf("File not found\n");
        return 0;
    }

    while((ch = fgetc(fp)) != EOF) {
        if(ch == ' ')
            spaces++;
        else if(ch == '\n')
            newlines++;
    }

    fclose(fp);

    printf("Spaces: %d\n", spaces);
    printf("New lines: %d\n", newlines);

    return 0;
}
