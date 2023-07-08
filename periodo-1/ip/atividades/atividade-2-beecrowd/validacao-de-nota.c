#include <stdio.h>

int main() {
    double valores[2];
    int i = 0;

    while (1) {
        if (i >= 2) {
            break;
        }

        scanf("%lf", &valores[i]);

        if (valores[i] < 0 || valores[i] > 10) {
            printf("nota invalida\n");
        } else if (i < 2) {
            i++;
        }
    }

    printf("media = %.2lf\n", (double) (valores[0] + valores[1]) / 2);

    return 0;
}