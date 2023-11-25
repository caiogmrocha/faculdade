#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <stdbool.h>

enum StatusLivro {
  DISPONIVEL,
  EMPRESTADO
};

typedef struct {
  int id;
  char titulo[100];
  char descricao[100];
  enum StatusLivro status;
  char editora[50];
  int ano;
} Livro;

typedef struct {
  Livro *livros;
  int qtd;
} ListaLivros;

extern ListaLivros lista;

void inserir_inicio(Livro dados);
void inserir_fim(Livro dados);
void inserir_posicao(Livro dados, int posicao);

void remover(int id);

void listar_todos();
void listar_disponiveis(Livro** livros, int* qtd);
void listar_emprestados(Livro** livros, int* qtd);
void listar_por_editora(Livro** livros, char* editora, int* qtd);

void buscar_por_id(int id, Livro *dest);

#endif