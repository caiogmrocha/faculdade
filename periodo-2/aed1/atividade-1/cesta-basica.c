#include <stdio.h>

int main() {
    double basketProductsPrices[27] = {
        5.50, 6.00, 7.50, 1.99, 4.00, 6.70, 1.20, 2.80,
        5.30, 5.00, 3.00, 2.00, 3.50, 0.80, 1.00, 0.80,
        5.40, 1.90, 5.00, 10.00, 0.50, 0.50, 5.00, 4.50,
        1.99, 2.90, 0.30
    };
    int basketEachProductAmounts[27];
    double receipt;

    for (int i = 0; i < 27; i++) {
        if (i == 26)
            scanf("%d", &basketEachProductAmounts[i]);
        else
            scanf("%d,", &basketEachProductAmounts[i]);
    }

    scanf("%lf", &receipt);
    
    // calc
    double totalBasketPrice = 0;

    for (int i = 0; i < 27; i++) {
        totalBasketPrice += basketProductsPrices[i] * basketEachProductAmounts[i];    
    }
    
    int totalBaskets = 0;

    while (receipt - totalBasketPrice > 0) {
        receipt -= totalBasketPrice;
        totalBaskets++;
    }

    printf("O valor da cesta básica ficou em: R$%.2lf\n", totalBasketPrice);
    printf("Com o valor doado pode ser comprada %d cestas básicas", totalBaskets);

    return 0;
}