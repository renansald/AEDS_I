#include "PilhaDinamica.h"
#include <stdio.h>

void fpVazia(tipoPilha *pilha)
{
    pilha->topo = (apontador)malloc(sizeof(celula));
    pilha->fundo = pilha->topo;
    pilha->topo->prox = NULL;
}

int vazia(tipoPilha pilha)
{
    return (pilha.topo == pilha.fundo);
}

void empilha(tipoItem x, tipoPilha *pilha)
{
    apontador aux;
    aux = (apontador)malloc(sizeof(celula));
    pilha->topo->item = x;
    aux->prox = pilha->topo;
    pilha->topo = aux;
}

void desempilha (tipoPilha *pilha, tipoItem *x)
{
    apontador q;
    if (vazia(*pilha)) {
        printf("\nERROR: STACK IS EMPTY\n");
        return;
    }
    q = pilha->topo;
    pilha->topo = q->prox;
    *x = q->prox->item;
    free (q);
}

void imprime(tipoPilha p)
{
    if(vazia(p))
        return;
    printf("\n\n*********************PRINTING THE STACK ITEMS*********************\n");
    apontador aux = p.topo;
    while(aux->prox != NULL) {
        printf("%d\n", aux->prox->item.chave);
        aux = aux->prox;
    }

    printf("***************************FINISH PRINT***************************\n\n");

}

