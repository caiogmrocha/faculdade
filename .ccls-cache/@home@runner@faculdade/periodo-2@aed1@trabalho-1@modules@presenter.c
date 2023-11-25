#include "presenter.h"
#include "datasource.h"
#include <stdio.h>
#include <stdlib.h>

void escolher_tela() {
  printf("Selecione uma tela: ");

  int tela_selecionada;

  scanf("%d", &tela_selecionada);

  switch (tela_selecionada) {
  case 0:
    exit(0);

  case 1:
    system("clear");
    tela_listagem_todos(lista);
    break;

  case 2:
    system("clear");
    tela_listagem_disponiveis();
    break;

  case 3:
    system("clear");
    tela_listagem_emprestados();
    break;

  case 4:
    system("clear");
    tela_listagem_por_editora();
    break;

  case 5:
    system("clear");
    tela_cadastro_inicio();
    break;

  case 6:
    system("clear");
    tela_cadastro_fim();
    break;

  case 7:
    system("clear");
    tela_cadastro_posicao_especifica();
    break;

  case 8:
    system("clear");
    tela_remocao();
    break;

  case 9:
    system("clear");
    tela_visualizar_detalhes();
    break;

  case 10:
    system("clear");
    tela_inicial();
    break;

  default:
    printf("Opção indisponível\n");
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
  printf("5 - Cadastrar um novo livro no inicio da lista\n");
  printf("6 - Cadastrar um novo livro no fim da lista\n");
  printf("7 - Cadastrar um novo livro em uma posicao especifica na lista\n");
  printf("8 - Excluir um livro existente\n");
  printf("9 - Detalhes de um produto cadastrado\n");
  printf("10 - Ir para a home\n\n");
}

void tela_listagem_todos() {
  if (lista.qtd == 0) {
    printf("Não existem livros cadastrados\n\n");

    return;
  }

  printf("ID: %-4s Titulo: %-16s Editora: %-20s\n", " ", " ", " ");

  for (int i = 0; i < lista.qtd; i++) {
    printf("%-8d %-24s %-23s\n", lista.livros[i].id, lista.livros[i].titulo,
           lista.livros[i].editora);
  }

  printf("\n");
}

void tela_listagem_disponiveis() {
  Livro *lista_disponiveis = NULL;

  listar_disponiveis(&lista_disponiveis);

  if (lista_disponiveis == NULL) {
    printf("Não existem livros disponiveis\n\n");

    return;
  }

  printf("ID: %-4s Titulo: %-16s Editora: %-20s\n", " ", " ", " ");

  for (int i = 0; i < sizeof(lista_disponiveis) / sizeof(lista_disponiveis[0]);
       i++) {
    printf("%-8d %-24s %-23s\n", lista_disponiveis[i].id,
           lista_disponiveis[i].titulo, lista_disponiveis[i].editora);
  }

  printf("\n");

  free(lista_disponiveis);
}

void tela_listagem_emprestados() {
  Livro *lista_emprestados = NULL;

  listar_emprestados(&lista_emprestados);

  if (lista_emprestados == NULL) {
    printf("Não existem livros emprestados\n");

    return;
  }

  printf("ID: %-4s Titulo: %-16s Editora: %-20s\n", " ", " ", " ");

  for (int i = 0; i < sizeof(lista_emprestados) / sizeof(lista_emprestados[0]);
       i++) {
    printf("%-8d %-24s %-23s\n", lista_emprestados[i].id,
           lista_emprestados[i].titulo, lista_emprestados[i].editora);
  }

  printf("\n");

  free(lista_emprestados);
}

void tela_listagem_por_editora() {
  char editora[50];

  printf("Digite o nome da editora: \n");
  scanf("%s", editora);

  Livro *lista_por_editora = NULL;

  listar_por_editora(&lista_por_editora, editora);

  if (lista_por_editora == NULL) {
    printf("Não existem livros para a editora %s\n", editora);

    return;
  }

  printf("ID: %-4s Titulo: %-16s\n", " ", " ");

  for (int i = 0; i < sizeof(lista_por_editora) / sizeof(lista_por_editora[0]);
       i++) {
    printf("%-8d %-24s\n", lista_por_editora[i].id,
           lista_por_editora[i].titulo);
  }

  free(lista_por_editora);
}

void tela_cadastro_inicio() {
  Livro livro;

  printf("Digite o titulo: ");
  scanf("%s", livro.titulo);
  getchar();

  printf("Digite a descricao: ");
  scanf("%s", livro.descricao);
  getchar();

  printf("Digite o nome da editora: ");
  scanf("%s", livro.editora);

  printf("Digite o ano de publicacao do livro: ");
  scanf("%d", &livro.ano);

  livro.status = DISPONIVEL;
  livro.id = lista.qtd;

  inserir_inicio(livro);

  printf("Livro cadastrado com sucesso!\n\n");
}

void tela_cadastro_fim() {
  Livro livro;

  printf("Digite o titulo: ");
  scanf("%s", livro.titulo);
  getchar();

  printf("Digite a descricao: ");
  scanf("%s", livro.descricao);
  getchar();

  printf("Digite o nome da editora: ");
  scanf("%s", livro.editora);

  printf("Digite o ano de publicacao do livro: ");
  scanf("%d", &livro.ano);

  livro.status = DISPONIVEL;
  livro.id = lista.qtd;

  inserir_fim(livro);

  printf("Livro cadastrado com sucesso!\n\n");
}

void tela_cadastro_posicao_especifica() {
  Livro livro;

  printf("Digite o titulo: ");
  scanf("%s", livro.titulo);
  getchar();

  printf("Digite a descricao: ");
  scanf("%s", livro.descricao);
  getchar();

  printf("Digite o nome da editora: ");
  scanf("%s", livro.editora);

  printf("Digite o ano de publicacao do livro: ");
  scanf("%d", &livro.ano);

  livro.status = DISPONIVEL;
  livro.id = lista.qtd;

  int posicao;

  printf("Digite a posicao de cadastro do livro: ");
  scanf("%d", &posicao);

  if (posicao < 0) {
    inserir_inicio(livro);
  } else if (posicao >= lista.qtd) {
    inserir_fim(livro);
  } else {
    inserir_posicao(livro, posicao);
  }

  printf("Livro cadastrado com sucesso!\n\n");
}

void tela_remocao() {
  int id;

  printf("Digite o id do livro a ser excluido: ");

  scanf("%d", &id);

  remover(id);

  printf("O livro %d foi removido com sucesso!\n\n", id);
}

void tela_visualizar_detalhes() {
  int id;

  printf("Digite o id do livro a ser visualizado: ");

  scanf("%d", &id);

  Livro livro = buscar_por_id(id);

  printf("ID: %d\n", livro.id);
  printf("Titulo: %s\n", livro.titulo);
  printf("Descricao: %s\n", livro.descricao);
  printf("Editora: %s\n", livro.editora);
  printf("Ano: %d\n", livro.ano);
  printf("Status: %s\n\n",
         livro.status == DISPONIVEL ? "Disponivel" : "Emprestado");
}