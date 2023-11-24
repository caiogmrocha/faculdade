#include "datasource.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ListaLivros lista;

void inserir_inicio(Livro dados) {
  lista.qtd++;
  lista.livros = (Livro *)realloc(lista.livros, (lista.qtd) * sizeof(Livro));

  for (int i = 1; i < lista.qtd; i++) {
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
      for (int j = posicao + 1; j < lista.qtd; j++) {
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
      for (int j = i; j < lista.qtd; j++) {
        lista.livros[j - 1] = lista.livros[j];

        if (j == lista.qtd - 1) {
          lista.qtd--;
          lista.livros =
              (Livro *)realloc(lista.livros, (lista.qtd) * sizeof(Livro));
        }
      }
    }
  }
}

void listar_disponiveis(Livro **livros) {
  int qtd = 0;

  for (int i = 0; i < lista.qtd; i++) {
    if (lista.livros[i].status == DISPONIVEL) {
      qtd++;

      *livros = (Livro *)realloc((*livros), qtd * sizeof(Livro));

      memcpy(&(*livros)[qtd - 1], &lista.livros[i], sizeof(Livro));

      printf("rapaazzzz");
      printf("%d;%s;%s;%d;%s;%d\n", livros[qtd - 1]->id,
             livros[qtd - 1]->titulo, livros[qtd - 1]->descricao,
             livros[qtd - 1]->status, livros[qtd - 1]->editora,
             livros[qtd - 1]->ano);
    }
  }

  printf("\n");
}

void listar_emprestados(Livro **livros) {
  int qtd = 0;

  for (int i = 0; i < lista.qtd; i++) {
    if (lista.livros[i].status == EMPRESTADO) {
      qtd++;

      *livros = (Livro *)realloc((*livros), qtd * sizeof(Livro));

      memcpy(&(*livros)[qtd - 1], &lista.livros[i], sizeof(Livro));
    }
  }

  printf("\n");
}

void listar_por_editora(Livro **livros, char *editora) {
  int qtd = 0;

  for (int i = 0; i < lista.qtd; i++) {
    if (strcmp(lista.livros[i].editora, editora) == 0) {
      qtd++;

      *livros = (Livro *)realloc((*livros), qtd * sizeof(Livro));

      memcpy(&(*livros)[qtd - 1], &lista.livros[i], sizeof(Livro));
    }
  }
}

Livro buscar_por_id(int id) {
  for (int i = 0; i < lista.qtd; i++) {
    if (lista.livros[i].id == id) {
      return lista.livros[i];
    }
  }
}