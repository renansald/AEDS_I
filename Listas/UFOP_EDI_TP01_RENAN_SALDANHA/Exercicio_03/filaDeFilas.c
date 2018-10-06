#include "filaDeFilas.h"
#include <stdio.h>

int ehVazia(tFila fila){
  return (fila.frente == fila.tras);
}

int ehVaziaFF(tFilas ffila){
  return (ffila.frente == ffila.tras);
}

void fazFila2(tFila *fila){
  fila->frente = 1;
  fila->tras = 1;
}

void fazFilaF(tFilas *ffila){
  ffila->frente = 1;
  ffila->tras = 1;
}

void enfilera2(tFila *fila, tipoItem x){
  if(((fila->tras % maxF) + 1) == (fila->frente)){
    printf("A fila está cheia\n");
    return;
  }
  fila->c[fila->tras - 1].item = x;
  fila->tras = fila->tras % maxF + 1;
}

void desenfilera2(tFila *fila, tipoItem *x){
  if(ehVazia(*fila)){
    printf("A fila está vazia\n");
    return;
  }
  *x = fila->c[fila->frente-1].item;
  fila->frente = fila->frente % maxF +1;
}

void enfileraF(tFilas *ffila, tFila fila){
  if(((ffila->tras % maxF) + 1) == (ffila->frente)){
    printf("A fila de filas está cheia\n");
    return;
  }
  fazFila2(&ffila->fila[ffila->tras - 1]);
  if(ehVazia(fila)){
    ffila->tras = ffila->tras % maxF + 1;
    return;
  }
  while(fila.tras != fila.frente){
    enfilera2(&ffila->fila[ffila->tras - 1], fila.c[fila.frente - 1].item);
    //ffila->fila[ffila->tras -1].c[ffila->fila[ffila->tras -1].tras-1].item = fila.c[aux - 1].item;
    //ffila->fila[ffila->tras - 1].tras = ffila->fila[ffila->tras - 1].tras % maxF + 1;
    fila.frente = fila.frente % maxF + 1;
  }
  ffila->tras = ffila->tras % maxF + 1;
}

void desenfileraf(tFilas *ffila, tFila *fila){
  if((ehVaziaFF(*ffila)) || !(ehVazia(*fila))){
    printf("Erro\n");
    return;
  }
  while(ffila->fila[ffila->frente -1].frente != ffila->fila[ffila->frente -1].tras){
    desenfilera2(&ffila->fila[ffila->frente-1], &fila->c[fila->tras - 1].item);
    fila->tras = fila->tras % maxF + 1;
  }
  ffila->frente = ffila->frente % maxF + 1;
}

void imprime(tFila fila){
  if(ehVazia(fila)){
    printf("\nFila Vazia\n");
    return;
  }
  apontador aux = fila.frente;
  printf("\n\n");
  while(aux != fila.tras){
    printf("%d\n", fila.c[aux-1].item);
    aux = aux % maxF + 1;
  }
}

void imprimef(tFilas ffila){
  if(ehVaziaFF(ffila)){
    printf("está vazia\n");
    return;
  }
  apontador aux = ffila.frente;
  int count = 1;
  while(aux != ffila.tras){
    printf("fila %d", count);
    imprime(ffila.fila[aux - 1]);
    aux = aux % maxF + 1;
    count++;
  }
}
