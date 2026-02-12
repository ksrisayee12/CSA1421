#include <stdio.h>
#include <string.h>

int main() {
    char expr[20];
    char op1, op2, op;
    char temp = 't';

    printf("Enter expression (a+b): ");
    scanf("%s", expr);

    op1 = expr[0];
    op = expr[1];
    op2 = expr[2];

    printf("%c = %c %c %c\n", temp, op1, op, op2);

    return 0;
}
