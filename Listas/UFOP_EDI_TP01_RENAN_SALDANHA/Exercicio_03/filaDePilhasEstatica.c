#include "filaDePilhasEstatica.h"
#include <stdio.h>

void fazFilaDePilhas(tFila *fila){
  fila->frente = 1;
  fila->tras = 1;
}

void fazPilha(tPilha *pilha){
  pilha->topo = 0;
}

int verificaFilaVazia(tFila fila){
  return(fila.frente == fila.tras);
}

int verificaPilhavazia(tPilha pilha){
  return(pilha.topo == 0);
}

void empilha(tPilha *pilha, tipoItem x){
  if(pilha->topo == maxP){
    printf("Pilha cheia\n");
    return;
  }
  pilha->c[pilha->topo].item = x;
  pilha->topo = pilha->topo + 1;
}

void enfileraPilha(tFila *fila, tPilha pilha){
  if(((fila->tras % maxF) + 1) == (fila->frente)){
    printf("Fila Cheia\n");
    return;
  }
  if (verificaPilhavazia(pilha)) {
    fazPilha(&fila->pilha[fila->tras-1]);
    fila->tras = fila->tras % maxF + 1;
    return;
  }
  tPilha aux;
  fazPilha(&aux);
  fazPilha(&fila->pilha[fila->tras - 1]);
  while(pilha.topo > 0){
    desempilha(&pilha, &aux.c[aux.topo].item);
    aux.topo = aux.topo + 1;
  }
  while(aux.topo != 0){
    empilha(&fila->pilha[fila->tras - 1], aux.c[aux.topo-1].item);
    aux.topo--;
  }
  fila->tras = fila->tras % maxF + 1;
}

void desempilha(tPilha *pilha, tipoItem *x){
  if(verificaPilhavazia(*pilha)){
    printf("A pilha esta vazia\n");
    return;
  }
  pilha->topo = pilha->topo - 1;
  *x = pilha->c[pilha->topo].item;
}

void desenfileraPilha(tFila *fila, tPilha *pilha){
  if((verificaFilaVazia(*fila)) || !(verificaPilhavazia(*pilha))){
    printf("Fila vazia\n");
    return;
  }
  if(verificaPilhavazia(fila->pilha[fila->frente-1])){
    pilha->topo = 0;
    fila->frente = fila->frente % maxF + 1;
    return;
  }
  tPilha aux;
  fazPilha(&aux);
  while(fila->pilha[fila->frente -1].topo != 0){
    desempilha(&fila->pilha[fila->frente-1], &aux.c[aux.topo].item);
    aux.topo++;
  }
  while(aux.topo != 0){
    empilha(pilha, aux.c[aux.topo-1].item);
    aux.topo--;
  }
  fila->frente = fila->frente % maxF + 1;
}

void imprimePilha(tPilha pilha){
  if(verificaPilhavazia(pilha)){
    printf("Pilha Vazia\n");
    return;
  }
  apontador aux = pilha.topo;
  printf("Pilha:\n");
  while (aux != 0) {
    printf("%d\n", pilha.c[aux-1].item);
    aux--;
  }
}

void imprimeFiladePilha(tFila fila){
  if(verificaFilaVazia(fila)){
    printf("Fila vazia\n");
    return;
  }
  apontador aux = fila.frente;
  int cont = 1;
  while(aux != (fila.tras+1)){
    printf("%d Pilha\n", cont);
    imprimePilha(fila.pilha[aux-1]);
    aux = aux % maxF + 1;
    cont++;
  }
}
