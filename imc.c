#include <stdio.h>
#include <math.h>

int main() {
    float weight, height;

    printf("Digite o seu peso: ");
    scanf("%f", &weight);

    printf("\nDigite o sua altura: ");
    scanf("%f", &height);

    float imc = weight / pow(height, 2);
    
    if (imc <= 16.9) {
        printf("\nMuito abaixo do peso");
    } else if (imc <= 18.4) {
        printf("\nAbaixo do peso");
    } else if (imc <= 24.9) {
        printf("\nPeso normal");
    } else if (imc <= 29.9) {
        printf("\n Acima do peso");
    } else if (imc <= 34.9) {
        printf("\nObesidade grau I");
    } else if (imc <= 40) {
        printf("\nObesidade grau II");
    } else {
        printf("\nObesidade grau III");
    }

    return 0;
}