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

int verificaNumeroPilha(tPilha pilha, tipoItem x){
  if(ehVazia(pilha)){
    return 0;
  }
  apontador aux = pilha.topo->proximo;
  while(aux != NULL){
    if(aux->c.item == x){
      return 1;
    }
    aux = aux->proximo;
  }
  return 0;
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

void intersecaoDePilha(tPilha pilha1, tPilha pilha2, tPilha *pilha){
  apontador aux = pilha1.topo;
  for(int i = 0; i < pilha1.cont; i++){
    aux = aux->proximo;
    if((verificaNumeroPilha(pilha2, aux->c.item)) && !(verificaNumeroPilha(*pilha, aux->c.item))){
      empilha(pilha, aux->c.item);
    }
  }
}

void diferencaPilha(tPilha pilha1, tPilha pilha2, tPilha *pilha){
  apontador aux = pilha1.topo->proximo;
  apontador aux2 = pilha2.topo->proximo;
  int int1 = pilha1.cont;
  int int2 = pilha2.cont;
  if(int1 >= int2){
    while(aux != NULL){
      if(int1 > int2){
        empilha(pilha, (aux->c.item));
        aux = aux->proximo;
        int1--;
      }
      else{
        empilha(pilha, (aux->c.item - aux2->c.item));
        aux = aux->proximo;
        aux2 = aux2->proximo;
        int2--;
        int1--;
      }
    }
    invertePilha(pilha);
  }
  else{
    while(aux2 != NULL){
      if(int2 > int1){
        empilha(pilha, -(aux2->c.item));
        aux2 = aux2->proximo;
        int2--;
      }
      else{
        empilha(pilha, (aux->c.item - aux2->c.item));
        aux2 = aux2->proximo;
        aux = aux->proximo;
        int2--;
        int1--;
      }
    }
    invertePilha(pilha);
  }
}

void pilhaOrdenada(tPilha pilha){
  apontador aux = pilha.topo->proximo;
  apontador aux2 = aux->proximo;
  if((pilha.cont == 0) || (pilha.cont == 1)){
    printf("ERRO: sua pilha contem apenas um elemento ou esta vazia\n");
  }
  else if((aux->c.item > aux2->c.item) && (aux2->proximo == NULL)){
    printf("Ordenado de forma decrescente\n");
    return;
  }
  else if((aux->c.item < aux2->c.item) && (aux2->proximo == NULL)){
    printf("Ordenado de forma crescente\n");
    return;
  }
  else if((aux->c.item > aux2->c.item) && (aux2->proximo == NULL)){
    printf("Seus itens sao iguais\n");
    return;
  }
  if(aux->c.item >= aux2->c.item){
    while(aux2->proximo != NULL){
      aux = aux->proximo;
      aux2 = aux->proximo;
      if(aux2->c.item > aux->c.item){
        break;
      }
      if(aux2->proximo == NULL){
        printf("Ordenado de forma decrescente\n");
        return;
      }
    }
  }
  if(aux->c.item <= aux2->c.item){
    while(aux2->proximo != NULL){
      aux = aux->proximo;
      aux2 = aux->proximo;
      if(aux->c.item > aux2->c.item){
        break;
      }
      if(aux2->proximo == NULL){
        printf("Ordenado de forma crescente\n");
        return;
      }
    }
  }
  printf("Seus itens estão desordenados\n");
}

void invertePilha(tPilha *pilha){
  if (ehVazia(*pilha)){
    printf("pilha vazia\n");
    return;
  }
  apontador aux = pilha->topo->proximo;
  apontador aux2 = aux;
  apontador t = pilha->topo;
  while(aux2 != NULL){
    aux2 = aux->proximo;
    aux->proximo = t;
    t = aux;
    aux = aux2;
  }
  pilha->fundo = pilha->topo->proximo;
  pilha->topo->proximo = t;
  pilha->fundo->proximo = NULL;
}
