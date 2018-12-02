#include "GerarArquivos.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "AnaliseAlgoritmica.h"

void criaArquivo(int n, int v[], int id){
  FILE *arquivo;
  char nomeArquivo[50];
  char numero[100];
  if(id == 1){
    nomeArquivo[0] = '0';
    nomeArquivo[1] = '1';
    nomeArquivo[2] = '_';
    nomeArquivo[3] = '\0';
  }
  else if(id == 2){
    nomeArquivo[0] = '0';
    nomeArquivo[1] = '2';
    nomeArquivo[2] = '_';
    nomeArquivo[3] = '\0';
  }
  else{
    nomeArquivo[0] = '0';
    nomeArquivo[1] = '3';
    nomeArquivo[2] = '_';
    nomeArquivo[3] = '\0';
  }
  sprintf(numero, "%d", n);
  strcat(nomeArquivo, numero);
  strcat(nomeArquivo, ".dat");

  arquivo = fopen(nomeArquivo, "a");
  for (int i = 0; i < n; i++) {
    fprintf(arquivo, "%d,", v[i]);
  }
  fclose(arquivo);
  printf("\nDados gravados com sucesso\n");
}

void fazLeitura(){
  int n, trocasQuick, trocasSeletion, trocasInsertion, trocasShell, cQuick, cSeletion, cInsertion, cShell, *vetor1, *vetor2, *vetor3, *vetor4;
  clock_t tQuick, tSelection, tInsertion, tShell;
  tQuick = tSelection = tInsertion = tShell = 0;
  double dQuick, dSeletion, dInsertion, dShell;
  dQuick = dSeletion = dInsertion = dShell = trocasQuick = trocasSeletion = trocasInsertion = trocasShell = cQuick = cSeletion = cInsertion = cShell = 0;
  FILE *arquivo;
  printf("Informe a quantidade de dados: ");
  scanf("%d", &n);
  vetor1 = (int*)malloc(n*sizeof(int));
  vetor2 = (int*)malloc(n*sizeof(int));
  vetor3 = (int*)malloc(n*sizeof(int));
  vetor4 = (int*)malloc(n*sizeof(int));
  char nomeArq[50];
  while(1){
    printf("Informe o nome do arquivo:");
    scanf(" %[^\n]s", &nomeArq);
    strcat(nomeArq, ".dat");
    arquivo = fopen(("%s",nomeArq), "r");
    if(arquivo == NULL){
      printf("Não existe\nDeseja informar outro arquivo?\nDigite 's' para sim e 'n' para nao: ");
      char questao;
      scanf(" %c", &questao);
      if((questao == 'n') || (questao == 'N')){
        return;
      }
    }
    else
    break;
  }
  int i = 0;
  for (int aux1 = 0; aux1 < 30; aux1++) {
    while (fscanf(arquivo, "%d, ", &vetor1[i]) != EOF){
      vetor2[i] = vetor1[i];
      vetor3[i] = vetor1[i];
      vetor4[i] = vetor1[i];
      i++;
    }
    /*for (int aux = 0; aux < n; aux++) {
      vetor2[aux] = vetor3[aux] = vetor4[aux] = vetor1[aux];
    }*/
    insertionSort(vetor1, n, &trocasInsertion, &cInsertion, &dInsertion, &tInsertion);
    printf("passei do insertion\n");
    clock_t t = clock();
    quickSort(vetor2, 0, (n-1), &cQuick, &trocasQuick);
    t = clock() - t;
    printf("passei do quick\n");
    double d = (((double)t)/CLOCKS_PER_SEC);
    tQuick += t;
    dQuick += d;
    shellSort(vetor3, n, &trocasShell, &cShell, &dShell, &tShell);
    printf("passei do shell\n");
    selectionSort(vetor4, n, &trocasSeletion, &cSeletion, &dSeletion, &tSelection);
    printf("passei do selection\n");
  }
  documentoAnalise(n, (tInsertion/30), "InsertionSort.dat", (cInsertion/30), (trocasInsertion/30), (dInsertion/30));
  documentoAnalise(n, (tSelection/30), "SeletionSort.dat", (cSeletion/30), (trocasSeletion/30), (dSeletion/30));
  documentoAnalise(n, (tShell/30), "ShellSort.dat", (cShell/30), (trocasShell/30), (dShell/30));
  documentoAnalise(n, (tQuick/30), "QuickSort.dat", (cQuick/30), (trocasQuick/30), (dQuick/30));

  printf("Documento de Analise do Insertion sort gerado/atualizado com sucesso\n");
  printf("Documento de Analise do Quick sort gerado/atualizado com sucesso\n");
  printf("Documento de Analise do Shell sort gerado/atualizado com sucesso\n");
  printf("Documento de Analise do Seletion sort gerado/atualizado com sucesso\n");
  fclose(arquivo);
}

void tipoArquivo(){
  srand (time(NULL));
  char tArquivo;
  int qntNumeros;
  int *vetor;
  while (1) {
    printf("Tipos de ordenaçao:\n\tA - Ordenado crescente;\n\tB - Ordenado decrescente;\n\tC - Random\nInforme a opcao desejada: ");
    scanf(" %c", &tArquivo);;
    if ((tArquivo == 'a') || (tArquivo == 'A') || (tArquivo == 'b') || (tArquivo == 'B') || (tArquivo == 'c') || (tArquivo == 'C')) {
      break;
    }
    printf("As opcoes do menu vao de 'A' a 'C', por favor escolha uma das alternativas abaixo\n");
  }
  printf("Informe o tamanho do seu array: ");
  scanf("%d", &qntNumeros);
  vetor = (int*)malloc(qntNumeros*sizeof(int));
  if((tArquivo == 'a') || (tArquivo == 'A')){
    for (int i = 0; i < qntNumeros; i++) {
      vetor[i] = i;
    }
    criaArquivo(qntNumeros, vetor, 1);
  } else if ((tArquivo == 'b') || (tArquivo == 'B')){
    for (int i =0; i < qntNumeros; i++) {
      vetor[i] = (qntNumeros - (i+1));
    }
    criaArquivo(qntNumeros, vetor, 2);
  } else if ((tArquivo == 'c') || (tArquivo == 'C')) {
    for (int i = 0; i < qntNumeros; i++) {
      vetor[i] = rand() % 50000;
    }
    criaArquivo(qntNumeros, vetor, 3);
  }
}

void documentoAnalise(int n, int t, char metodo[], int comparacoes, int numeroTrocas, double time){
  FILE *arquivo;
  arquivo = fopen(("%s", metodo), "a");
  fprintf(arquivo, "Numero de elementos do array: %d\nNumero de comparacoes: %d\nNumero de trocas: %d\nNumero de clicks: %d\nTempo em segundos: %lf\n\n", n, comparacoes, numeroTrocas, t, time);
  fclose(arquivo);
}
