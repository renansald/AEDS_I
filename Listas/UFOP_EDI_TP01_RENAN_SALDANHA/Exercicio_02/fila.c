#include "fila.h"
#include <stdio.h>

void fazFilaVazia(tFila *fila){
  fila->frente = 1;
  fila->tras = 1;
}

int filaVazia(tFila fila){
  return fila.frente == fila.tras;
}

void enfilera(tFila *fila, tipoItem x){
  if(((fila->tras % max) + 1) == (fila->frente)){
    printf("Fila cheia\n");
    return;
  }
  /*if((fila->tras == max) && (fila->frente == fila->tras-1)){
    fila->tras = fila->frente = 1;
    fila->c[fila->tras - 1].item = x;
    fila->tras = fila ->tras + 1;
    return;
  }*/
  if((fila->tras == max) && (fila->frente !=1)){
    tipoItem aux1;
    int aux = 0;
    apontador auxFrente = fila->frente;
    while (auxFrente != fila->tras){
      aux1 = fila->c[auxFrente-1].item;
      fila->c[aux].item = aux1;
      auxFrente = auxFrente + 1;
      aux++;
    }
    fila->tras = ((max + 1) - (fila->frente));
    fila->frente = 1;
  }
  fila->c[fila->tras-1].item = x;
  fila->tras = fila->tras + 1;
}

void desenfilera(tFila *fila, tipoItem *x){
  if(filaVazia(*fila)){
    printf("Fila vazia\n");
    return;
  }
  *x = fila->c[fila->frente-1].item;
  fila->frente = fila->frente + 1;
}

void imprimeFila(tFila fila){
  if(filaVazia(fila)){
    printf ("Fila vazia\n");
    return;
  }
  apontador aux = fila.frente;
  while (aux != (fila.tras)){
    printf("%d\n", fila.c[aux-1].item);
    aux = aux + 1;
  }
}
