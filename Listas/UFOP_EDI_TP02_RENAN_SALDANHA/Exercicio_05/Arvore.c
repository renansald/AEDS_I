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

void exibirEmOrdem(No *pRaiz){
  if(pRaiz != NULL){
    exibirEmOrdem(pRaiz->esquerda);
    printf("\n%d", pRaiz->numero);
    exibirEmOrdem(pRaiz->direita);
  }
}

int similaridade(apontador a, apontador a1){
  int x;
  if((a->numero != a1->numero) || ((a->direita == NULL) && (a1->direita !=NULL)) || ((a->direita != NULL) && (a1->direita ==NULL)) || ((a->esquerda == NULL) && (a1->esquerda !=NULL)) || (((a->direita != NULL) && (a1->direita ==NULL)))){
    return 0;
  }
  else if((a->esquerda == NULL) && (a->direita == NULL) && (a1->esquerda == NULL) && (a1->direita == NULL)){
    return 1;
  }
  if(a->esquerda != NULL)
  x = similaridade(a->esquerda, a1->esquerda);
  if(x == 0)
  return x;
  if(a->direita != NULL)
  x = similaridade(a->direita, a1->direita);
  return x;
}
