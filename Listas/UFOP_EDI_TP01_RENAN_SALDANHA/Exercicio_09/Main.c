#include "listaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  tLista lista;
  Item x, y, z;
  fazLista(&lista);
  printf("imprime se a lista é vazia\n");
  if (ehVazia(lista)) {
    printf("Lista vazia\n");
  }
  add(&lista, 6);
  add(&lista, 6);
  add(&lista, 7);
  add(&lista, 8);
  add(&lista, 3);
  add(&lista, 4);
  add(&lista, 5);
  add(&lista, 10);
  add(&lista, 11);
  add(&lista, 12);
  add(&lista, 12);
  printf("Imprime a lista\n");
  imprime(lista);
  removePar(&lista);
  printf("imprime lista nova\n");
  imprime(lista);
  return 0;
}
