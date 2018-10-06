#include "pilhaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  tPilha pilha, pilha2, pilha3, pilha4;
  tipoItem x, y, z;
  printf("Teste com a PILHA\n\n");
  fazPilha(&pilha);
  fazPilha(&pilha2);
  fazPilha(&pilha3);
  fazPilha(&pilha4);
  printf("Imprime se a pilha ta vazia");
  if(ehVazia(pilha)){
    printf("Pilha vazia\n");
  }
  empilha(&pilha, 1);
  empilha(&pilha, 2);
  empilha(&pilha, 3);
  printf("Imprime pilha\n");
  imprimePilha(pilha);
  desempilha(&pilha, &x);
  printf("x = %d\n", x);
  printf("Nova pilha\n");
  imprimePilha(pilha);
  verificaNumeroPilha(pilha, 2);
  verificaNumeroPilha(pilha, 5);
  cpyPilha(pilha, &pilha2);
  printf("Imprime copia da pilha\n");
  imprimePilha(pilha2);
  empilha(&pilha, 10);
  empilha(&pilha, 20);
  printf("Pilha 1\n");
  imprimePilha(pilha);
  concatenaPilha(pilha, pilha2, &pilha3);
  printf("Imprime pilhas concatenadas\n");
  imprimePilha(pilha3);
  intercalaPilha(pilha, pilha2, &pilha4);
  printf("Imprime pilha1 intercalda com pilha2\n");
  imprimePilha(pilha4);
  return 0;
}
