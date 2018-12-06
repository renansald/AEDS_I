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

int RemoveElemento(apontador *a, int x){
  int w = 0;
  apontador l = (*a)->esquerda;
  apontador r = (*a)->direita;
  if(((*a)->numero) == x){
    if(((*a)->esquerda) != NULL){
      apontador y;
      y = elementoDireita((((*a)->esquerda)));
      ((*a)->numero) = y->numero;
      free(y);
      return 1;
    }
    else if(((*a)->direita) == NULL){
      (*a) = NULL;
      return 1;
    }
    else{
      apontador aux = (*a)->direita;
      (*a)->numero = aux->numero;
      (*a)->direita = aux->direita;
      (*a)->esquerda = aux->esquerda;
      free(aux);
      return 1;
    }
  }
  else if(l->numero == x){
    if((l->esquerda) != NULL){
      apontador y;
      y = elementoDireita((l)->esquerda);
      if(l->esquerda->direita == NULL){
        l->numero = y->numero;
        y->esquerda = NULL;
        y->direita = l->direita;
        (*a)->esquerda = y;
        free(l);
        return 1;
      }
      l->numero = y->numero;
      y->esquerda = l->esquerda;
      y->direita = l->direita;
      (*a)->esquerda = y;
      free(l);
      return 1;
    }
    if(l->direita == NULL){
      free(l);
      (*a)->esquerda = NULL;
      return 1;
    }
    else{
      (*a)->esquerda = l->direita;
      return 1;
    }
  }
  else if(r->numero == x){
    if((r->esquerda) != NULL){
      apontador y;
      y = elementoDireita((r)->esquerda);
      if(r->esquerda->direita == NULL){
        r->numero = y->numero;
        y->esquerda = NULL;
        y->direita = r->direita;
        (*a)->direita = y;
        free(r);
        return 1;
      }
      r->numero = y->numero;
      y->esquerda = r->esquerda;
      (*a)->direita = y;
      free(r);
      return 1;
      y->direita = r->direita;
    }
    if(r->direita == NULL){
      free(r);
      (*a)->direita = NULL;
      return 1;
    }
    else{
      (*a)->direita = r->direita;
      return 1;
    }
  }
  if((l->esquerda) != NULL)
  w = RemoveElemento(&l, x);
  if(w == 1)
  return 1;
  if((r->direita) != NULL)
  w = RemoveElemento(&r, x);
  if(w == 1)
  return 1;
  return 0;
}

apontador elementoDireita(apontador a){
  apontador aux = NULL;
  if(a->direita == NULL){
    return a;
  }
  else if(((a)->direita->direita == NULL)){
    aux = (a->direita);
    (a)->direita = a->direita->esquerda;
    return aux;
  }
  aux = elementoDireita((a->direita));
  return aux;
}
