#include <tgmath.h>
#include <stdio.h>

int main() {
    double valor;
    int quantidade;
    int notas[6] = {100,50,20,10,5,2};
    double moedas[6] = {1,0.50,0.25,0.10,0.05,0.01};

    scanf("%lf", &valor);

    printf("NOTAS:\n");

    for (int i = 0; i < 6; i++) {
        quantidade = (int) (valor / notas[i]);

        printf("%d nota(s) de R$ %.2f\n", quantidade, (float) notas[i]);

        valor = fmod(valor, notas[i]);
    }

    printf("MOEDAS:\n");

    for (int i = 0; i < 6; i++) {
        quantidade = (int) (valor / moedas[i]);

        printf("%d moeda(s) de R$ %.2lf\n", quantidade, moedas[i]);

        valor = fmod(valor, moedas[i]);
        // printf("%f\n", valor);
    }

    return 0;
}