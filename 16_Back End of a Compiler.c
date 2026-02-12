#include <stdio.h>

int main() {
    char op, arg1, arg2, result;

    FILE *fp = fopen("ic.txt", "r");

    if (fp == NULL) {
        printf("Intermediate code file not found\n");
        return 0;
    }

    printf("Target Code (Assembly-like):\n\n");

    while (fscanf(fp, "%c = %c %c %c\n",
                  &result, &arg1, &op, &arg2) != EOF) {

        switch (op) {
            case '+':
                printf("MOV %c, R1\n", arg1);
                printf("ADD %c, R1\n", arg2);
                printf("MOV R1, %c\n\n", result);
                break;

            case '-':
                printf("MOV %c, R1\n", arg1);
                printf("SUB %c, R1\n", arg2);
                printf("MOV R1, %c\n\n", result);
                break;

            case '*':
                printf("MOV %c, R1\n", arg1);
                printf("MUL %c, R1\n", arg2);
                printf("MOV R1, %c\n\n", result);
                break;

            case '/':
                printf("MOV %c, R1\n", arg1);
                printf("DIV %c, R1\n", arg2);
                printf("MOV R1, %c\n\n", result);
                break;
        }
    }

    fclose(fp);
    return 0;
}
