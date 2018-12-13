#include "Arvore.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  No *a;
  int nos = 0;
  int soma;
  criarArvore(&a);
  insercao(&a, 9);
  insercao(&a, 4);
  insercao(&a, 11);
  insercao(&a, 2);
  insercao(&a, 5);
  insercao(&a, 10);
  insercao(&a, 15);
  //insercao(&a, 27);
  //insercao(&a, 13);
  //insercao(&a, 18);
  exibirEmOrdem(a);
  int no = Profundidade(a, 1);
  printf("\n%d\n", no);
  if(verificaEstritamenteBinaria(a) == 1){
    printf("Arvore Estritamente binaria\n");
  }
  if(verificaCompleta(a, Profundidade(a, 1)) == 1){
    printf("Arvore Completa\n");
  }
  if(verificarCheia(a, no) == 1){
    printf("Arvore cheia\n");
  }
  //printf("\n\n%d\n\n%d\n\n%d", nos, soma, altura)
  return 0;
}
