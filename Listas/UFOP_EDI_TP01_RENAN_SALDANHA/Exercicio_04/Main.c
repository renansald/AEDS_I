#include "filaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  tipoItem *v1, *v2, *v3;
  tFila fila;
  v1 = (tipoItem*)malloc(3*sizeof(tipoItem));
  v3 = (tipoItem*)malloc(5*sizeof(tipoItem));
  v2 = (tipoItem*)malloc(5*sizeof(tipoItem));
  printf("%d", sizeof(v1)/sizeof(v1[0]));
  printf("V1\n");
  for(int i = 0; i < 5; i++){
    v1[i] = i+1;
    printf("%d\n", v1[i]);
  }
  printf("tamanho v1 %d\n", sizeof(v1));
  printf("V2\n");
  for(int i = 0; i < maxI; i++){
    v2[i] = i+1;
    printf("%d\n", v2[i]);
  }
  printf("V3\n");
  for(int i = 0; i < 5; i++){
    v3[i] = i+2;
    printf("%d\n", v3[i]);
  }
  printf("impreme se a fila ta vazia\n");
  fazFila(&fila);
  if (ehVazia(fila)) {
    printf("Fila vazia\n");
  }
  enfilera(&fila, v1, 5);
  enfilera(&fila, v2, 5);
  enfilera(&fila, v3, 5);
  printf("Imprime fila cheia\n");
  imprime(fila);
  /*desenfileira(&fila, v3, sizeof(v3)/sizeof(v3[0]));
  printf("impresão do v3 recebendo o primeiro item da fila");
  for(int i = 0; i < sizeof(v3)/sizeof(v3[0]); i++){
    printf("%d\n", v3[i]);
  }*/
  tipoItem *y;
  int z;
  y = desenfileira(&fila, &z);
  y = desenfileira(&fila, &z);
  y = desenfileira(&fila, &z);
  printf("\n\n\n\n\n\n\n%d\n\n\n\n\n\n\n", sizeof(y)/sizeof(tipoItem));
  printf("Imprime y\n");
  for(int i =0 ; i < z; i++){
    printf("%d\n", y[i]);
  }
  printf("fila\n");
  imprime(fila);



  return 0;
}
