#include "questao_12.h"
#include <stdio.h>
#include <stdlib.h>

void fazPilha(tPilha *pilha){
  pilha->fundo = (apontador)malloc(sizeof(celulaP));
  pilha->topo = pilha->fundo;
  pilha->topo->proximo = NULL;
  pilha->count = 0;
}

void fazFila(tFila *fila){
  fila->frente = (apontador)malloc(sizeof(celulaP));
  fila->tras = fila->frente;
  fila->frente->proximo = NULL;
  fila->count = 0;
}

void fazLista(tLista *lista){
  lista->fim = (apontador)malloc(sizeof(celulaP));
  lista->inicio = lista->fim;
  lista->fim->proximo = NULL;
  lista->count = 0;
}

int ehVaziaP(tPilha pilha){
  return pilha.count == 0;
}

int ehVaziaF(tFila fila){
  return fila.count == 0;
}

int ehVaziaL(tLista lista){
  return lista.count == 0;
}

void empilha(tPilha *pilha, tipoChave x){
  apontador aux = (apontador)malloc(sizeof(celulaP));
  pilha->topo->item.chave = x;
  aux->proximo = pilha->topo;
  pilha->topo = aux;
  pilha->count++;
}

void enfilera(tFila *fila, tipoChave x){
  fila->tras->proximo = (apontador)malloc(sizeof(celulaP));
  fila->tras = fila->tras->proximo;
  fila->tras->item.chave = x;
  fila->tras->proximo = NULL;
  fila->count++;
}

void add(tLista *lista, tipoChave x){
  lista->fim->proximo = (apontador)malloc(sizeof(celulaP));
  lista->fim = lista->fim->proximo;
  lista->fim->item.chave = x;
  lista->fim->proximo = NULL;
  lista->count++;
}

void desempilha(tPilha *pilha, tipoChave *x){
  if(ehVaziaP(*pilha)){
    printf("Pilha vazia\n");
    return;
  }
  apontador aux = pilha->topo;
  pilha->topo = pilha->topo->proximo;
  *x = pilha->topo->item.chave;
  free(aux);
  pilha->count--;
}

void desenfilera(tFila *fila, tipoChave *chave) {
  if(ehVaziaF(*fila)){
    printf("Fila vazia\n");
    return;
  }
  apontador aux = fila->frente;
  fila->frente = aux->proximo;
  *chave = fila->frente->item.chave;
  free(aux);
  fila->count--;
}

void removes(tLista *lista, tipoChave *x){
  if(ehVaziaL(*lista)){
    printf("Lista vazia\n");
    return;
  }
  apontador aux = lista->inicio;
  lista->inicio = aux->proximo;
  *x = lista->inicio->item.chave;
  free(aux);
  lista->count--;
}

void imprime(tLista lista){
  if(ehVaziaL(lista)){
    printf("Lista vazia\n");
    return;
  }
  apontador aux = lista.inicio->proximo;
  while(aux != NULL){
    printf("%c ", aux->item.chave);
    aux = aux->proximo;
  }
  printf("\n");
}

int ehDigito(tipoChave x){
  if((x == '0') || (x == '1') || (x == '2') || (x == '3') || (x == '4') || (x == '5') || (x == '6') || (x == '7') || (x == '8') || (x == '9')){
    return 1;
  }
  else{
    return 0;
  }
}

void reorganiza(tLista *lista, tLista lista2){
  if(ehVaziaL(lista2)){
    printf("Lista vazia\n");
    return;
  }
  tipoChave aux1;
  tFila fila;
  tPilha pilha;
  fazFila(&fila);
  fazPilha(&pilha);
  apontador aux = lista2.inicio->proximo;
  while(aux != NULL){
    if(ehDigito(aux->item.chave)){
      empilha(&pilha, aux->item.chave);
    }
    else{
      enfilera(&fila, aux->item.chave);
    }
    aux = aux->proximo;
  }
  while (fila.frente != fila.tras) {
    desenfilera(&fila, &aux1);
    add(lista, aux1);
  }
  while (pilha.topo != pilha.fundo) {
    desempilha(&pilha, &aux1);
    add(lista, aux1);
  }
}
