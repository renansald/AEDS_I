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

int nNos(No *pRaiz, int n){
  if (pRaiz == NULL)	{
    return (++n);
  }
  n = nNos(pRaiz->esquerda, n);
  n = nNos(pRaiz->direita, n);
  return n;
}

void verificaSimilaridade(apontador a, apontador a1){
  if ((nNos(a, 1) != nNos(a1, 1)) && (Profundidade(a, -1) == Profundidade(a1, -1))) {
    printf("Arvores não similares\n");
    return;
  }
  if(similaridade(a, a1) == 1){
    printf("São similares\n");
  }
  else{
    printf("Arvores não similares\n");
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

void verificarEspelho(apontador a, apontador a1){
  if((nNos(a, -1)%2==0) || ((nNos(a1, -1)%2==0))){
    printf("Não são espelho\n");
    return;
  }
  int x = nNos(a, -1);
  int z = nNos(a1, -1);
  int *v = (int*)malloc(x*sizeof(int));
  int *w = (int*)malloc(z*sizeof(int));
  int y = 0;
  int k = 0;
  espelho(a, v, &y);
  espelho(a1, w, &k);
  //for (int i = 0; i < x; i++) {
  //  printf("%d||%d\n", v[i], w[i]);
  //}
  for (int i = 0; i < (x-1); i++) {
    if(v[i] != v[((x-1)/2)+i]){
      y = -1;
      break;
    }
  }
  for (int i = 0; i < (z-1); i++) {
    if(w[i] != w[((z-1)/2)+i]){
      z = -1;
      break;
    }
  }
  if((y != -1) && (z != -1)){
    printf("São arvores espelho\n");
    return;
  }
  else if((y == -1) && (z != -1)){
    printf("Somente a segunda arvore é espelho\n");
    return;
  }
  else if((y != -1) && (z == -1)){
    printf("Somente a primeira arvore é espelho\n");
    return;
  }
  else
  printf("Não são espelho\n");
}

void espelho(apontador a, int *v, int *x){
  if((a->esquerda == NULL) && (a->direita == NULL)){
    v[*x] = a->numero;
    ++*x;
    return;
  }
  if(a->esquerda != NULL)
  espelho(a->esquerda, v, x);
  if(a->direita != NULL)
  espelho(a->direita, v, x);
  v[*x] = a->numero;
  ++*x;
  return;
}
