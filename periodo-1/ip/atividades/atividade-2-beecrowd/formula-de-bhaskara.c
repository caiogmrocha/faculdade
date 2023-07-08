#include <stdio.h>
#include <math.h>

struct BhaskaraResult {
    int possible;
    double x1;
    double x2;
};

double discriminant_without_sqrt(double a, double b, double c) {
    return pow(b, 2) - (4 * a * c);
}

struct BhaskaraResult bhaskara(double a, double b, double c) {
    struct BhaskaraResult result;

    double discriminant = discriminant_without_sqrt(a, b, c);

    if (a == 0 || discriminant < 0) {
        result.possible = 0;
    } else if (discriminant == 0) {
        double square = -b / (2 * a);
        result.possible = 1;
        result.x1 = square;
        result.x2 = square;
    } else {
        result.possible = 1;
        result.x1 = (-b + sqrt(discriminant)) / (2 * a);
        result.x2 = (-b - sqrt(discriminant)) / (2 * a);
    }

    return result;
}

int main() {
    double a, b, c, x1, x2;

    scanf("%lf %lf %lf", &a, &b, &c);

    struct BhaskaraResult result = bhaskara(a, b, c);

    if (result.possible == 1) {
        printf("R1 = %.5lf\n", result.x1);
        printf("R2 = %.5lf\n", result.x2);
    } else {
        printf("Impossivel calcular\n");
    }

    return 0;
}