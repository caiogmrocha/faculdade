#include <stdio.h>

int main() {
    int a;

    scanf("%d", &a);

    if (a % 2 == 0) {
        printf("O numero %d eh par", a);
    } else {
        printf("O numero %d eh impar", a);
    }

    return 0;
}