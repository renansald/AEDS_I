#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
  Pilha pilha;
  int matricula = 1;
  criaPilha(&pilha);
  if(checaPilha(pilha))
  printf("pilha vazia\n");
  for (int i = 0; i <= 21; i++){
    empilha(&pilha, matricula);
    matricula++;
  }
  listaPilha(pilha);
  if(checaPilha(pilha))
  printf("pilha vazia\n");
  else
  printf("pilha cheia\n");
  int x;
  for(int i = 0; i < 20; i++){
    x = desempilha(&pilha);
  }
  listaPilha(pilha);
  if(checaPilha(pilha))
  printf("pilha vazia\n");
  else
  printf("pilha cheia\n");
  printf("%d\n", x);
  for (int i = 0; i <= 10; i++){
    empilha(&pilha, matricula);
    matricula++;
  }
  listaPilha(pilha);
}
