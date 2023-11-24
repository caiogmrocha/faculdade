#include "modules/datasource.h"
#include "modules/presenter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void persist_database();
void load_database();

void gracefull_shutdown() {
  persist_database();
  free(lista.livros);
  exit(0);
}

int main(void) {
  atexit(gracefull_shutdown);

  lista.qtd = 0;
  lista.livros = NULL;

  load_database();

  tela_inicial();
  escolher_tela();

  return 0;
}

void persist_database() {
  FILE *file = fopen("database.txt", "w");

  int id;
  char titulo[100];
  char descricao[100];
  enum StatusLivro status;
  char editora[50];
  int ano;

  for (int i = 0; i < lista.qtd; i++) {
    fprintf(file, "%d;%s;%s;%d;%s;%d\n", lista.livros[i].id,
            lista.livros[i].titulo, lista.livros[i].descricao,
            lista.livros[i].status, lista.livros[i].editora,
            lista.livros[i].ano);
  }

  fclose(file);
}

void load_database() {
  FILE *file = fopen("database.txt", "r");

  if (file == NULL)
    return;

  lista.qtd = 0;

  Livro livro;

  while (fscanf(file, "%d;%100[^;];%100[^;];%d;%50[^;];%d\n\r", &livro.id,
                livro.titulo, livro.descricao, &livro.status, livro.editora,
                &livro.ano) > 0) {
    lista.qtd++;
    lista.livros = (Livro *)realloc(lista.livros, lista.qtd * sizeof(Livro));
    lista.livros[lista.qtd - 1] = livro;
  }
}