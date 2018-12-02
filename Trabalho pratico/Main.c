#include "GerarArquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  char tArquivo;
  int alternativaMenu = 0;
  while (alternativaMenu != 3) {
    while (1) {
      printf("\tMenu\n1: Criacao de arquivos\n2: Analise comparativa\n3: Sair\nInforme a opcao desejada: ");
      scanf("%d", &alternativaMenu);
      if((alternativaMenu > 0) && (alternativaMenu < 4)){
        break;
      }
      printf("As opcoes do menu vao de 1 a 3, por favor escolha uma das alternativas abaixo\n");
    }

    switch (alternativaMenu) {
      case 1:
      tipoArquivo();
      break;
      case 2:
      fazLeitura();
      break;
    }
  }
  return 0;
}
