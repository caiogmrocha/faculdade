#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[200];
    double nota;
} aluno;

int sort(const void *a, const void *b) {
    const aluno *aluno_a = (const aluno *) a;
    const aluno *aluno_b = (const aluno *) b;

    if (aluno_a->nota == aluno_b->nota)
        if (aluno_a->matricula > aluno_b->matricula) {
            return 1;
        } else {
            return -1;
        }
    else
        if (aluno_a->nota > aluno_b->nota) {
            return 1;
        } else {
            return -1;
        }
}

int main() {
    int qtd_alunos;

    scanf("%d", &qtd_alunos);

    getchar();

    aluno alunos[qtd_alunos];

    for (int i = 0; i < qtd_alunos; i++) {
        char input[1024];

        fgets(input, sizeof(input), stdin);
    
        char *token;
        
        token = strtok(input, "-");

        alunos[i].matricula = atoi(token);
        
        token = strtok(NULL, "-");

        strcpy(alunos[i].nome, token);
        
        token = strtok(NULL, "-");

        alunos[i].nota = atof(token);
    }

    qsort(alunos, sizeof(alunos) / sizeof(alunos[0]), sizeof(aluno), sort);

    double media_geral;

    for (int i = 0; i < qtd_alunos; i++)
        media_geral += alunos[i].nota;

    media_geral = media_geral / qtd_alunos;

    aluno alunos_abaixo[qtd_alunos];
    aluno alunos_acima[qtd_alunos];
    int counter_alunos_abaixo = 0, counter_alunos_acima = 0;

    for (int i = 0 ; i < qtd_alunos; i++) {
        if (alunos[i].nota < media_geral) {
            alunos_abaixo[counter_alunos_abaixo] = alunos[i];
            counter_alunos_abaixo++;
        } else {
            alunos_acima[counter_alunos_acima] = alunos[i];
            counter_alunos_acima++;
        }
    }


    printf("Alunos abaixo da media:\n");

    for (int i = 0; i < counter_alunos_abaixo; i++) {
        printf("Matricula: %d Nome: %s Nota: %.1lf\n", alunos_abaixo[i].matricula, alunos_abaixo[i].nome, alunos_abaixo[i].nota);
    }

    printf("Alunos iguais ou acima da media:\n");
    
    for (int i = 0; i < counter_alunos_acima; i++) {
        printf("Matricula: %d Nome: %s Nota: %.1lf\n", alunos_acima[i].matricula, alunos_acima[i].nome, alunos_acima[i].nota);
    }

    printf("Media = %.2lf\n", media_geral);

    return 0;
}