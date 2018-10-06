#include "fila.h"
#include <stdio.h>

void fazFilaVazia(tFila *fila){
  fila->frente = 1;
  fila->tras = 1;
}

int filaVazia(tFila fila){
  return (fila.frente == fila.tras);
}

void enfilera(tFila *fila, tipoItem y){
  if ((fila->tras % max + 1) == (fila->frente)){
    printf("Fila cheia\n");
    return;
  }
  fila->c[fila->tras - 1].item = y;
  fila->tras = (fila->tras % max) + 1;
}

void desenfilera(tFila *fila, tipoItem *y){
  if (filaVazia(*fila)){
    printf("Fila Vazia");
    return;
  }
  *y = fila->c[fila->frente - 1].item;
  fila->frente = (fila->frente % max) + 1;
}

void imprimeFila(tFila fila){
  if (filaVazia(fila)){
    printf("Fila Vazia\n");
    return;
  }
  apontador aux = fila.frente;
  while(aux != fila.tras){
    printf("%d\n", fila.c[aux-1].item);
    aux = (aux % max) + 1;
  }
}

void furaFila(tFila *fila, tipoItem x){
  if(((fila->tras % max) + 1) == (fila->frente)){
    printf("Fila cheia\n");
    return;
  }
  if(((fila->frente % max) - 1) == 0){
    fila->frente = max;
  }
  else{
    fila->frente = (fila->frente % max) - 1;
  }
  fila->c[fila->frente-1].item = x;
}
