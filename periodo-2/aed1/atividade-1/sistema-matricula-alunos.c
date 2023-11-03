#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char codigo[30];
    char nome[500];
    int idade;
    int sexo;
    double nota;
} aluno;

typedef struct {
    char codigo[25];
    char nome[100];
} disciplina;

typedef struct {
    char codigo_aluno[30];
    char codigo_disciplinas[25];
} matricula;

int comparar_disciplinas(const void *a, const void *b) {
    const disciplina *disciplina_a = (const disciplina *) a; 
    const disciplina *disciplina_b = (const disciplina *) b;

    if (strcmp(disciplina_a->nome, disciplina_b->nome) != 0) {
        return strcmp(disciplina_a->nome, disciplina_b->nome);
    } else {
        return strcmp(disciplina_a->codigo, disciplina_b->codigo);
    }
}

int comparar_alunos(const void *a, const void *b) {
    const aluno *aluno_a = (const aluno *) a; 
    const aluno *aluno_b = (const aluno *) b;

    if (strcmp(aluno_a->nome, aluno_b->nome) != 0) {
        return strcmp(aluno_a->nome, aluno_b->nome);
    } else {
        return strcmp(aluno_a->codigo, aluno_b->codigo);
    }
}


int main() {
    // Input
    int qtd_alunos, qtd_disciplinas, qtd_matriculas;

    scanf("%d", &qtd_alunos);

    aluno alunos[qtd_alunos];

    for (int i = 0; i < qtd_alunos; i++) {
        scanf("%s", alunos[i].codigo);
        getchar();
        scanf("%[^\n]", alunos[i].nome);
        scanf("%d", &alunos[i].idade);
        scanf("%d", &alunos[i].sexo);
        scanf("%lf", &alunos[i].nota);
    }

    scanf("%d", &qtd_disciplinas);

    disciplina disciplinas[qtd_disciplinas];

    for (int i = 0; i < qtd_disciplinas; i++) {
        scanf("%s", disciplinas[i].codigo);
        getchar();
        scanf("%[^\n]", disciplinas[i].nome);
        getchar();
    }

    scanf("%d", &qtd_matriculas);

    matricula matriculas[qtd_matriculas];

    for (int i = 0; i < qtd_matriculas; i++) {
        scanf("%s %s", matriculas[i].codigo_aluno, matriculas[i].codigo_disciplinas);
        getchar();
    }

    // Process
    int qtd_masculino = 0, qtd_feminino = 0;
    double media_idade_alunos = 0, media_idade_por_nota_alunos = 0, qtd_idade_por_nota_alunos;

    for (int i = 0; i < qtd_alunos; i++) {
        if (alunos[i].sexo == 0)
            qtd_masculino++;
        else
            qtd_feminino++;

        media_idade_alunos += alunos[i].idade;

        if (alunos[i].nota > 7.5) {
            media_idade_por_nota_alunos += alunos[i].idade;
            qtd_idade_por_nota_alunos++;
        }
    }

    media_idade_alunos = media_idade_alunos / qtd_alunos;
    media_idade_por_nota_alunos = media_idade_por_nota_alunos / qtd_idade_por_nota_alunos;

    qsort(disciplinas, qtd_disciplinas, sizeof(disciplina), comparar_disciplinas);
    qsort(alunos, qtd_alunos, sizeof(aluno), comparar_alunos);

    int qtd_matriculados[qtd_disciplinas];

    for (int i = 0; i < qtd_disciplinas; i++)
        qtd_matriculados[i] = 0;

    for (int i = 0; i < qtd_disciplinas; i++)
        for (int j = 0; j < qtd_matriculas; j++)
            if (strcmp(disciplinas[i].codigo, matriculas[j].codigo_disciplinas) == 0)
                for (int k = 0; k < qtd_alunos; k++)
                    if (strcmp(alunos[k].codigo, matriculas[j].codigo_aluno) == 0)
                            qtd_matriculados[i]++;

    // Output
    printf("%d\n", qtd_masculino);
    printf("%d\n", qtd_feminino);
    printf("%.2lf\n", media_idade_alunos);
    printf("%.2lf\n", media_idade_por_nota_alunos);

    for (int i = 0; i < qtd_disciplinas; i++) {
        printf("%s\n", disciplinas[i].nome);
        printf("%d\n", qtd_matriculados[i]);

        aluno *alunos_matriculados = NULL;
        int c = 0;

        for (int j = 0; j < qtd_matriculas; j++) {
            if (strcmp(disciplinas[i].codigo, matriculas[j].codigo_disciplinas) == 0) {
                for (int k = 0; k < qtd_alunos; k++) {
                    if (strcmp(alunos[k].codigo, matriculas[j].codigo_aluno) == 0) {
                        c++;

                        alunos_matriculados = realloc(alunos_matriculados, c * sizeof(aluno));

                        memcpy(&alunos_matriculados[c - 1], &alunos[k], sizeof(aluno));
                    }
                }
            }
        }

        qsort(alunos_matriculados, c, sizeof(aluno), comparar_alunos);

        if (alunos_matriculados != NULL) {
            for (int k = 0; k < c; k++) {
                printf("%s\n", alunos_matriculados[k].nome);
            }

            free(alunos_matriculados);
        }
    }

    return 0;
}