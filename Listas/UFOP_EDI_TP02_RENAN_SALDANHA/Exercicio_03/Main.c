#include "Arvore.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  No *a;
  int n = 9;
  int g = 4;
  int h = 11;
  int k = 2;
  int j = 5;
  int v = 10;
  int r = 12;
  int nos = 0;
  int soma;
  criarArvore(&a);
  insercao(&a, n);
  insercao(&a, g);
  insercao(&a, h);
  insercao(&a, k);
  insercao(&a, j);
  insercao(&a, v);
  insercao(&a, r);
  insercao(&a, 27);
  exibirEmOrdem(a);
  int altura;
  nos = nNos(a, -1);
  printf("Contei nos");
  soma = Soma(a, 0);
  printf("Somei");
  altura = Profundidade(a, 1);
  printf("\n\n%d\n\n%d\n\n%d", nos, soma, altura);
  return 0;
}
