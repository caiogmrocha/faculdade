#include <stdio.h>

int main() {
    int quantidade, soma_divisores = 0;

    scanf("%d", &quantidade);

    long int valor;

    for (int i = 0; i < quantidade; i++) {
        scanf("%d", &valor);

        for (int j = 1; j <= valor; j++) {
            if (valor % j == 0) {
                soma_divisores += j;
            }
        }

        if (soma_divisores == valor + 1) {
            printf("%d eh primo\n", valor);
        } else {
            printf("%d nao eh primo\n", valor);
        }

        soma_divisores = 0;
    }

    return 0;
}