#include <stdio.h>
#include <stdlib.h>
#include "datasource.h"
#include "presenter.h"

void escolher_tela() {
    printf("Selecione uma tela: ");

    int tela_selecionada;

    scanf("%d", &tela_selecionada);

    switch(tela_selecionada) {
        case 1: system("clear"); listar_todos(lista); break;

        case 2: system("clear"); tela_listagem_disponiveis(); break;

        case 3: system("clear"); tela_listagem_emprestados(); break;

        case 4: system("clear"); tela_listagem_por_editora(); break;

        // case 5: {

        // } break;

        // case 6: {

        // } break;

        // case 7: {

        // } break;

        case 8: system("clear"); tela_inicial(); break;

        default: printf("Opção indisponível\n");
    }

    escolher_tela();
}

void tela_inicial() {
    printf("###############################\n");
    printf("#                             #\n");
    printf("#        Seja Bem-vindo       #\n");
    printf("#                             #\n");
    printf("#      Gestão de Produtos     #\n");
    printf("#                             #\n");
    printf("###############################\n");
    printf("#                             #\n");
    printf("#     Selecione uma opção     #\n");
    printf("#                             #\n");
    printf("###############################\n\n");
    printf("1 - Listar todos os livros\n");
    printf("2 - Listar livros disponíveis\n");
    printf("3 - Listar livros emprestados\n");
    printf("4 - Listar livros por editora\n");
    printf("5 - Cadastrar um novo livro\n");
    printf("6 - Excluir um livro existente\n");
    printf("7 - Detalhes de um produto cadastrado\n");
    printf("8 - Ir para a home\n\n");
}

void tela_listagem_todos() {
    if (lista.qtd == 0) {
        printf("Não existem livros cadastrados");

        return;
    }

    listar_todos();
}

void tela_listagem_disponiveis() {
    Livro* lista_disponiveis = NULL;
    
    listar_disponiveis(&lista_disponiveis);

    if (lista_disponiveis != NULL) {
        printf("Não existem livros disponiveis\n");

        return;
    }

    printf("ID: %-4s Titulo: %-16s Editora: %-20s\n", " ", " ", " ");

    for (int i = 0; i < sizeof(lista_disponiveis) / sizeof(lista_disponiveis[0]); i++) {
        printf(
            "%-8d %-24s %-23s\n",
            lista_disponiveis[i].id,
            lista_disponiveis[i].titulo,
            lista_disponiveis[i].editora
        );
    }

    free(lista_disponiveis);
}

void tela_listagem_emprestados() {
    Livro* lista_emprestados = NULL;
    
    listar_emprestados(&lista_emprestados);

    if (lista_emprestados != NULL) {
        printf("Não existem livros emprestados\n");

        return;
    }

    printf("ID: %-4s Titulo: %-16s Editora: %-20s\n", " ", " ", " ");

    for (int i = 0; i < sizeof(lista_emprestados) / sizeof(lista_emprestados[0]); i++) {
        printf(
            "%-8d %-24s %-23s\n",
            lista_emprestados[i].id,
            lista_emprestados[i].titulo,
            lista_emprestados[i].editora
        );
    }

    free(lista_emprestados);
}

void tela_listagem_por_editora() {
    char editora[50];

    printf("Digite o nome da editora: \n");
    scanf("%s", editora);

    Livro* lista_por_editora = NULL;
    
    listar_por_editora(&lista_por_editora, editora);

    if (lista_por_editora != NULL) {
        printf("Não existem livros para a editora %s\n", editora);

        return;
    }

    printf("ID: %-4s Titulo: %-16s\n", " ", " ");

    for (int i = 0; i < sizeof(lista_por_editora) / sizeof(lista_por_editora[0]); i++) {
        printf(
            "%-8d %-24s\n",
            lista_por_editora[i].id,
            lista_por_editora[i].titulo
        );
    }

    free(lista_por_editora);
}
void tela_cadastro();
void tela_remocao();
void tela_listar_todos();
void tela_listar_disponiveis();
void tela_listar_emprestados();
void tela_listar_por_editora();
void tela_listar_por_ano();