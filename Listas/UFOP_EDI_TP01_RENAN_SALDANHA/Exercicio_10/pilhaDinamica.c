#include "pilhaDinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void fazPilha(tPilha *pilha){
  pilha->fundo = (apontador)malloc(sizeof(celula));
  pilha->topo = pilha->fundo;
  pilha->fundo->proximo = NULL;
  pilha->count = 0;
}

int ehVazia(tPilha pilha){
  return (pilha.fundo == pilha.topo);
}

void empilha(tPilha *pilha, char c[]){
  int n = 0;
  apontador aux;
  while(c[n] != '\0'){
    aux = (apontador)malloc(sizeof(celula));
    aux->proximo = pilha->topo;
    pilha->topo->l.letra = c[n];
    pilha->topo = aux;
    pilha->count++;
    n++;
  }
}

void imprime(tPilha pilha){
  if(ehVazia(pilha)){
    printf("Pilha Vazia\n");
    return;
  }
  apontador aux = pilha.topo->proximo;
  while(aux != NULL){
    printf("%c", aux->l.letra);
    aux= aux->proximo;
  }
  printf("\n");
}

void palindrome(tPilha pilha, char c[]){
  apontador aux = pilha.topo->proximo;
  char c2[1000];
  for(int i = 0; aux != NULL; i++){
    c2[i] = aux->l.letra;
    aux = aux->proximo;
  }
  int n = 0;
  for(int i = 0; c[i] != '\0'; i++){
    if((c[i] == ' ') || (c[i] == '.') || (c[i] == ',')){
      continue;
    }
    c[n] = (toupper (c[i]));
    n++;
  }
  n = 0;
  for(int i = 0; c2[i] != '\0'; i++){
    if((c2[i] == ' ') || (c2[i] == '.') || (c2[i] == ',')){
      continue;
    }
    c2[n] = (toupper (c2[i]));
    n++;
  }
  for (int i = 0; c[i] != '\0'; i++) {
    if(c[i] != c2[i]){
      printf("Nao e palindrome\n");
      return;
    }
  }
  printf("E palindrome\n");
}
