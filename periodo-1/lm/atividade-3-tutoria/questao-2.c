#include <stdio.h>
#include <math.h>

int main() {
    float numero = 0;
    
    for(int contador = 1; contador <= 5; contador++){
        scanf("%f", &numero);

        if(
            (numero < 5.0)
            && (2 * numero < 10.7)
            || sqrt(5.0 * numero) > 5.1
        ) {
            printf("%.1f ", numero);
        }
    }
}