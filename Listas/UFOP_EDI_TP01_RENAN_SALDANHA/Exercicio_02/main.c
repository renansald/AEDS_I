#include "fila.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  tFila fila;
  tipoItem x, y, z;
  fazFilaVazia(&fila);
  if(filaVazia(fila)){
  printf("Fila Vazia\n");
}
  enfilera(&fila, 9);
  enfilera(&fila, 8);
  enfilera(&fila, 7);
  enfilera(&fila, 6);
  enfilera(&fila, 5);
  enfilera(&fila, 4);
  enfilera(&fila, 3);
  enfilera(&fila, 2);
  imprimeFila(fila);
  desenfilera(&fila, &x);
  desenfilera(&fila, &y);
  desenfilera(&fila, &z);
  printf("%d, %d, %d Nova fila apos desinfelra:\n", x, y, z);
  imprimeFila(fila);
  enfilera(&fila, 11);
  enfilera(&fila, 12);
  printf("Nova fila:\n");
  imprimeFila(fila);
  return 0;
}
