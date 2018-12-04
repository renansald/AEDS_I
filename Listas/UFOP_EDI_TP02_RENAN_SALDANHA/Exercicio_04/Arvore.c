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

int verificaEstritamenteBinaria(apontador a, int n, int v){
  int x;
  int pAtual = v;
  if (((a->esquerda == NULL) && (a->direita != NULL)) || ((a->esquerda != NULL) && (a->direita == NULL))){
    return 0;
  }
  else if((a->esquerda == NULL) && (a->direita == NULL)){
    return 1;
  }
  x = verificaEstritamenteBinaria(a->esquerda, n, (v+1));
  if(x == 0)
  return 0;
  x = verificaEstritamenteBinaria(a->direita, n, (v+1));
  if(x==0)
  return 0;
}

int nNos(No *pRaiz, int n){
  if (pRaiz == NULL)	{
    return (++n);
  }
  n = nNos(pRaiz->esquerda, n);
  n = nNos(pRaiz->direita, n);
  return n;
}

int verificaCompleta(apontador a, int n, int v){
  int x, y;
  int pAtual = v;
  if (((a->esquerda == NULL) || (a->direita == NULL)) && (pAtual <= n-2)){
    return 0;
  }
  if(((a->esquerda == NULL) || (a->direita == NULL)) && (pAtual >= (n-1))){
    return 1;
  }
  if(a->esquerda != NULL)
  x = verificaCompleta(a->esquerda, n, (v+1));
  y = verificaCompleta(a->direita, n, (v+1));
  if((x == 0) || (y == 0)){
    return 0;
  }
  return 1;
}

int verificarCheia(apontador a, int n, int v){
  int x, y;
  int pAtual = v;
  if(((a->esquerda == NULL) || (a->direita == NULL)) && (pAtual != n))
    return 0;
  else if(((a->esquerda == NULL) || (a->direita == NULL)) && (pAtual == n))
    return 1;
    x = verificarCheia(a->esquerda, n, v+1);
    y = verificarCheia(a->direita, n, v+1);
    if((x == 0) || (y == 0)){
      return 0;
    }
    return 1;
}
