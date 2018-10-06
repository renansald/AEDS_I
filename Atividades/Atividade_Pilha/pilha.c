#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

void criaPilha(Pilha *pilha){
  pilha->topo = 0;
}

int checaPilha(Pilha pilha){
  return (pilha.topo == 0);
}

void listaPilha(Pilha pilha){
  if (pilha.topo > 0){
    for(int i = (pilha.topo - 1); i >= 0; i--){
      printf("%d\n", pilha.matricula[i]);
    }
  }
  else
  printf("Pilha Vazia\n");
}

void empilha(Pilha *pilha, int numero){
  if(pilha->topo <= (limite)){
    pilha->matricula[pilha->topo] = numero;
    pilha->topo++;
  }
  else
printf("Pilha cheia\n");
}

int desempilha(Pilha *pilha){
  if(pilha->topo >= 0){
    pilha->topo--;
    return pilha->matricula[(pilha->topo)];
  }
  else
printf("Pilha vazia\n");
}
