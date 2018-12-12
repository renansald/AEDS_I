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
    return (n);
  }
  n++;
  n = nNos(pRaiz->esquerda, (n));
  n = nNos(pRaiz->direita, (n));
  return n;
}

int Profundidade(No *pRaiz){
  int k = 0;
  int n = 0;
  if(pRaiz == NULL){
    return 0;
  }
  if ((pRaiz->esquerda == NULL) && (pRaiz->direita == NULL))	{
    return 1;
  }
  if (pRaiz->esquerda != NULL)
    n += Profundidade(pRaiz->esquerda);
  if (pRaiz->direita != NULL)
    k += Profundidade(pRaiz->direita);
    if(k >= n){
      return k + 1;
    }
    else
    return n + 1;
}

int Soma(No *pRaiz){
  int n = 0;
  if ((pRaiz->esquerda == NULL) && (pRaiz->direita == NULL))	{
    return (pRaiz->numero);
  }
  if (pRaiz->esquerda != NULL) {
    n+= Soma(pRaiz->esquerda);
  }
  if(pRaiz->direita != NULL){
    n+= Soma(pRaiz->direita);
  }
  return (n+pRaiz->numero);
}
