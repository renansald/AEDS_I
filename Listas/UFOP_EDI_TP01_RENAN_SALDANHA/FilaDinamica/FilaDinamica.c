#include "FilaDinamica.h"
#include <stdio.h>

void ffVazia(tipoFila *fila)
{
    fila->frente =(apontador)malloc(sizeof(celula));
    fila->tras = fila->frente;
    fila->frente->prox = NULL;
}

int vazia(tipoFila fila)
{
    return (fila.frente == fila.tras);
}

void enfileira(tipoItem x, tipoFila *fila)
{
    fila->tras->prox = (apontador)malloc(sizeof(celula));
    fila->tras = fila->tras->prox;
    fila->tras->item = x;
    fila->tras->prox = NULL;
}
void desenfileira( tipoFila *fila, tipoItem *item)
{
    apontador q;
    if (vazia (*fila))
    {
        printf("ERRO: THIS QUEUE IS EMPTY!");
        return;
    }
    q = fila->frente;
    fila->frente = fila->frente->prox;
    *item = fila->frente->item;
    free (q);
}

void imprime(tipoFila fila)
{
    if(vazia(fila))
        return;
    printf("\n\n*********************PRINTING THE QUEUE ITEMS*********************\n");
    apontador aux = fila.frente;
    while(aux->prox != NULL) {
        printf("%d,", aux->prox->item.chave);
        aux = aux->prox;
    }

    printf("\n***************************FINISH PRINT***************************\n\n");
}
