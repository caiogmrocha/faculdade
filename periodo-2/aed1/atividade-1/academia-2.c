#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int senha;
    char situacao[1];
} cliente;

int main() {
    cliente clientes[100];
    int qtd_clientes = 0;

    while (1) {
        char nome[50];

        scanf("%[^\n]", nome);

        if ((strcmp(nome, "SAIR") == 0) || (qtd_clientes == 100)){
            break;
        }

        strcpy(clientes[qtd_clientes].nome, nome);
        scanf("%d", &clientes[qtd_clientes].senha);
        scanf("%s", clientes[qtd_clientes].situacao);
        getchar();

        qtd_clientes++;
    }

    int *senhas;
    int qtd_senhas = 0;
    
    senhas = malloc(sizeof(int));

    while (1) {
        scanf("%d", &senhas[qtd_senhas]);

        if (senhas[qtd_senhas] == -1)
            break;

        for (int i = 0; i < qtd_clientes; i++) {
            if (clientes[i].senha == senhas[qtd_senhas]) {
                if (strcmp(clientes[i].situacao, "P") == 0)
                    printf("%s, seja bem-vindo(a)!\n", clientes[i].nome);
                else
                    printf("Não está esquecendo de algo, %s? Procure a recepção!\n", clientes[i].nome);
                break;
            }

            if (i == qtd_clientes - 1) {
                printf("Seja bem-vindo(a)! Procure a recepção!\n");
            }
        }

        qtd_senhas++;

        senhas = (int *) realloc(senhas, qtd_senhas * sizeof(senhas[qtd_senhas-1]));

        if (senhas[qtd_senhas - 1] == -1)
            break;
    }

    free(senhas);

    return 0;
}