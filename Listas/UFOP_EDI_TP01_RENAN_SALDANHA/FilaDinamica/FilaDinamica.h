#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED

typedef int tipoChave;
typedef struct {
  tipoChave chave;
} tipoItem;

typedef struct celula *apontador;

typedef struct celula {
  tipoItem item;
  apontador prox;
} celula;

typedef struct tipoFila{
  apontador frente, tras;
  int Tamanho;
} tipoFila;


void ffVazia(tipoFila *fila);
int vazia(tipoFila fila);
void enfileira(tipoItem x, tipoFila *fila);
void desenfileira (tipoFila *fila, tipoItem *x);
//void concatena(tipoPilha *p1, tipoFila *p2);
void imprime(tipoFila fila);

#endif // PILHAESTATICA_H_INCLUDED
