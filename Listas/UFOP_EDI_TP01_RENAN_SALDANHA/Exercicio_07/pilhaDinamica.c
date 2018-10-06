#include "pilhaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

void fazPilha(tPilha *pilha){
  pilha->fundo = (apontador)malloc(sizeof(Celula));
  pilha->topo = pilha->fundo;
  pilha->fundo->proximo = NULL;
  pilha->cont = 0;
}

int ehVazia(tPilha pilha){
  return (pilha.fundo == pilha.topo);
}

void empilha(tPilha *pilha, tipoItem x){
  apontador aux = (apontador)malloc(sizeof(Celula));
  aux->proximo = pilha->topo;
  pilha->topo->c.item = x;
  pilha->topo = aux;
  pilha->cont++;
}

void desempilha(tPilha *pilha, tipoItem *x){
  if(ehVazia(*pilha)){
    printf("A pilha esta vazia\n");
    return;
  }
  apontador aux = pilha->topo;
  pilha->topo = pilha->topo->proximo;
  *x = pilha->topo->c.item;
  pilha->cont--;
  free(aux);
}

void imprimePilha(tPilha pilha){
  if(ehVazia(pilha)){
    printf("A pilha esta vazia\n");
    return;
  }
  apontador aux = pilha.topo->proximo;
  while (aux != NULL) {
    printf("%d\n", aux->c.item);
    aux = aux->proximo;
  }
}

void verificaNumeroPilha(tPilha pilha, tipoItem x){
  apontador aux = pilha.topo->proximo;
  while(aux != NULL){
    if(aux->c.item == x){
      printf("O item %d pertence a pilha\n", x);
      return;
    }
    aux = aux->proximo;
  }
  printf("O item %d nao pertence a pilha\n", x);
}

void cpyPilha(tPilha pilha, tPilha *pilhac){
  if(ehVazia(pilha)){
    printf("Pilha a ser copiada está vazia\n");
    return;
  }
  apontador aux = pilha.topo->proximo;
  int c = pilha.cont -1;
  while (c > -1) {
    for (int i = 0; i < c; i++) {
      aux = aux->proximo;
    }
    empilha(pilhac, aux->c.item);
    aux = pilha.topo->proximo;
    c--;
  }
}

void concatenaPilha(tPilha pilha1, tPilha pilha2, tPilha *pilha){
  if((ehVazia(pilha1)) || (ehVazia(pilha2))){
    printf("As duas ou uma pilha é vazia, logo não a necessidade de concatenar as pilhas\n");
    return;
  }
  cpyPilha(pilha1, pilha);
  cpyPilha(pilha2, pilha);
}

void intercalaPilha(tPilha pilha1, tPilha pilha2, tPilha *pilha){
  if((ehVazia(pilha1)) || (ehVazia(pilha2))){
    printf("As duas ou uma pilha é vazia, logo não e necessario intercala-las\n");
    return;
  }
  apontador aux1 = pilha1.topo->proximo;
  apontador aux2 = pilha2.topo->proximo;
  int aux3 = pilha1.cont - 1;
  int aux4 = pilha2.cont - 1;
  int aux = aux3 + aux4;
  while (aux > -1) {
    for(int i = 0; i < aux3; i++){
      aux1 = aux1->proximo;
    }
    for(int i = 0; i < aux4; i++){
      aux2 = aux2->proximo;
    }
    if(aux3 >= 0){
      empilha(pilha, aux1->c.item);
    }
    if(aux4 >= 0){
      empilha(pilha, aux2->c.item);
    }
    aux1 = pilha1.topo->proximo;
    aux2 = pilha2.topo->proximo;
    aux--;
    aux3--;
    aux4--;
  }
}
