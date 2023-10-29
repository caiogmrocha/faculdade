#include <stdio.h> 

double CalculaMedia(double n1, double n2, double n3, double n4, double n5);

int main() {
    int faltas;
    double n1, n2, n3, n4, n5;

    scanf("%d", &faltas);
    scanf("%lf", &n1);
    scanf("%lf", &n2);
    scanf("%lf", &n3);
    scanf("%lf", &n4);
    scanf("%lf", &n5);

    double media = CalculaMedia(n1, n2, n3, n4, n5);

    if (media >= 7.0 && faltas <= 5)
        printf("APROVADO\n");
    else
        printf("REPROVADO\n");

    return 0;
}

double CalculaMedia(double n1, double n2, double n3, double n4, double n5) {
    return (n1 + n2 + n3 + n4 + n5) / 5;
}