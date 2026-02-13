#include <stdio.h>

int main() {
    char str[200];
    int i = 0, count = 0;

    printf("Enter sentence: ");
    fgets(str, sizeof(str), stdin);

    while(str[i] != '\0') {
        char ch = str[i];

        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
           ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
            count++;

        i++;
    }

    printf("Number of vowels: %d\n", count);
    return 0;
}
