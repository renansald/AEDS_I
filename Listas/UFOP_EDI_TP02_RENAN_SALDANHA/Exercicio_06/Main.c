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
  //insercao(&a, 18);
  insercaoEspelho(&a1, 9);
  insercaoEspelho(&a1, 4);
  insercaoEspelho(&a1, 11);
  insercaoEspelho(&a1, 2);
  insercaoEspelho(&a1, 5);
  insercaoEspelho(&a1, 10);
  insercaoEspelho(&a1, 15);
  insercaoEspelho(&a1, 27);
  insercaoEspelho(&a1, 13);
  //insercao(&a1, 18);
  if(espelho(a, a1) == 1){
    printf("Eh espelho\n");
  }
  else
  printf("Não é espelho\n");
  return 0;
}
