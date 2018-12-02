#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED

typedef int tipoChave;
typedef struct {
  tipoChave chave;
} tipoItem;

typedef struct celula *apontador;

typedef struct celula {
  tipoItem item;
  apontador prox;
} celula;

typedef struct tipoPilha{
  apontador fundo, topo;
  int Tamanho;
} tipoPilha;


void fpVazia(tipoPilha *pilha);
int vazia(tipoPilha pilha);
void empilha(tipoItem x, tipoPilha *pilha);
void desempilha (tipoPilha *pilha, tipoItem *x);
void imprime(tipoPilha p);

#endif // PILHAESTATICA_H_INCLUDED
