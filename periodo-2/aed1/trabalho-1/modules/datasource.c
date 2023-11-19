#include <stdio.h>
#include <stdlib.h>
#include "datasource.h"

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

bool remover(int id) {
  for (int i = 0; i < lista.qtd; i++) {
    if (lista.livros[i].id == id) {
      for (int j = i; j < lista.qtd; j++) {
          lista.livros[j - 1] = lista.livros[j];
  
          if (j == lista.qtd - 1) {
            lista.qtd--;
            lista.livros = (Livro *)realloc(lista.livros, (lista.qtd) * sizeof(Livro));
          }
      }
    }
  }
}

void listar_todos() {
  printf("ID: %-4s Titulo: %-16s Editora: %-20s\n", " ", " ", " ");

  for (int i = 0; i < lista.qtd; i++) {
    printf(
      "%-8d %-24s %-23s\n",
      lista.livros[i].id,
      lista.livros[i].titulo,
      lista.livros[i].editora
    );
  }
}

void listar_disponiveis() {
  printf("ID: %-4s Titulo: %-16s Editora: %-20s\n", " ", " ", " ");

  for (int i = 0; i < lista.qtd; i++) {
    if (lista.livros[i].status == DISPONIVEL) {
      printf(
        "%-8d %-24s %-23s\n",
        lista.livros[i].id,
        lista.livros[i].titulo,
        lista.livros[i].editora
      );
    }
  }
}

void listar_emprestados() {
  printf("ID: %-4s Titulo: %-16s Editora: %-20s\n", " ", " ", " ");

  for (int i = 0; i < lista.qtd; i++) {
    if (lista.livros[i].status == EMPRESTADO) {
      printf(
        "%-8d %-24s %-23s\n",
        lista.livros[i].id,
        lista.livros[i].titulo,
        lista.livros[i].editora
      );
    }
  }
}

void listar_por_editora(char *editora) {
  printf("ID: %-4s Titulo: %-16s Editora: %-20s\n", " ", " ", " ");

  for (int i = 0; i < lista.qtd; i++) {
    if (lista.livros[i].editora == editora) {
      printf(
        "%-8d %-24s %-23s\n",
        lista.livros[i].id,
        lista.livros[i].titulo,
        lista.livros[i].editora
      );
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