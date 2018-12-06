#include "Arvore.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  apontador a, a1;
  criarArvore(&a);
  criarArvore(&a1);
  insercao(&a, 9);
  //insercao(&a, 4);
  insercao(&a, 11);
  //insercao(&a, 2);
  //insercao(&a, 5);
  insercao(&a, 10);
  insercao(&a, 15);
  insercao(&a, 27);
  insercao(&a, 13);
  exibirEmOrdem(a);
  if(RemoveElemento(&a, 9) == 1){
    printf("\nElemento removido com sucesso\n");
  }
  else
  printf("Elemnto não removido\n");
  exibirEmOrdem(a);
  return 0;
}
