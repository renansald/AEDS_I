#include "deck.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  Deque d;
  tipoItem a = 2;
  tipoItem b = 1;
  fazDeque(&d);
  if(ehVazio(d)){
    printf("Deque vazio\n");
  }
  imprimeDeque(d);
  InsDir(&d, 1);
  InsDir(&d, 2);
  InsDir(&d, 3);
  InsDir(&d, 4);
  InsEsq(&d, 5);
  InsEsq(&d, 6);
  InsEsq(&d, 7);
  printf("IMPRIME DEQUE CHEIO\n");
  imprimeDeque(d);
  InsEsq(&d, a);
  InsDir(&d, b);
  //RemDir(&d, &a);
  //printf("Item removido da direita %d\n", a);
  RemEsq(&d, &b);
  //printf("Item removido da Esquerda %d\n", b);
  //printf("IMPRIME NOVO DEQUE\n");
  //imprimeDeque(d)
  RemEsq(&d, &a);
  RemEsq(&d, &a);
  RemEsq(&d, &b);
  RemEsq(&d, &b);
  printf("\n%d\n", b);
  RemEsq(&d, &a);
  RemEsq(&d, &b);
  RemDir(&d, &b);
  RemEsq(&d, &a);
  printf("ulitmo direita = %d\nPrimeiro direita = %d\nUltimo esquerda = %d\nPrimeiro esquerda = %d\n", d.finalDir, d.primeiroDir, d.finalEsq, d.primeiroEsq);
  printf("erro a partir daqui\n");
  RemDir(&d, &a);
  RemEsq(&d, &b);
  return 0;
}
