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

  tela_inicial();
  escolher_tela();

  return 0;
}