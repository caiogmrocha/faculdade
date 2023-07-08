#include <stdio.h>

int main() {
    int entradas[3];

    scanf("%d %d %d", &entradas[0], &entradas[1], &entradas[2]);

    int entradas_ordenadas[3] = {
        entradas[0],
        entradas[1],
        entradas[2]
    };

    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            if (entradas_ordenadas[i] > entradas_ordenadas[j]) {
                int temp = entradas_ordenadas[i];
                entradas_ordenadas[i] = entradas_ordenadas[j];
                entradas_ordenadas[j] = temp;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("%d\n", entradas_ordenadas[i]);
    }

    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%d\n", entradas[i]);
    }

    return 0;
}