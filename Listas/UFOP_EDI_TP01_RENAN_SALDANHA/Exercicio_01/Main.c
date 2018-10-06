#include "Fila.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  tFila fila;
  tipoItem x, y, z;

  fazFilaVazia(&fila);
  if (filaVazia(fila)){
    printf("Fila vazia");
  }
  x = 3;
  enfilera(&fila, x);
  y = 2;
  enfilera(&fila, y);
  printf("x = %d, y = %d\n", x, y);
  z = 5;
  furaFila(&fila, z);
  imprimeFila(fila);
  desenfilera(&fila, &y);
  desenfilera(&fila, &x);
  printf("x = %d, y = %d\nResto da fila:", x, y);
  imprimeFila(fila);
  enfilera(&fila, 10);
  enfilera(&fila, 6);
  enfilera(&fila, 7);
  imprimeFila(fila);
  printf("Fureia fila com 8\nNova Fila:\n");
  furaFila(&fila, 8);
  imprimeFila(fila);
  furaFila(&fila, 3);
  printf("Nova Fila:\n");
  imprimeFila(fila);
  furaFila(&fila, 16);
  printf("Nova Fila:\n");
  imprimeFila(fila);

  return 0;
}
