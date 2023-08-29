#include <stdio.h>

int fatorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return fatorial(n - 1) * n;
}

int main() {
    int n;

    printf("Informe um numero inteiro: \n");
    scanf("%d", &n);

    printf("O fatorial de %d eh: %d\n", n, fatorial(n));

    return 0;
}