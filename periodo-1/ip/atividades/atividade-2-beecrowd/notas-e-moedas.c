#include <tgmath.h>
#include <stdio.h>

int main() {
    double valor;
    int quantidade;
    int notas[6] = {10000,5000,2000,1000,500,200};
    int moedas[6] = {100,50,25,10,5,1};

    scanf("%lf", &valor);
    
    valor *= 100;

    printf("NOTAS:\n");

    for (int i = 0; i < 6; i++) {
        quantidade = (int) (valor / notas[i]);

        printf("%d nota(s) de R$ %.2f\n", quantidade, notas[i] / 100.0);

        valor = fmod(valor, notas[i]);
    }

    printf("MOEDAS:\n");

    for (int i = 0; i < 6; i++) {
        quantidade = (int) (valor / moedas[i]);

        printf("%d moeda(s) de R$ %.2lf\n", quantidade, moedas[i] / 100.0);

        valor = fmod(valor, moedas[i]);
    }

    return 0;
}