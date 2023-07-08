#include <stdio.h>

int main() {
    int x, y;

    scanf("%f %f", &x, &y);

    // estah na origem
    if (x == 0 && y == 0) {
        printf("Origem\n");
    // estah no eixo x
    } else if (x != 0 && y == 0) {
        printf("Eixo X\n");
    // estah no eixo y
    } else if (x == 0 && y != 0) {
        printf("Eixo Y\n");
    // estah em algum dos quadrantes
    } else {
        // estah no q1
        if (x > 0 && y > 0) {
            printf("Q1\n");
        // estah no q2
        } else if (x < 0 && y > 0) {
            printf("Q2\n");
        // estah no q3
        } else if (x < 0 && y < 0) {
            printf("Q3\n");
        // estah no q4
        } else {
            printf("Q4\n");
        }
    }

    return 0;
}