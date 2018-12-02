#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

int main()
{
    tipoFila f1;
    ffVazia(&f1);

    tipoItem x;
    x.chave = 10;
    enfileira(x, &f1);
    x.chave = 11;
    enfileira(x, &f1);

    imprime(f1);

    int eHvazia = vazia(f1);
    if(eHvazia)
        printf("Test: Queue is empty!");
    else
        printf("Test: Queue is not empty!");

    desenfileira(&f1, &x);

    imprime(f1);

    return 0;
}
