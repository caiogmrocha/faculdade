#include <stdio.h>

int main() {
    int n, d;

    scanf("%d", &n);

    while ((int) n != 0) {
        n /= 10;
        d++;
    }

    printf("%d\n", d);

    return 0;
}