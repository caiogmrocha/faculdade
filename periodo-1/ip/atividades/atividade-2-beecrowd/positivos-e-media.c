#include <stdio.h>
#include <stdlib.h>

int main() {
    double valor, soma_positivos = 0;
    int qtd_positivos = 0;

    for (int i = 0; i < 6; i++) {
        scanf("%lf", &valor);

        if (valor > 0) {
            qtd_positivos++;
            soma_positivos += valor;
        }
    }

    printf("%d valores positivos\n", qtd_positivos);
    printf("%.1lf\n", soma_positivos / qtd_positivos);

    return 0;
}