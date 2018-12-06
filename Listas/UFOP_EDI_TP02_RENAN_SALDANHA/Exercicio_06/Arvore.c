#include "Arvore.h"
#include <stdio.h>
#include <stdlib.h>

void criarArvore(No **pRaiz){
  *pRaiz = NULL;
}

void insercao(No **pRaiz, int numero2){
  if (*pRaiz == NULL)	{
    (*pRaiz)=(apontador)malloc(sizeof (No));
    (*pRaiz)->esquerda=NULL;
    (*pRaiz)->direita=NULL;
    (*pRaiz)->numero=numero2;
  }
  else{
    if (numero2 < ((*pRaiz)->numero)){
      insercao(&((*pRaiz)->esquerda), numero2);
    }
    else{
      insercao(&((*pRaiz)->direita), numero2);
    }
  }
}

void insercaoEspelho(No **pRaiz, int numero2){
  if (*pRaiz == NULL)	{
    (*pRaiz)=(apontador)malloc(sizeof (No));
    (*pRaiz)->esquerda=NULL;
    (*pRaiz)->direita=NULL;
    (*pRaiz)->numero=numero2;
  }
  else{
    if (numero2 > ((*pRaiz)->numero)){
      insercaoEspelho(&((*pRaiz)->esquerda), numero2);
    }
    else{
      insercaoEspelho(&((*pRaiz)->direita), numero2);
    }
  }
}

void exibirEmOrdem(No *pRaiz){
  if(pRaiz != NULL){
    exibirEmOrdem(pRaiz->esquerda);
    printf("\n%d", pRaiz->numero);
    exibirEmOrdem(pRaiz->direita);
  }
}

int espelho(apontador a, apontador a1){
  int x;
  if((a->esquerda == NULL) && (a->direita == NULL) && (a1->esquerda == NULL) && (a1->direita == NULL) && (a1->numero == a->numero)){
    return 1;
  }
  else if(((a->esquerda == NULL) && (a1->direita != NULL)) || ((a->esquerda != NULL) && (a1->direita == NULL)) || ((a1->esquerda == NULL) && (a->direita != NULL)) || ((a1->esquerda != NULL) && (a->direita == NULL)) || (a->numero != a1->numero)){
    return 0;
  }
  x = espelho(a->esquerda, a1->direita);
  if(x == 0)
  return 0;
  x = espelho(a->direita, a1->esquerda);
  if(x == 0)
  return 0;
  return x;
}
