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
    printf("\n%i", pRaiz->numero);
    exibirEmOrdem(pRaiz->direita);
  }
}

int nNos(No *pRaiz, int n){
  if (pRaiz == NULL)	{
    return (++n);
  }
  n = nNos(pRaiz->esquerda, n);
  n = nNos(pRaiz->direita, n);
  return n;
}

int Soma(No *pRaiz, int n){
  if ((pRaiz->esquerda == NULL) && (pRaiz->direita == NULL))	{
    return (n+pRaiz->numero);
  }
  if (pRaiz->esquerda != NULL) {
    n = Soma(pRaiz->esquerda, n);
  }
  if(pRaiz->direita != NULL){
    n = Soma(pRaiz->direita, n);
  }
  return (n+pRaiz->numero);
}

int Profundidade(No *pRaiz, int n){
    int k = n;
    if ((pRaiz->esquerda == NULL) && (pRaiz->direita == NULL))	{
      return n;
    }
    if (pRaiz->esquerda != NULL)
      n = Profundidade(pRaiz->esquerda, n+1);
    if (pRaiz->direita != NULL)
      k = Profundidade(pRaiz->direita, k+1);
      if(k >= n){
        return k;
      }
      else
      return n;
  }
}
