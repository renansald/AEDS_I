#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  tipoItem x, y, z;
  tLista lista, lista2, lista3, lista4;
  x = 1;
  y = 2;
  z = 3;
  fazLista(&lista);
  fazLista(&lista2);
  fazLista(&lista3);
  fazLista(&lista4);
  printf("Imprime lista vazia\n");
  if(ehVazia(lista))
  printf("Lista vazia\n");
  add(&lista, x);
  add(&lista, y);
  add(&lista, z);
  add(&lista, z+1);
  add(&lista, z+2);
  add(&lista, z+3);
  add(&lista, z+4);
  add(&lista, z+5);
  add(&lista, z+6);
  //add(&lista, z+7);
  printf("Imprime lista\n");
  imprime(lista);
  listaA(&lista2, lista);
  printf("Imprime lista2\n");
  imprime(lista2);
  listaB(&lista3, lista);
  printf("Imprime lista3\n");
  imprime(lista3);
  listaC(&lista4, lista);
  printf("Imprime lista4\n");
  imprime(lista4);
  removes(&lista, &z);
  printf("Item z\n");
  printf("%d\n", z);
  printf("Lista\n");
  imprime(lista);
  return 0;
}
