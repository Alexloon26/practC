#include <stdio.h>

int main(void) {
    char currentChar;
    printf("Enter string: ");
    while ((currentChar=getchar()) != '\n') {
        if (currentChar>='A'&& currentChar<='Z') {
            currentChar+=32;
        }
        putchar(currentChar);
    }
    return 0;
}