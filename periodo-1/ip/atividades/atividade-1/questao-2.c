#include <math.h>
#include <stdio.h>

int main() {
    unsigned int a, b, resultado;
    
    printf("Digite o primeiro número: \n");
    scanf("%d", &a);
    
    printf("Digite o segundo número: \n");
    scanf("%d", &b);

    resultado = pow(a + b, 3) - (pow(a, 3) + pow(b, 3));

    printf("%d", resultado);

    return 0;
}