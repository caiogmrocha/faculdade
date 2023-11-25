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
extern const int INITIAL_CAPACITY;

/**
 * Insere um livro no inicio da lista
 * 
 * @param dados Livro a ser inserido
 * 
 * @return void
 */
void inserir_inicio(Livro dados);

/**
 * Insere um livro no fim da lista
 * 
 * @param dados Livro a ser inserido
 * 
 * @return void
*/
void inserir_fim(Livro dados);

/**
 * Insere um livro em uma posicao especifica da lista
 * 
 * @param dados Livro a ser inserido
 * @param posicao Posicao a ser inserido o livro
 * 
 * @return void
*/
void inserir_posicao(Livro dados, int posicao);

/**
 * Remove um livro da lista
 * 
 * @param id Id do livro a ser removido
 * 
 * @return void
*/
void remover(int id);

/**
 * Lista todos os livros da lista
 * 
 * @param livros Lista de livros
 * @param qtd Quantidade de livros
 * 
 * @return void
*/
void listar_disponiveis(Livro** livros, int* qtd);

/**
 * Lista todos os livros emprestados da lista
 * 
 * @param livros Lista de livros
 * @param qtd Quantidade de livros
 * 
 * @return void
*/
void listar_emprestados(Livro** livros, int* qtd);

/**
 * Lista todos os livros por editora
 * 
 * @param livros Lista de livros
 * @param editora Editora a ser buscada
 * @param qtd Quantidade de livros
 * 
 * @return void
*/
void listar_por_editora(Livro** livros, char* editora, int* qtd);

/**
 * Busca um livro por id
 * 
 * @param id Id do livro a ser buscado
 * @param dest Livro de destino
 * 
 * @return void
*/
void buscar_por_id(int id, Livro *dest);

/**
 * Persiste os dados da lista em um arquivo
 * 
 * @return void
*/
void persist_database();

/**
 * Carrega os dados da lista de um arquivo
 * 
 * @return void
*/
void load_database();

#endif