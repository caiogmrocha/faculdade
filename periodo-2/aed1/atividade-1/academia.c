#include <stdio.h>

typedef struct {
    int idade;
    char nome[50];
    char sexo;
    char estado_civil;
    int qtd_amigos;
    int qtd_fotos;
} usuario;

int main() {
    int qtd_usuarios;

    scanf("%d", &qtd_usuarios);

    usuario usuarios[qtd_usuarios];

    for (int i = 0; i < qtd_usuarios; i++) {
        scanf("%d", &usuarios[i].idade);
        scanf("%s", usuarios[i].nome);
        getchar();
        scanf("%c", &usuarios[i].sexo);
        getchar();
        scanf("%c", &usuarios[i].estado_civil);
        scanf("%d", &usuarios[i].qtd_amigos);
        scanf("%d", &usuarios[i].qtd_fotos);
    }

    for (int i = 0; i < qtd_usuarios; i++) {
        printf("Idade: %d\n", usuarios[i].idade);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Sexo: %c\n", usuarios[i].sexo);
        printf("Estado Civil: %c\n", usuarios[i].estado_civil);
        printf("Numero de amigos: %d\n", usuarios[i].qtd_amigos);
        printf("Numero de fotos: %d\n\n", usuarios[i].qtd_fotos);
    }

    return 0;
}