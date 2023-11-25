#include "modules/datasource.h"
#include "modules/presenter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gracefull_shutdown() {
  persist_database();
  free(lista.livros);
  exit(0);
}

int main(void) {
  atexit(gracefull_shutdown);

  printf("capacidade inicial: %d\n", INITIAL_CAPACITY);

  lista.livros = (Livro *) malloc(INITIAL_CAPACITY * sizeof(Livro));

  lista.qtd = 0;
  lista.livros = NULL;

  load_database();

  tela_inicial();
  escolher_tela();

  return 0;
}