#include "pilhaDefilasEstatica.h"
#include <stdio.h>

void fazPilhadeListas(tPilha *pilha){
  pilha->topo = 0;
}

void fazFila(tFila *fila){
  fila->frente = 1;
  fila->tras = 1;
}

int filaVazia(tFila fila){
  return (fila.tras == fila.frente);
}

int pilhaVazia(tPilha pilha){
  return (pilha.topo == 0);
}

void enfilera(tFila *fila, tipoItem x){
  if(((fila->tras % maxF) + 1)==(fila->frente)){
    printf("Fila cheia\n");
    return;
  }
  fila->c[fila->tras - 1].item = x;
  fila->tras = fila->tras %maxF + 1;
}

void desenfilera(tFila *fila, tipoItem *y){
  if(filaVazia(*fila)){
    printf("Fila Vazia\n");
    return;
  }
  *y = fila->c[fila->frente-1].item;
  fila->frente = fila->frente % maxF + 1;
}

void empilhaFila(tPilha *pilha, tFila fila){
  if(pilha->topo == maxP){
    printf("Pilha cheia\n");
    return;
  }
  if(filaVazia(fila)){
    fazFila(&pilha->fila[pilha->topo]);
    pilha->topo++;
    return;
  }
  fazFila(&pilha->fila[pilha->topo]);
  apontador aux = fila.frente;
  while(aux != fila.tras){
    enfilera(&pilha->fila[pilha->topo], fila.c[aux - 1].item);
    aux = aux % maxF +1;
  }
  pilha->topo = pilha->topo + 1;
}

void desempilhaFila(tPilha *pilha, tFila *fila){
  if(pilhaVazia(*pilha)){
    printf("Pilha Vazia");
    return;
  }
  if(pilha->fila[pilha->topo].tras % maxF + 1 == pilha->fila[pilha->topo].frente){
    printf("A fila na qual deseja alocar está cheia, por favor use outra fila");
    return;
  }
  apontador aux = pilha->fila[pilha->topo - 1].frente;
  while(aux != pilha->fila[pilha->topo - 1].tras){
    fila->c[fila->tras-1].item = pilha->fila[pilha->topo - 1].c[aux-1].item;
    aux = aux % maxF + 1;
    fila->tras = fila->tras % maxF + 1;
  }
  pilha->topo = pilha->topo - 1;
}

void imprimeFila(tFila fila){
  if(filaVazia(fila)){
    printf("Fila vazia\n");
    return;
  }
  apontador aux = fila.frente;
  while(aux != fila.tras){
    printf("%d\n", fila.c[aux-1].item);
    aux = aux % maxF + 1;
  }
}

void imprimePilhadeFilas(tPilha pilha){
  if(pilhaVazia(pilha)){
    printf("A pilha esta vazia\n");
    return;
  }
  apontador aux = pilha.topo;
  int count = 1;
  while(aux > 0){
    printf("%d fila da pilha\n", count);
    imprimeFila(pilha.fila[aux-1]);
    printf("\n\n");
    aux--;
    count++;
  }
}
