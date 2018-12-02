#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void fazLista(tLista *lista){
  lista->inicio = (apontador)malloc(sizeof(Celula));
  lista->fim = lista->inicio;
  lista->cont = 0;
}

int ehVazia(tLista lista){
  return (lista.inicio == lista.fim);
}

void add(tLista *lista, tipoItem x){
  lista->fim->proximo = (apontador)malloc(sizeof(Celula));
  lista->fim->c.item = x;
  lista->fim = lista->fim->proximo;
  lista->cont++;
}

void removes(tLista *lista, tipoItem *x){
  if(ehVazia(*lista)){
    printf("Lista vazia\n");
    return;
  }
  apontador exclui = lista->inicio;
  *x = lista->inicio->c.item;
  lista->inicio = lista->inicio->proximo;
  lista->cont--;
  free(exclui);
}

void imprime(tLista lista){
  if(ehVazia(lista)){
    printf("Lista vazia\n");
    return;
  }
  apontador aux = lista.inicio;
  while(aux != lista.fim){
    printf("%d\n", aux->c.item);
    aux = aux->proximo;
  }
}

void listaA(tLista *a, tLista lista){
  if(ehVazia(lista)){
    printf("A lista esta vazia\n");
    return;
  }
  apontador aux = lista.inicio->proximo;
  if(lista.cont == 1){
    add(a, lista.inicio->c.item);
    return;
  }
  while(lista.cont - 1 > a->cont){
    add(a, aux->c.item);
    aux = aux->proximo;
  }
  add(a, lista.inicio->c.item);
}

void listaB(tLista *a, tLista lista){
  if(ehVazia(lista)){
    printf("A lista esta vazia\n");
    return;
  }
  if(lista.cont == 1){
    add(a, lista.inicio->c.item);
    return;
  }
  apontador aux = lista.inicio;
  apontador aux2;
  int count = lista.cont;
  while (count > 0){
    aux2 = (apontador)malloc(sizeof(Celula));
    aux2->proximo = a->inicio;
    a->inicio = aux2;
    a->inicio->c.item = aux->c.item;
    aux = aux->proximo;
    count--;
  }
}

void listaC(tLista *a, tLista lista){
  if(ehVazia(lista)){
    printf("A lista esta vazia\n");
    return;
  }
  if(lista.cont%2 != 0){
    printf("A lista deve ter um número par de elementos\n");
    return;
  }
  int count = lista.cont / 2;
  apontador aux1 = lista.inicio;
  apontador aux2;
  int count2 = lista.cont - 2;
  while(count > 0){
    aux2 = aux1->proximo;
    if(count != 1){
      for(int i = 0; i < count2; i++){
        aux2 = aux2->proximo;
      }
    }
    add(a, (aux1->c.item + aux2->c.item));
    aux1 = aux1->proximo;
    count--;
    count2-= 2;
  }
}
