#include <stdio.h>

int condicao1(int P, int Q) {
    return !P || Q;
}

int condicao2(int P, int Q) {
    return P || (Q && P);
}

int condicao3(int P, int Q) {
    return !Q || P;
}

int main() {
    if (condicao1(1, 1) && condicao1(1, 0) && condicao1(0, 1) && condicao1(0, 0)) {
        printf("A primeira condicao eh uma tautologia\n");
    } else {
        printf("A primeira condicao nao eh uma tautologia\n");
    }

    if (condicao2(1, 1) && condicao2(1, 0) && condicao2(0, 1) && condicao2(0, 0)) {
        printf("A segunda condicao eh uma tautologia\n");
    } else {
        printf("A segunda condicao nao eh uma tautologia\n");
    }

    if (condicao3(1, 1) && condicao3(1, 0) && condicao3(0, 1) && condicao3(0, 0)) {
        printf("A terceira condicao eh uma tautologia\n");
    } else {
        printf("A terceira condicao nao eh uma tautologia\n");
    }

    return 0;
}