#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    if (n == 0) {
        printf("Lista vazia - O valor de S eh zero\n");
        return 0;
    } else if (n < 0) {
        printf("O valor informado para N foi negativo\n");
        return 0;
    }

    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int s = 0;

    for (int i = 0, j = n - 1; (n % 2 == 0 && i < j) || (n % 2 != 0 && i <= j); i++, j--) {
        if (n % 2 != 0 && i == j) {
            s += a[i] * a[i];
        } else {
            s += (a[i] - a[j]) * (a[i] - a[j]);
        }
    }

    printf("S = %d\n", s);

    return 0;
}