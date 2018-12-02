#include "pilhaDinamica.h"
#include "filaDinamica.h"
#include "listaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  tPilha pilha, pilha2, pilha3, pilha4, pilha5, pilha6;
  tipoItem x, y, z;
  printf("TESTE COM A PILHA\n\n");
  fazPilha(&pilha);
  fazPilha(&pilha2);
  fazPilha(&pilha3);
  fazPilha(&pilha4);
  fazPilha(&pilha5);
  fazPilha(&pilha6);
  printf("Imprime se a pilha ta vazia");
  if(ehVazia(pilha)){
    printf("Pilha vazia\n");
  }
  empilha(&pilha, 1);
  empilha(&pilha, 2);
  empilha(&pilha, 3);
  printf("Imprime pilha\n");
  imprimePilha(pilha);
  printf("Nova pilha\n");
  imprimePilha(pilha);
  if(verificaNumeroPilha(pilha, 2))
  printf("O numero 2 existe na pilha\n");
  else
  printf("O numero 2 nao existe na pilha\n");
  if(verificaNumeroPilha(pilha, 5))
    printf("O numero 5 existe na pilha\n");
  else
  printf("O numero 5 nao existe na pilha\n");
  cpyPilha(pilha, &pilha2);
  printf("Imprime copia da pilha\n");
  imprimePilha(pilha2);
  empilha(&pilha, 10);
  empilha(&pilha, 20);
  printf("Pilha 1\n");
  imprimePilha(pilha);
  concatenaPilha(pilha, pilha2, &pilha3);
  printf("Imprime pilhas concatenadas\n");
  imprimePilha(pilha3);
  intercalaPilha(pilha, pilha2, &pilha4);
  printf("Imprime pilha1 intercalda com pilha2\n");
  imprimePilha(pilha4);
  printf("Interseção de pilha1 com pilha2\n");
  intersecaoDePilha(pilha, pilha2, &pilha5);
  imprimePilha(pilha5);
  printf("Pilha 1\n");
  imprimePilha(pilha);
  printf("Pilha 2\n");
  imprimePilha(pilha2);
  printf("Diferenca de pilhas\n");
  diferencaPilha(pilha2, pilha, &pilha6);
  imprimePilha(pilha6);
  printf("Ordenacao de pilhas\n");
  pilhaOrdenada(pilha);
  pilhaOrdenada(pilha5);
  pilhaOrdenada(pilha3);
  printf("FIM COM OS TESTES DE PILHAS\n\n\n\n\nINCIO COM OS TESTES DE FILA\n\n");
  tFila fila, fila2, fila3, fila4, fila5, fila6;
  fazFila(&fila);
  fazFila(&fila2);
  fazFila(&fila3);
  fazFila(&fila4);
  fazFila(&fila5);
  fazFila(&fila6);
  if(ehVaziaf(fila)){
    printf("Fila vazia\n");
  }
  enfilera(&fila, 1);
  enfilera(&fila, 2);
  enfilera(&fila, 3);
  enfilera(&fila, 4);
  enfilera(&fila, 5);
  printf("Imprime fila\n");
  imprimeFila(fila);
  desenfilera(&fila, &x);
  printf("x = %d\n\n", x);
  imprimeFila(fila);
  if(verificaNumeroFila(fila, 2))
    printf("O numero 2 existe dentro da fila\n");
  else
  printf("o numero 2 nao existe dentro da fila\n");
  if (verificaNumeroFila(fila, 10))
    printf("O numero 10 existe dentro da fila\n");
  else
  printf("O numero 10 nao existe na fila\n");
  printf("Fila copiada\n");
  cpyFila(fila, &fila2);
  imprimeFila(fila2);
  enfilera(&fila, 33);
  enfilera(&fila, 22);
  enfilera(&fila, 11);
  concatenaFila(&fila3, fila);
  printf("Imprime filas concatenadas\n");
  concatenaFila(&fila3, fila2);
  imprimeFila(fila3);
  printf("imprime fila 1 intercalada com fila 2\n");
  intercalaFila(fila, fila2, &fila4);
  imprimeFila(fila4);
  printf("Imprime a interseção de f1 com f2\n");
  intersecaoDeFila(fila, fila2, &fila5);
  imprimeFila(fila5);
  printf("Imprime a diferenca da fila 1 e fila 2\n");
  diferencaFila(fila, fila2, &fila6);
  imprimeFila(fila6);
  filaOrdenada(fila3);
  filaOrdenada(fila5);
  inverteFila(&fila5);
  imprimeFila(fila5);
  filaOrdenada(fila5);
  printf("FIM COM OS TESTES DE FILAS\n\n\n\n\nINCIO COM OS TESTES DE LISTA\n\n");
  tLista lista, lista2, lista3, lista4, lista5, lista6;
  fazLista(&lista);
  fazLista(&lista2);
  fazLista(&lista3);
  fazLista(&lista4);
  fazLista(&lista5);
  fazLista(&lista6);
  printf("Imprime se a lista é vazia\n");
  if(ehVaziaL(lista));
  printf("Lista vazia\n");
  add(&lista, 1);
  add(&lista, 2);
  add(&lista, 3);
  add(&lista, 4);
  printf("Imprime lista\n");
  imprimeLista(lista);
  removes(&lista, &z);
  printf("removeu %d\n", z);
  printf("Nova lista\n");
  imprimeLista(lista);
  if(verificaNumeroLista(lista, 2))
    printf("O numero 2 pertence a lista\n");
  else
    printf("O numero 2 não pertence a lista\n");
  if(verificaNumeroLista(lista, 12))
    printf("O numero 12 pertence a lista\n");
  else
    printf("O numero 12 não pertence a lista\n");
  cpyLista(lista, &lista2);
  imprimeLista(lista);
  printf("\n\n");
  printf("Imprime copia da lista 1\n");
  imprimeLista(lista2);
  add(&lista, 11);
  add(&lista, 33);
  printf("Concatena a lista 1 com a lista2\n");
  concatenaLista(lista, lista2, &lista3);
  printf("Concatenou\n");
  imprimeLista(lista3);
  printf("Imprime lista 1 intercalada com 2\n");
  intercalaLista(lista, lista2, &lista4);
  imprimeLista(lista4);
  fazLista(&lista4);
  printf("Imprime lista 2 intercalada com 1\n");
  intercalaLista(lista2, lista, &lista4);
  imprimeLista(lista4);
  printf("\n\n");
  imprimeLista(lista);
  printf("\n\n");
  imprimeLista(lista2);
  printf("Imprime a intersecao de lista 1 com lista 2\n");
  intersecaoDeLista(lista, lista2, &lista5);
  imprimeLista(lista5);
  printf("Imprime a diferenca de lista1 com a lista 2\n");
  diferencaLista(lista2, lista, &lista6);
  imprimeLista(lista6);
  printf("\n\nLista 1\n");
  imprimeLista(lista);
  listaOrdenada(lista);
  printf("\n\nLista 2\n");
  imprimeLista(lista2);
  listaOrdenada(lista2);
  printf("\n\nLista 3\n");
  imprimeLista(lista3);
  listaOrdenada(lista3);
  printf("\n\nLista 4\n");
  imprimeLista(lista4);
  listaOrdenada(lista4);
  printf("\n\nLista 5\n");
  imprimeLista(lista5);
  listaOrdenada(lista5);
  printf("\n\nLista 6\n");
  imprimeLista(lista6);
  listaOrdenada(lista6);
  printf("Ordena o 10 na lista 1\n");
  addOrdenado(&lista, 34);
  imprimeLista(lista);
  printf("Imprime lista 2\n");
  imprimeLista(lista2);
  mesclaElemento(&lista, lista2);
  printf("imprie listas mescaldas\n");
  imprimeLista(lista);
  return 0;
}
