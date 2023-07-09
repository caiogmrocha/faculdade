#include <stdio.h>

int main() {
    int P = 1, Q = 0, R = 1;

    if (P && !Q || R) {
        printf("A expressão é verdadeira para os valores padrões");
    } else {
        printf("A expressão é falsa para os valores padrões");
    }

    return 0;
}