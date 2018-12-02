#include "questao_12.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  tLista lista, lista2, lista3, lista4;
  fazLista(&lista);
  fazLista(&lista2);
  fazLista(&lista3);
  fazLista(&lista4);
  printf("imprime se é vazia\n");
  if(ehVaziaL(lista))
  printf("Lista vazia\n");
  if(ehVaziaL(lista2))
  printf("Lista vazia\n");
  add(&lista, 'A');
  add(&lista, '1');
  add(&lista, 'E');
  add(&lista, '5');
  add(&lista, 'T');
  add(&lista, '7');
  add(&lista, 'W');
  add(&lista, '8');
  add(&lista, 'G');
  imprime(lista);
  reorganiza(&lista2, lista);
  printf("\n\n");
  imprime(lista2);
  add(&lista3, '3');
  add(&lista3, 'C');
  add(&lista3, '9');
  add(&lista3, 'H');
  add(&lista3, '4');
  add(&lista3, 'Q');
  add(&lista3, '6');
  imprime(lista3);
  reorganiza(&lista4, lista3);
  imprime(lista4);
  return 0;
}
