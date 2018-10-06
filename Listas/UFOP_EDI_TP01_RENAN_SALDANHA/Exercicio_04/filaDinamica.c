#include "filaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

void fazFila(tFila *fila){
  fila->frente = (apontador) malloc (sizeof(celula));
  fila->tras = fila->frente;
  fila->frente->proximo = NULL;
}

int ehVazia(tFila fila){
  return (fila.frente == fila.tras);
}

void enfilera(tFila *fila, tipoItem *y, int n){
  fila->tras->proximo = (apontador)malloc(sizeof(celula));
  fila->tras = fila->tras->proximo;
  fila->tras->c.item = y;
  fila->tras->c.cont = n;
  printf("%d", fila->tras->c.cont);
  fila->tras->proximo = NULL;
}

tipoItem *desenfileira(tFila *fila, int *n){
  tipoItem *y;
  if(ehVazia(*fila)){
    return NULL;
  }
  apontador exclui = fila->frente;
  fila->frente = fila->frente->proximo;
  y = fila->frente->c.item;
  *n = fila->frente->c.cont;
  free(exclui);
  return y;
}

void imprime(tFila fila){
  if(ehVazia(fila)){
    printf("Fila vazia\n");
    return;
  }
  apontador aux = fila.frente->proximo;
  int count = 1;
  while (aux != fila.tras->proximo) {
    printf("\n\nposicao %d da fila\n", count);
    for(int i = 0; i < aux->c.cont; i++){
      printf("%d\n", aux->c.item[i]);
    }
    aux = aux->proximo;
    count++;
}
}
