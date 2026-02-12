#include <stdio.h>
#include <string.h>

char trail[3][10] = {
    "id )",
    "id )",
    "id )"
};

int main() {
    printf("TRAILING(E) = { %s }\n", trail[0]);
    printf("TRAILING(T) = { %s }\n", trail[1]);
    printf("TRAILING(F) = { %s }\n", trail[2]);
    return 0;
}
