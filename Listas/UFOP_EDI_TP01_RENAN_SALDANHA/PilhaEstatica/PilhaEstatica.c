#include "PilhaEstatica.h"


void fpVazia(tipoPilha *pilha)
{
    pilha->topo = 0;
}

int vazia(tipoPilha pilha)
{
    return (pilha.topo == 0);
}

void empilha(tipoItem x, tipoPilha *pilha)
{
    if (pilha->topo==MAX)
        printf("\nERRO: STACK IS FULL\n");
    else
    {
        pilha->topo++;
        pilha->item[pilha->topo-1] = x;
    }
}

void desempilha (tipoPilha *pilha, tipoItem *x)
{
    if (vazia(*pilha))
        printf("\nERROR: STACK IS EMPATY\n");
    else
    {
        *x = pilha->item[pilha->topo-1];
        pilha->topo--;
    }
}

void imprime(tipoPilha p)
{
    if(vazia(p))
        return;
    printf("\n\n*********************PRINTING THE STACK ITEMS*********************\n");

    int i=p.topo-1;
    while(i >= 0)
    {
        printf("%d\n", p.item[i]);
        i--;
    }

    printf("***************************FINISH PRINT***************************\n\n");
}

