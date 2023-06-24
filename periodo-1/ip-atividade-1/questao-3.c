#include <stdio.h>

int main() {
    int ano;

    printf("Digite o ano a ser considerado: \n");
    scanf("%d", &ano);
    
    if ((ano % 4 == 0) && (ano % 100 != 0)) {
        printf("O ano %d eh um ano bissexto", ano);
    } else if ((ano % 4 == 0) && (ano % 100 == 0) && (ano % 400 == 0)) {
        printf("O ano %d eh um ano bissexto", ano);
    } else {
        printf("O ano %d nao eh um ano bissexto");
    }

    return 0;
}