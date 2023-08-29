#include <stdio.h>

int pa(int termo_inicial, int razao, int posicao) {
    return termo_inicial + (posicao - 1) * razao;
}

int main() {
    int termo_inicial, razao, posicao;

    printf("Informe o termo inicial da PA: \n");
    scanf("%d", &termo_inicial);

    printf("Informe a razao da PA: \n");
    scanf("%d", &razao);

    printf("Informe a posicao do termo geral: \n");
    scanf("%d", &posicao);

    printf("O termo geral da PA é: %d\n", pa(termo_inicial, razao, posicao));

    return 0;
}