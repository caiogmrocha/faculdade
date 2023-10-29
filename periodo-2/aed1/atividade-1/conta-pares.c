#include <stdio.h>
#include <math.h>

int ContaDigitosPares(int numero);

int main() {
    int numero;

    scanf("%d", &numero);

    int digitos = ContaDigitosPares(numero);

    printf("%d\n", digitos);

    return 0;
}

int ContaDigitosPares(int numero) {
    if (numero == 0) {
        return 0;
    }
    
    int digito = numero % 10;

    if (digito % 2 == 0)
        return 1 + ContaDigitosPares(numero / 10);
    else
        return ContaDigitosPares(numero / 10);    
}