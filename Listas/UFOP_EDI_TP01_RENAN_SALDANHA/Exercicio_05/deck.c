#include "deck.h"
#include <stdio.h>

void fazDeque(Deque *d){
  d->primeiroEsq = 0;
  d->finalEsq = 0;
  d->primeiroDir = Max-1;
  d->finalDir = Max-1;
}

int ehVazio(Deque d){
  return((d.primeiroEsq == d.finalEsq) && (d.primeiroDir == d.finalDir));
}

void InsDir(Deque *d, tipoItem x){
  if((d->finalEsq - 1 == d->finalDir) || (d->finalDir + 1 == d->finalEsq)){
    printf("Deque cheio\n");
    return;
  }
  int aux = d->finalDir;
  while(aux < d->primeiroDir){
    d->dek[aux] = d->dek[aux+1];
    aux++;
  }
  d->dek[d->primeiroDir] = x;
  d->finalDir = d->finalDir - 1;
}

void InsEsq(Deque *d, tipoItem x){
  if((d->finalEsq - 1 == d->finalDir) || (d->finalDir + 1 == d->finalEsq)){
    printf("Deque cheio\n");
    return;
  }
  int aux = d->finalEsq;
  while(aux > d->primeiroEsq){
    d->dek[aux] = d->dek[aux-1];
    aux--;
  }
  d->dek[d->primeiroEsq] = x;
  d->finalEsq = d->finalEsq + 1;
}

void RemDir(Deque *d, tipoItem *x){
  if(ehVazio(*d)){
    printf("O deque está vazio\n");
    return;
  }
  if(d->finalDir == d->primeiroDir){
    *x = d->dek[d->finalEsq - 1];
    d->finalEsq--;
    return;
  }
  *x = d->dek[d->primeiroDir];
  int aux = d->primeiroDir - 1;
  while (aux > d->finalDir) {
    d->dek[aux +1] = d->dek[aux];
    aux--;
  }
  d->finalDir++;
  /*d->primeiroDir--;
  if(d->primeiroDir == d->primeiroEsq - 1){
    d->primeiroDir = Max - 1;
    d->finalDir = Max - 1;
    d->primeiroEsq = 0;
    d->finalEsq = 0;
  }*/
}

void RemEsq(Deque *d, tipoItem *x){
  if(ehVazio(*d)){
    printf("O deque está vazio\n");
    return;
  }
  if(d->finalEsq == d->primeiroEsq){
    *x =d->dek[d->finalDir + 1];
    d->finalDir++;
    return;
  }
  *x = d->dek[d->primeiroEsq];
  int aux = d->primeiroEsq;
  while (aux < d->finalEsq-1) {
    d->dek[aux] = d->dek[aux+1];
    aux++;
  }
  d->finalEsq--;
  /*d->primeiroEsq++;
  if(d->primeiroEsq == d->primeiroDir + 1){
    d->primeiroDir = Max - 1;
    d->finalDir = Max - 1;
    d->primeiroEsq = 0;
    d->finalEsq = 0;
  }*/
}

void imprimeDeque(Deque d){
  if(ehVazio(d)){
    printf("Deque vazio\n");
    return;
  }
  int aux = d.primeiroEsq;
  while(aux < d.finalEsq){
    printf("%d\n", d.dek[aux]);
    aux++;
  }
  aux = d.finalDir;
  while (aux < d.primeiroDir) {
    printf("%d\n", d.dek[aux+1]);
    aux++;
  }
  /*for(int aux = d.primeiroEsq; aux <= d.primeiroDir; aux++){
    printf("%d\n", d.dek[aux]);
  }*/
}
