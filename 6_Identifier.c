#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char id[20];
    int valid = 1;

    printf("Enter identifier: ");
    scanf("%s", id);

    if(!(isalpha(id[0]) || id[0] == '_'))
        valid = 0;

    for(int i = 1; i < strlen(id); i++) {
        if(!(isalnum(id[i]) || id[i] == '_')) {
            valid = 0;
            break;
        }
    }

    if(valid)
        printf("Valid Identifier\n");
    else
        printf("Invalid Identifier\n");

    return 0;
}
