#include "listaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

void fazLista(tLista *lista){
  lista->primeiro = (apontadorL)malloc(sizeof(celulaL));
  lista->ultimo = lista->primeiro;
  lista->count = 0;
}

int ehVaziaL(tLista lista){
  return (lista.primeiro == lista.ultimo);
}

void add(tLista *lista, tipoItem x){
  lista->ultimo->item = x;
  lista->ultimo->proximo = (apontadorL)malloc(sizeof(celulaL));
  lista->ultimo = lista->ultimo->proximo;
  lista->ultimo->proximo = NULL;
  lista->count++;
}

void removes(tLista *lista, tipoItem *x){
  if(ehVaziaL(*lista)){
    printf("A lista esta vazia\n");
    return;
  }
  *x = lista->primeiro->item;
  apontadorL exclui = lista->primeiro;
  lista->primeiro = lista->primeiro->proximo;
  lista->count--;
  free(exclui);
}

void imprimeLista(tLista lista){
  if(ehVaziaL(lista)){
    printf("A lista esta vazia\n");
    return;
  }
  apontadorL aux = lista.primeiro;
  while(aux->proximo != NULL){
    printf("%d\n", aux->item);
    aux = aux->proximo;
  }
}

int verificaNumeroLista(tLista lista, tipoItem x){
  if(!(ehVaziaL(lista))){
  apontadorL aux = lista.primeiro;
    while(aux->proximo != NULL){
      if(aux->item == x){
        return 1;
      }
      aux = aux->proximo;
    }
  }
  return 0;
}

void cpyLista(tLista lista1, tLista *lista){
  if(ehVaziaL(lista1)){
    printf("A lista a ser copiada esta vazia\n");
    return;
  }
  apontadorL aux = lista1.primeiro;
  while(aux->proximo != NULL){
    add(lista, aux->item);
    aux = aux->proximo;
  }
}

void concatenaLista(tLista lista1, tLista lista2, tLista *lista){
  if((ehVaziaL(lista1)) && (ehVaziaL(lista2))){
    printf("As listas estão vazias");
    return;
  }
  else if(ehVaziaL(lista1)){
    cpyLista(lista2, lista);
    return;
  }
  else if(ehVaziaL(lista2)){
    cpyLista(lista1, lista);
    return;
  }
  else{
    cpyLista(lista1, lista);
    cpyLista(lista2, lista);
  }
}

void intercalaLista(tLista lista1, tLista lista2, tLista *lista){
  if((ehVaziaL(lista1)) && (ehVaziaL(lista2))){
    printf("Listas vazias\n");
    return;
  }
  else if((ehVaziaL(lista1)) || (ehVaziaL(lista2))){
    printf("Uma das listas está vazia");
    return;
  }
  apontadorL aux = lista1.primeiro;
  apontadorL aux2 = lista2.primeiro;
  if(lista1.count > lista2.count){
    while(aux->proximo != NULL){
      if(aux2->proximo == NULL){
        add(lista, aux->item);
        aux = aux->proximo;
      }
      else{
        add(lista, aux->item);
        add(lista, aux2->item);
        aux = aux->proximo;
        aux2 = aux2->proximo;
      }
    }
    return;
  }
  if(lista1.count < lista2.count){
    while(aux2->proximo != NULL){
      if(aux->proximo == NULL){
        add(lista, aux2->item);
        aux2 = aux2->proximo;
      }
      else{
        add(lista, aux->item);
        add(lista, aux2->item);
        aux = aux->proximo;
        aux2 = aux2->proximo;
      }
    }
  }
}

void intersecaoDeLista(tLista lista1, tLista lista2, tLista *lista){
  if((ehVaziaL(lista1)) || (ehVaziaL(lista2))){
    printf("Uma das listas está vazia\n");
    return;
  }
  apontadorL aux = lista1.primeiro;
  int i = 0;
  while(aux->proximo != NULL){
    if((verificaNumeroLista(lista2, aux->item)) && !(verificaNumeroLista(*lista, aux->item))){
      add(lista, aux->item);
      i++;
    }
    aux = aux->proximo;
  }
  if(i == 0){
    printf("Não existe intersecao entre as listas\n");
  }
}

void diferencaLista(tLista lista1, tLista lista2, tLista *lista){
  if((ehVaziaL(lista1)) && (ehVaziaL(lista2))){
    printf("Listas vazias\n");
    return;
  }
  apontadorL aux = lista1.primeiro;
  apontadorL aux2 = lista2.primeiro;
  if(lista1.count >= lista2.count){
    while (aux->proximo != NULL) {
      if(aux2->proximo == NULL){
        add(lista, aux->item);
        aux = aux->proximo;
      }
      else{
        add(lista, (aux->item - aux2->item));
        aux = aux->proximo;
        aux2 = aux2->proximo;
      }
    }
  }
  else{
    while (aux2->proximo != NULL) {
      if(aux->proximo == NULL){
        add(lista, -aux2->item);
        aux2 = aux2->proximo;
      }
      else{
        add(lista, (aux->item - aux2->item));
        aux = aux->proximo;
        aux2 = aux2->proximo;
      }
    }
  }
}

void listaOrdenada(tLista lista){
  if(ehVaziaL(lista)){
    printf("Lista vazia\n");
    return;
  }
  else if(lista.count == 1){
    printf("Existe apenas um elemento\n");
    return;
  }
  int x = 0;
  apontadorL aux = lista.primeiro;
  apontadorL aux2 = lista.primeiro->proximo;
  for(int i = 0; i < lista.count; i++){
    for(int a = i + 1; a < lista.count; a++){
    //  printf("primeiro %d\n\n segundo %d\n\n\n\\", aux->item, aux2->item);
      if(aux->item >= aux2->item){
      //  printf("Sou maior ou igual\n");
        x = 1;
      }
      else{
        x = 0;
        break;
      }
    }
    if(x == 0){
      break;
    }
      aux = aux->proximo;
      aux2 = aux2->proximo;
  }
  if(x == 1){
    printf("A lista esta ordenada de forma decrescente\n");
    return;
  }
  aux = lista.primeiro;
  aux2 = lista.primeiro->proximo;
  for(int i = 0; i < lista.count; i++){
    for(int a = i + 1; a < lista.count; a++){
      if(aux->item <= aux2->item){
        x = 1;
      }
      else{
        printf("Nao esta ordenado\n");
        return;
      }
    }
      aux = aux->proximo;
      aux2 = aux2->proximo;
  }
  printf("A lista esta ordenada de forma crescente\n");
}

void addOrdenado(tLista *lista, tipoItem x){
  if(ehVaziaL(*lista)){
    add(lista, x);
    return;
  }
  apontadorL aux = lista->primeiro;
  apontadorL aux2;
  while (aux->proximo != NULL) {
    if(x < aux->item){
      break;
    }
    aux2 = aux;
    aux = aux->proximo;
  }
  if(aux == lista->primeiro){
    apontadorL temp = (apontadorL)malloc(sizeof(celulaL));
    temp->item = x;
    temp->proximo = aux;
    lista->primeiro = temp;
  }
  apontadorL temp = (apontadorL)malloc(sizeof(celulaL));
  temp->item = x;
  temp->proximo = aux;
  aux2->proximo = temp;
}

void mesclaElemento(tLista *lista, tLista lista1){
  apontadorL aux1 = lista1.primeiro;
  while(aux1->proximo != NULL){
    add(lista, aux1->item);
    aux1 = aux1->proximo;
  }
    apontadorL aux = lista->primeiro;
    apontadorL aux2 = aux->proximo;
    apontadorL temp = lista->primeiro;
    while (aux2->proximo != NULL) {
      if(aux->item > aux2->item){
       if(aux == lista->primeiro){
          aux->proximo = aux2->proximo;
          aux2->proximo = lista->primeiro;
          lista->primeiro = aux2;
          aux = lista->primeiro->proximo;
          aux2 = aux->proximo;
        }
        temp->proximo = aux2;
        aux->proximo = aux2->proximo;
        aux2->proximo = aux;
        aux = lista->primeiro;
        aux2 = aux->proximo;
        temp = lista->primeiro;
      }
      temp = aux;
      aux = aux->proximo;
      aux2 = aux2->proximo;
    }
  }
