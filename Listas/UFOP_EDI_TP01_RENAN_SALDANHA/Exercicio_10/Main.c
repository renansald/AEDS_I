#include "pilhaDinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  char frase[1000];
  tPilha pilha;
  printf("Informe a frase: ");
  scanf("%[^\n]s", frase);
  fazPilha(&pilha);
  printf("Imprime se a fila é vazia\n");
  if(ehVazia(pilha))
  printf("Pilha vazia\n");
  empilha(&pilha, frase);
  printf("Imprime a frase de tras pra frente\n");
  imprime(pilha);
  palindrome(pilha, frase);
  return 0;
}
