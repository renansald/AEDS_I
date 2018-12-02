#include <stdio.h>
#include <stdlib.h>
#include "PilhaEstatica.h"

int main()
{
    tipoPilha p1;
    fpVazia(&p1);

    tipoItem x;
    x.chave = 10;
    empilha(x, &p1);
    x.chave = 11;
    empilha(x, &p1);

    imprime(p1);

    int eHvazia = vazia(p1);
    if(eHvazia)
        printf("Test: Stack is empty!");
    else
        printf("Test: Stack is not empty!");

    desempilha(&p1, &x);

    imprime(p1);

    return 0;
}
