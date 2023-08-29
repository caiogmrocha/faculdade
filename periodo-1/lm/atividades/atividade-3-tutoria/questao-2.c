#include <stdio.h>

int sempre_eh_impar() {
    for (int i = 0; i < 100000; i++) {
        if ((i * i) % 2 == 0 && i % 2 == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    if (sempre_eh_impar()) {
        printf("Pode-se concluir que o quadrado de um numero impar nem sempre é impar\n");
    } else {
        printf("Pode-se concluir que o quadrado de um numero impar também é impar\n");
    }

    return 0;
}