#include <stdio.h>

int forma_triangulo(double *lados) {
    int result = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if ((lados[i] + lados[j] <= lados[k]) && (i != j && j != k && k != i)) {
                    result = 0;
                }
            }
        }
    }

    return result;
}

double perimetro_triangulo(double a, double b, double c) {
    return (double) (a + b + c);
}

double area_trapezio(double base_menor, double base_maior, double altura) {
    return (base_menor + base_maior) * altura / 2.0;
}

int main() {
    double entradas[3];

    scanf("%lf %lf %lf", &entradas[0], &entradas[1], &entradas[2]);

    int forma = forma_triangulo(entradas);

    if (forma == 1) {
        printf("Perimetro = %.1lf\n", perimetro_triangulo(entradas[0], entradas[1], entradas[2]));
    } else {
        printf("Area = %.1lf\n", area_trapezio(entradas[0], entradas[1], entradas[2]));
    }

    return 0;
}