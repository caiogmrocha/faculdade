#include <stdio.h>

int main() {
    int odds[5], evens[5], oddc = 0, evenc = 0;

    for (int i = 0; i < 15; i++) {
        int value;

        scanf("%d", &value);

        if (value % 2 != 0) {
            odds[oddc] = value;
            oddc++;

            if (oddc == 5) {
                for (int j = 0; j < oddc; j++) {
                    printf("impar[%d] = %d\n", j, odds[j]);
                }

                oddc = 0;
            }
        } else {
            evens[evenc] = value;
            evenc++;

            if (evenc == 5) {
                for (int j = 0; j < evenc; j++) {
                    printf("par[%d] = %d\n", j, evens[j]);
                }

                evenc = 0;
            }
        }
    }

    for (int j = 0; j < oddc; j++) {
        printf("impar[%d] = %d\n", j, odds[j]);
    }

    for (int j = 0; j < evenc; j++) {
        printf("par[%d] = %d\n", j, evens[j]);
    }
    
    return 0;
}