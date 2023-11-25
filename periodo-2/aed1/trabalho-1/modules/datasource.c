#include "datasource.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ListaLivros lista;

void inserir_inicio(Livro dados) {
  lista.qtd++;
  lista.livros = (Livro *)realloc(lista.livros, (lista.qtd) * sizeof(Livro));

  for (int i = lista.qtd - 1; i >= 0 ; i--) {
    lista.livros[i] = lista.livros[i - 1];
  }

  lista.livros[0] = dados;
}

void inserir_fim(Livro dados) {
  lista.qtd++;
  lista.livros = (Livro *)realloc(lista.livros, (lista.qtd) * sizeof(Livro));

  lista.livros[lista.qtd - 1] = dados;
}

void inserir_posicao(Livro dados, int posicao) {
  lista.qtd++;
  lista.livros = (Livro *)realloc(lista.livros, (lista.qtd) * sizeof(Livro));

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