#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/datasource.h"
#include "modules/presenter.h"

void gracefull_shutdown() {
  free(lista.livros);
}

int main(void) {
  atexit(gracefull_shutdown);

  lista.qtd = 0;
  lista.livros = NULL;

  Livro novo_livro;

  novo_livro.id = 1;
  strcpy(novo_livro.titulo, "Titulo 1");
  strcpy(novo_livro.descricao, "Descrição 1");
  strcpy(novo_livro.editora, "Editora 3");
  novo_livro.status = DISPONIVEL;
  novo_livro.ano = 2023;

  inserir_fim(novo_livro);
  inserir_fim(novo_livro);
  inserir_fim(novo_livro);
  inserir_fim(novo_livro);
  inserir_fim(novo_livro);

  listar_disponiveis();

  tela_inicial();

  escolher_tela();

  free(lista.livros);

  return 0;
}