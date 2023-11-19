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

        // case 2: {

        // } break;

        // case 3: {

        // } break;

        // case 4: {

        // } break;

        // case 5: {

        // } break;

        // case 6: {

        // } break;

        case 7: system("clear"); tela_inicial(); break;

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
    printf("2 - Listar livros emprestados\n");
    printf("2 - Listar livros por editora\n");
    printf("2 - Cadastrar um novo livro\n");
    printf("2 - Excluir um livro existente\n");
    printf("3 - Detalhes de um produto cadastrado\n");
    printf("7 - Ir para a home\n\n");
}

void tela_listagem_todos() {
    if (lista.qtd == 0) {
        printf("Não existem livros cadastrados");

        return;
    }

    listar_todos();
}

void tela_listagem_disponiveis();
void tela_listagem_emprestados();
void tela_listagem_por_editora();
void tela_cadastro();
void tela_remocao();
void tela_listar_todos();
void tela_listar_disponiveis();
void tela_listar_emprestados();
void tela_listar_por_editora();
void tela_listar_por_ano();