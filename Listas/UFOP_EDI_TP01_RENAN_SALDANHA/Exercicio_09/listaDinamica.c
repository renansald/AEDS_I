#include "listaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

void fazLista(tLista *lista){
  lista->fim = (apontador)malloc(sizeof(celula));
  lista->inicio = lista->fim;
  lista->fim->proximo = NULL;
  lista->count = 0;
}

int ehVazia(tLista lista){
  return (lista.inicio == lista.fim);
}

void add(tLista *lista, Item x){
  lista->fim->proximo = (apontador)malloc(sizeof(celula));
  lista->fim = lista->fim->proximo;
  lista->fim->item.chave = x;
  lista->fim->proximo = NULL;
  lista->count++;
}

void removes(tLista *lista, Item *x){
  if(ehVazia(*lista)){
    printf("Lista vazia\n");
    return;
  }
  apontador exclui = lista->inicio;
  *x = lista->inicio->proximo->item.chave;
  lista->inicio = lista->inicio->proximo;
  lista->count--;
  free(exclui);
}

void imprime(tLista lista) {
  if(ehVazia(lista)){
    printf("Lista vazia\n");
    return;
  }
  apontador aux = lista.inicio->proximo;
  while(aux != NULL){
    printf("%d\n", aux->item.chave);
    aux = aux->proximo;
  }
}

void removePar(tLista *lista){
  if(ehVazia(*lista)){
    printf("Lista vazia\n");
    return;
  }
  apontador aux = lista->inicio->proximo;
  apontador temp = lista->inicio;
  while (aux != NULL) {
    if(aux->item.chave % 2 == 0){
      if(aux->proximo == NULL){
        lista->fim = temp;
        lista->fim->proximo = NULL;
        free(aux);
        break;
      }
      else{
        temp->proximo = aux->proximo;
        free(aux);
        aux = temp->proximo;
      }
    }
    else{
    aux = aux->proximo;
    temp = temp->proximo;
  }
  }
}
