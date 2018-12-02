#include "listaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

void fazLista(tLista *lista){
  lista->inicio = (apontador)malloc(sizeof(celula));
  lista->fim = lista->inicio;
  lista->fim->proximo = NULL;
  lista->count = 0;
}

int ehVazia(tLista lista){
  return (lista.inicio == lista.fim);
}

void add(tLista *lista, char s[1000], char link[1000]){
  printf("Vou adicionar %s e %s\n", s, link);
  lista->fim->proximo = (apontador)malloc(sizeof(celula));
  lista->fim = lista->fim->proximo;
  int i = 0;
  lista->fim->nbusca = 0;
  while (s[i] != '\0') {
    printf("%c\n", s[i]);
    lista->fim->sites[i] = s[i];
    i++;
  }
  i = 0;
  while (link[i] != '\0') {
    lista->fim->link[i] = link[i];
    i++;
  }
  lista->count++;
}

void removes(tLista *lista, char s[1000], char link[1000]){
  if(ehVazia(*lista)){
    printf("A lista está vazia\n");
    return;
  }
  apontador aux = lista->inicio;
  lista->inicio = lista->inicio->proximo;
  int i = 0;
  while(lista->inicio->sites[i] != '\0'){
    s[i] = lista->fim->sites[i];
    i++;
  }
  i = 0;
  while(lista->inicio->link[i] != '\0'){
    link[i] = lista->inicio->link[i];
    i++;
  }
  free(aux);
}

void imprimeLista(tLista lista){
  if(ehVazia(lista)){
    printf("A lista está vazia\n");
    return;
  }
  apontador aux = lista.inicio->proximo;
  while(aux != NULL){
    printf("Nome do site: %s\nLink do site: %s\nNumero de buscas %d\n\n", aux->sites, aux->link, aux->nbusca);
    aux = aux->proximo;
  }
}

void atualizaOrdem(tLista *lista){
  apontador aux = lista->inicio->proximo;
  apontador aux2 = aux->proximo;
  apontador temp = lista->inicio;
  while (aux2 != NULL) {
    if(aux->nbusca < aux2->nbusca){
      if(aux2 == lista->fim){
        temp->proximo = aux2;
        aux2->proximo = aux;
        aux->proximo = NULL;
        lista->fim = aux;
        aux = lista->inicio->proximo;
        aux2 = aux->proximo;
        temp = lista->inicio;
      }
      temp->proximo = aux2;
      aux->proximo = aux2->proximo;
      aux2->proximo = aux;
      aux = lista->inicio->proximo;
      aux2 = aux->proximo;
      temp = lista->inicio;
    }
    else{
    aux = aux->proximo;
    aux2 = aux2->proximo;
    temp = temp->proximo;
  }
  }
}

void busca(tLista *lista, char site[1000]){
  if(ehVazia(*lista)){
    printf("Lista vazia\n");
    return;
  }
  int control = 0;
  apontador aux = lista->inicio->proximo;
  while(aux != NULL){
    for (int i = 0; site[i] !='\0'; i++){
      if(aux->sites[i] != site[i]){
        control = 0;
        break;
      }
      else
      control = 1;
    }
    if(control == 1){
      break;
    }
    aux = aux->proximo;
  }
  if(control == 1){
    printf("Link de %s: %s\n", site, aux->link);
    aux->nbusca++;
    atualizaOrdem(lista);
  }
  else{
    printf("Site não encontrado\n");
  }
}
