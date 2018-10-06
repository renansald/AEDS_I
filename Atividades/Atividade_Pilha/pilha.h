#include <stdio.h>
#include <stdlib.h>

#define max 20
#define  limite 19

typedef struct Pilha{
  int matricula[max];
  int topo;
} Pilha;

void criaPilha(Pilha *pilha);
int checaPilha(Pilha pilha);
void listaPilha(Pilha pilha);
void empilha(Pilha *pilha, int numero);
int desempilha(Pilha *pilha);
