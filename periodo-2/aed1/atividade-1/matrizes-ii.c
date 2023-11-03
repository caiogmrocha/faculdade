#include <stdio.h>

int main() {
    int menor_valor;
    int valor_delta = 0;
    int soma_positivos = 0;
    int qtd_positivos = 0;
    int soma_exceto_diagonal = 0;
    double media_positivos = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            int v;

            scanf("%d", &v);

            // menor valor
            if ((i == 0 && j == 0) || menor_valor > v)
                menor_valor = v;

            // soma exceto diagonal
            if (i != j)
                soma_exceto_diagonal += v;

            // soma positivos
            if (v > 0) {
                soma_positivos += v;
                qtd_positivos++;
            }
        }

    // valor delta
    if (menor_valor % 2 == 0)
        valor_delta = 1;
    else
        valor_delta = 0;

    // media positivos
    media_positivos = (double) soma_positivos / qtd_positivos;

    printf("%.2lf %d %d %d\n", media_positivos, menor_valor, valor_delta, soma_exceto_diagonal);

    return 0;
}