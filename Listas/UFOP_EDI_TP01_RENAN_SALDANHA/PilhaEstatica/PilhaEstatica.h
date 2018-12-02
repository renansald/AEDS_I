#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED

#define MAX 10



typedef int tipoChave;

typedef int apontador;

typedef struct {
    tipoChave chave;
    //outros componentes
}tipoItem;

typedef struct{
    tipoItem item[MAX];
    apontador topo;
}tipoPilha;

void fpVazia(tipoPilha *pilha);
int vazia(tipoPilha pilha);
void empilha(tipoItem x, tipoPilha *pilha);
void desempilha (tipoPilha *pilha, tipoItem *x);
void imprime(tipoPilha p);

#endif // PILHAESTATICA_H_INCLUDED
