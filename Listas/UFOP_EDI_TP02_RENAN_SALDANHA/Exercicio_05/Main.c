#include "Arvore.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  apontador a, a1;
  criarArvore(&a);
  criarArvore(&a1);
  insercao(&a, 9);
  insercao(&a, 4);
  insercao(&a, 11);
  insercao(&a, 2);
  insercao(&a, 5);
  insercao(&a, 10);
  insercao(&a, 15);
  insercao(&a, 27);
  insercao(&a, 13);
  insercao(&a, 18);
  insercao(&a1, 9);
  insercao(&a1, 4);
  insercao(&a1, 11);
  insercao(&a1, 3);
  insercao(&a1, 5);
  insercao(&a1, 10);
  insercao(&a1, 15);
  insercao(&a1, 27);
  insercao(&a1, 13);
  insercao(&a1, 18);
  if(similaridade(a, a1)==1)
  printf("Similares\n");
  else
  printf("Não são nada\n");
  return 0;
}
