    #include <stdio.h>

    int main() {
        int a, j = 0;

        for (int i = 0; i < 7; i++) {
            scanf("%d", &a);

            if (a % 13 == 0) {
                j++;
            }
        }

        printf("%d numeros sao multiplos de 13", j);

        return 0;
    }