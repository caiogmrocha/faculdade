#include <stdio.h>

int main() {
    int hora_inicio, hora_fim;

    scanf("%d %d", &hora_inicio, &hora_fim);

    if (hora_inicio < hora_fim) {
        printf("O JOGO DUROU %d HORA(S)\n", hora_fim - hora_inicio);
    } else {
        printf("O JOGO DUROU %d HORA(S)\n", (hora_fim + 24) - hora_inicio);
    }

    return 0;
}