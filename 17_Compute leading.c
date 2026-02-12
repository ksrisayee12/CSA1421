#include <stdio.h>
#include <string.h>

char lead[3][10] = {
    "id (",
    "id (",
    "id ("
};

int main() {
    printf("LEADING(E) = { %s }\n", lead[0]);
    printf("LEADING(T) = { %s }\n", lead[1]);
    printf("LEADING(F) = { %s }\n", lead[2]);
    return 0;
}
