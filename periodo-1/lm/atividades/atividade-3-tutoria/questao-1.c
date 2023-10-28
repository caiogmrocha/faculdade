#include <stdio.h>
#include <math.h>

int somatorio(int x, int n) {
    return (pow(x, n + 1)) / (x - 1);
}

int polinomio(int x, int n) {
    int resultado = 0;
    
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            resultado = resultado + x + 1;
        }

        resultado = resultado + pow(x, i);
    }

    return resultado;
}

int equacao_verdadeira() {
    for (int x = 1; x < 100000; x++) {
        for (int n = 1; n < 100000; n++) {
            if (somatorio(x, n) != polinomio(x, n)) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    if (equacao_verdadeira()) {
        printf("Pode-se concluir que a equação é verdadeira para inteiros positivos\n");
    } else {
        printf("Pode-se concluir que a equação é falsa para inteiros positivos\n");
    }

    return 0;
}