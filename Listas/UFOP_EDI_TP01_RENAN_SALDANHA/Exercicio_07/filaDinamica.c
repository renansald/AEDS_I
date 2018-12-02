#include "filaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

void fazFila(tFila *fila){
  fila->frente = (apontadorF)malloc(sizeof(celulaf));
  fila->tras = fila->frente;
  fila->tras->proximo = NULL;
  fila->count = 0;
}

int ehVaziaf(tFila fila){
  return (fila.frente == fila.tras);
}

void enfilera(tFila *fila, tipoItem x){
  fila->tras->item = x;
  fila->tras->proximo = (apontadorF)malloc(sizeof(celulaf));
  fila->tras = fila->tras->proximo;
  fila->tras->proximo = NULL;
  fila->count++;
}

void desenfilera(tFila *fila, tipoItem *x){
  if(ehVaziaf(*fila)){
    printf("Fila vazia\n");
    return;
  }
  apontadorF aux = fila->frente;
  *x = fila->frente->item;
  fila->frente = fila->frente->proximo;
  fila->count--;
  free(aux);
}

void imprimeFila(tFila fila){
  if(ehVaziaf(fila)){
    printf("Fila vazia\n");
    return;
  }
  apontadorF aux = fila.frente;
  while(aux->proximo != NULL){
    printf("%d\n", aux->item);
    aux = aux->proximo;
  }
}

int verificaNumeroFila(tFila fila, tipoItem x){
  if(ehVaziaf(fila)){
    return 0;
  }
  apontadorF aux = fila.frente;
  while(aux->proximo != NULL){
    if(aux->item == x){
      return 1;
    }
    aux = aux->proximo;
  }
  return 0;
}

void cpyFila(tFila fila, tFila *fila1){
  if (ehVaziaf(fila)) {
    printf("Fila Vazia\n");
  }
  apontadorF aux = fila.frente;
  while(aux->proximo != NULL){
    enfilera(fila1, aux->item);
    aux = aux->proximo;
  }
}

/*void concatenaFila(tFila fila1, tFila fila2, tFila *fila){
  if((ehVaziaf(fila1)) && (ehVaziaf(fila2))){
    printf("As filas a serem concatenadas estão vazias\n");
    return;
  }
  if(!(ehVaziaf(fila1))){
    cpyFila(fila1, fila);
  }
  if(!(ehVaziaf(fila2))){
    cpyFila(fila2, fila);
  }
}*/

void concatenaFila(tFila *fila, tFila fila2){
  if(ehVaziaf(fila2)){
    printf("A fila a ser concatena com a outra esta vazia\n");
    return;
  }
  apontadorF aux = fila2.frente;
  while(aux->proximo != NULL){
    enfilera(fila, aux->item);
    aux = aux->proximo;
  }
}

void intercalaFila(tFila fila1, tFila fila2, tFila *fila){
  int cont = fila1.count + fila2.count;
  apontadorF aux = fila1.frente;
  apontadorF aux2 = fila2.frente;
  while (cont > 0) {
    if(aux->proximo != NULL){
      enfilera(fila, aux->item);
      aux = aux->proximo;
    }
    if(aux2->proximo != NULL){
      enfilera(fila, aux2->item);
      aux2 = aux2->proximo;
    }
    cont--;
  }
}

void intersecaoDeFila(tFila fila1, tFila fila2, tFila *fila){
  if((ehVaziaf(fila1)) || (ehVaziaf(fila2))){
    printf("Uma das filas esta vazia\n");
    return;
  }
  apontadorF aux = fila1.frente;
  while(aux->proximo != NULL){
    if((verificaNumeroFila(fila2, aux->item)) && !(verificaNumeroFila(*fila, aux->item))){
      enfilera(fila, aux->item);
    }
    aux = aux->proximo;
  }
}

void diferencaFila(tFila fila1, tFila fila2, tFila *fila){
  if(ehVaziaf(fila1)){
    printf("A primeira fila ta vazia\n");
    return;
  }
  else if(ehVaziaf(fila2)){
    printf("A sua segunda fila t vazia\n");
    return;
  }
  apontadorF aux = fila1.frente;
  apontadorF aux2 = fila2.frente;
  if(fila1.count >= fila2.count){
    while (aux->proximo != NULL) {
      if(aux2->proximo == NULL){
        enfilera(fila, aux->item);
        aux = aux->proximo;
      }
      else{
        enfilera(fila, (aux->item - aux2->item));
        aux = aux->proximo;
        aux2 = aux2->proximo;
      }
    }
  }
  else{
    while (aux2->proximo != NULL) {
      if(aux->proximo == NULL){
        enfilera(fila, -(aux2->item));
        aux2 = aux2->proximo;
      }
      else{
        enfilera(fila, (aux->item - aux2->item));
        aux = aux->proximo;
        aux2 = aux2->proximo;
      }
    }
  }
}

void filaOrdenada(tFila fila){
  int x;
  apontadorF aux = fila.frente;
  apontadorF aux2 = fila.frente->proximo;
  while(aux2->proximo != NULL){
    if(aux->item >= aux2->item){
      x = 1;
      aux = aux->proximo;
    }
    else{
      x = 0;
      break;
    }
    aux2 = aux->proximo;
  }
  if(x == 1){
    printf("Ordenado de forma decrescente\n");
    return;
  }
  aux = fila.frente;
  aux2 = fila.frente->proximo;
  while(aux2->proximo != NULL){
    if(aux->item <= aux2->item){
      x = 1;
      aux = aux->proximo;
    }
    else{
      x = 0;
      printf("Fila desordenada\n");
      return;
    }
    aux2 = aux->proximo;
  }
  if(x == 1){
    printf("Ordenado de forma crescente\n");
    return;
  }
}

void inverteFila(tFila *fila){
  apontadorF aux = fila->frente->proximo;
  apontadorF aux2 = aux;
  apontadorF t = fila->frente;
  while (aux2->proximo != NULL) {
    aux2 = aux->proximo;
    aux->proximo = t;
    t = aux;
    aux = aux2;
  }
  fila->frente->proximo = fila->tras;
  fila->tras->proximo = NULL;
  fila->frente = t;
}
