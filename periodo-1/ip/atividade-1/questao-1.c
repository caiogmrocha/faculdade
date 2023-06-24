#include <stdio.h>

int main() {
    int a, eh_primo = 1;

    printf("Digite o numero: \n");
    scanf("%d", &a);

    for (int i = 2; i < a; i++) {
        if (a % i == 0) {
            eh_primo = 0;
            break;
        }
    }

    if (eh_primo == 1) {
        printf("O numero %d eh primo: ", a);
    } else {
        printf("O numero %d nao eh primo: ", a);
    }

    return 0;
}