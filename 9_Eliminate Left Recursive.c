#include <stdio.h>

int main() {
    printf("Original Grammar:\n");
    printf("L -> L , S | S\n\n");

    printf("After Eliminating Left Recursion:\n");
    printf("L  -> S L'\n");
    printf("L' -> , S L' | ε\n");

    return 0;
}
