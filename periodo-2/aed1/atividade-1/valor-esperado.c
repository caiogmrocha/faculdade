#include <stdio.h>

double expectedValue(int n);

int main() {
    int n;

    scanf("%d", &n);

    printf("%.2lf\n", expectedValue(n));

    return 0;
}

double expectedValue(int n) {
    int sumOfNumeratorsOfFractions = 0;
    
    for (int x = 1; x <= n; x++) {
        int sumOfValuesFromOneToX = 0;

        for (int i = 1; i <= x; i++) {
            sumOfValuesFromOneToX += i;
        }

        sumOfNumeratorsOfFractions += sumOfValuesFromOneToX;
    }

    double ev = 0;

    for (int x = 1; x <= n; x++) {
        int sumOfValuesFromOneToX = 0;

        for (int i = 1; i <= x; i++) {
            sumOfValuesFromOneToX += i;
        }


        ev += (sumOfValuesFromOneToX / (double) sumOfNumeratorsOfFractions) * x;
    }

    return ev;
}