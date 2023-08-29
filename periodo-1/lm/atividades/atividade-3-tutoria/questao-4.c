#include <stdio.h>

int equacao_eh_verdadeira() {
    for (int n = 0; n < 100000; n++) {
        if (!(2 * n - 1 == n * n)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    if (equacao_eh_verdadeira()) {
        printf("Pode-se concluir que a equacao eh verdadeira para os numeros naturais\n");
    } else {
        printf("Pode-se concluir que a equacao eh falsa para os numeros naturais\n");
    }

    return 0;
}   