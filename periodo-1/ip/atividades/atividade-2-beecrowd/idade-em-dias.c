#include <stdio.h>

int main() {
    int dias, meses, anos;

    scanf("%d", &dias);

    anos = dias / 365;
    meses = (dias % 365) / 30;
    dias = ((dias % 365) % 30);

    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias);

    return 0;
}