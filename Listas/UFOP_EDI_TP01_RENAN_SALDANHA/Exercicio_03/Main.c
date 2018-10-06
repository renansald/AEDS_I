//#include "pilhaDefilasEstatica.h"
//#include "filaDePilhasEstatica.h"
#include "filaDeFilas.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  /*tPilha p1, p2, p3;
  tFila fila;
  printf("Testa library filaDePilhasEstatica:\n");
  fazPilha(&p1);
  fazPilha(&p2);
  fazPilha(&p3);
  fazFilaDePilhas(&fila);
  if(verificaFilaVazia(fila))
  printf("Fila vazia\n");
  if(verificaPilhavazia(p1))
  printf("P1 vazia\n");
  if(verificaPilhavazia(p2))
  printf("P2 vazia\n");
  if(verificaPilhavazia(p3))
  printf("P3 vazia\n");
  for(int i = 0; i < 2; i++){
    empilha(&p1, i);
    empilha(&p2, i+1);
  }
  printf("Imprime p1\n");
  imprimePilha(p1);
  printf("Imprime p2\n");
  imprimePilha(p2);
  printf("Imprime p3\n");
  imprimePilha(p3);
  printf("Imprime fila vazia\n");
  imprimeFiladePilha(fila);
  enfileraPilha(&fila, p3);
  enfileraPilha(&fila, p2);
  enfileraPilha(&fila, p1);
  printf("imprime fila de pilhas\n");
  imprimeFiladePilha(fila);
  desenfileraPilha(&fila, &p3);
  printf("fila\n");
  imprimeFiladePilha(fila);
  printf("p3\n");
  imprimePilha(p3);
  printf("p1\n");
  imprimePilha(p1);
  printf("Final de testa library filaDePilhasEstatica\n\n\n");
  /*printf("Teste library pilhaDefilasEstatica\n");
  tFila f1, f2, f3;
  tPilha pilha;
  fazFila(&f1);
  fazFila(&f2);
  fazFila(&f3);
  if(filaVazia(f1))
  printf("F1 vazia\n");
  if(filaVazia(f2))
  printf("F2 vazia\n");
  if(filaVazia(f3))
  printf("F3 vazia\n");
  fazPilhadeListas(&pilha);
  if(pilhaVazia(pilha))
  printf("Pilha Vazia\n");
  for(int i = 0; i < 3; i++){
    enfilera(&f1, i);
    enfilera(&f2, i+1);
  }
  printf("Fila f1\n");
  imprimeFila(f1);
  printf("Fila f2\n");
  imprimeFila(f2);
  printf("Fila f3\n");
  imprimeFila(f3);
  printf("Pilha\n");
  imprimePilhadeFilas(pilha);
  empilhaFila(&pilha, f1);
  empilhaFila(&pilha, f2);
  empilhaFila(&pilha, f3);
  printf("Imprime a pilha com 3 filas\n");
  imprimePilhadeFilas(pilha);
  tipoItem y;
  for(int i = 0; i < 3; i++){
    desenfilera(&f1, &y);
  }
  desempilhaFila(&pilha, &f1);
  desempilhaFila(&pilha, &f3);
  printf("imprime f1\n");
  imprimeFila(f1);
  printf("imprime f3\n");
  imprimeFila(f3);
  printf("imprime f2\n");
  imprimeFila(f2);
  printf("imprime pilha\n");
  imprimePilhadeFilas(pilha);*/

  printf("Teste library filaDeFilas\n");
  tFila f1, f2, f3;
  tFilas fila;
  fazFilaF(&fila);
  fazFila2(&f1);
  fazFila2(&f2);
  fazFila2(&f3);
  if(ehVaziaFF(fila))
    printf("\n\nffila é vazia\n");
  if(ehVazia(f1))
    printf("\n\nf1 é vazia\n");
  if(ehVazia(f2))
    printf("\n\nf2 é vazia\n");
  if(ehVazia(f3))
    printf("\n\nf3 é vazia\n");
  for(int i = 0; i < 6; i++){
    enfilera2(&f1, i);
    enfilera2(&f2, i+1);
  }
  printf("\n\nf1\n");
  imprime(f1);
  printf("\n\nf2\n");
  imprime(f2);
  printf("\n\nf3\n");
  imprime(f3);
  printf("\n\nffila\n");
  imprimef(fila);
  enfileraF(&fila, f1);
  enfileraF(&fila, f2);
  enfileraF(&fila, f3);
  printf("\n\nimprime ffila cheia\n");
  imprimef(fila);
  printf("\n\nf1\n");
  imprime(f1);
  printf("\n\nf2\n");
  imprime(f2);
  printf("\n\nf3\n");
  imprime(f3);
  desenfileraf(&fila, &f3);
  printf("\n\nimprime ffila desempilhada\n");
  imprimef(fila);
  printf("\n\nf1\n");
  imprime(f1);
  printf("\n\nf2\n");
  imprime(f2);
  printf("\n\nf3\n");
  imprime(f3);
  printf("Final de testa library filaDeFilas\n\n\n");

  return 0;
}
