#include <stdio.h>

int main() {
    int valor_atual, maior_valor = 0, posicao_maior;

    for (int i = 0; i < 100; i++) {
        scanf("%d", &valor_atual);

        if (valor_atual > maior_valor) {
            maior_valor = valor_atual;
            posicao_maior = i + 1;
        }
    }

    printf("%d\n", maior_valor);
    printf("%d\n", posicao_maior);

    return 0;
}