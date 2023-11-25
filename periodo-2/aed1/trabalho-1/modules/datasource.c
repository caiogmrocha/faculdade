#include "datasource.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int INITIAL_CAPACITY = 10;
ListaLivros lista;

void inserir_inicio(Livro dados) {
  lista.qtd++;

  if (lista.qtd > INITIAL_CAPACITY) {
    lista.livros = (Livro *)realloc(lista.livros, (lista.qtd) * sizeof(Livro));
  }

  for (int i = lista.qtd - 1; i >= 0 ; i--) {
    lista.livros[i] = lista.livros[i - 1];
  }

  lista.livros[0] = dados;
}

void inserir_fim(Livro dados) {
  lista.qtd++;

  if (lista.qtd > INITIAL_CAPACITY) {
    lista.livros = (Livro *)realloc(lista.livros, (lista.qtd) * sizeof(Livro));
  }

  lista.livros[lista.qtd - 1] = dados;
}

void inserir_posicao(Livro dados, int posicao) {
  lista.qtd++;
  
  if (lista.qtd > INITIAL_CAPACITY) {
    lista.livros = (Livro *)realloc(lista.livros, (lista.qtd) * sizeof(Livro));
  }

  for (int i = 0; i < lista.qtd; i++) {
    if (i == posicao) {
      for (int j = lista.qtd - 1; j >= posicao + 1; j--) {
        lista.livros[j] = lista.livros[j - 1];
      }

      lista.livros[posicao] = dados;

      break;
    }
  }
}

void remover(int id) {
  for (int i = 0; i < lista.qtd; i++) {
    if (lista.livros[i].id == id) {
      for (int j = i; j < lista.qtd - 1; j++) {
        lista.livros[j] = lista.livros[j + 1];
      }

      lista.qtd--;
      lista.livros = (Livro *)realloc(lista.livros, (lista.qtd) * sizeof(Livro));

      break;
    }
  }
}

void listar_disponiveis(Livro **livros, int *qtd) {
  *qtd = 0;

  for (int i = 0; i < lista.qtd; i++) {
    if (lista.livros[i].status == DISPONIVEL) {
      *qtd += 1;

      *livros = (Livro *)realloc(*livros, (*qtd) * sizeof(Livro));

      (*livros)[(*qtd) - 1] = lista.livros[i];
    }
  }
}

void listar_emprestados(Livro **livros, int *qtd) {
  *qtd = 0;

  for (int i = 0; i < lista.qtd; i++) {
    if (lista.livros[i].status == EMPRESTADO) {
      *qtd += 1;

      *livros = (Livro *)realloc(*livros, (*qtd) * sizeof(Livro));

      (*livros)[(*qtd) - 1] = lista.livros[i];
    }
  }
}

void listar_por_editora(Livro **livros, char *editora, int* qtd) {
  *qtd = 0;

  for (int i = 0; i < lista.qtd; i++) {
    if (strcmp(lista.livros[i].editora, editora) == 0) {
      *qtd += 1;

      *livros = (Livro *)realloc(*livros, (*qtd) * sizeof(Livro));

      (*livros)[(*qtd) - 1] = lista.livros[i];
    }
  }
}

void buscar_por_id(int id, Livro *dest) {
  for (int i = 0; i < lista.qtd; i++) {
    if (lista.livros[i].id == id) {
      *dest = lista.livros[i];
    }
  }
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
    fprintf(
      file,
      "%d;%s;%s;%d;%s;%d\n",
      lista.livros[i].id,
      lista.livros[i].titulo,
      lista.livros[i].descricao,
      lista.livros[i].status,
      lista.livros[i].editora,
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
  int status;

  livro.status = status;

  while (
    fscanf(
      file,
      "%d;%100[^;];%100[^;];%d;%50[^;];%d\n\r",
      &livro.id,
      livro.titulo,
      livro.descricao,
      &status,
      livro.editora,
      &livro.ano
    ) > 0
  ) {
    lista.qtd++;
    lista.livros = (Livro *)realloc(lista.livros, lista.qtd * sizeof(Livro));
    lista.livros[lista.qtd - 1] = livro;
  }
}