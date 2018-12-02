#include "AnaliseAlgoritmica.h"
#include <stdio.h>
#include <time.h>
#include "GerarArquivos.h"

void troca(int *vetor, int i, int j){
  int t = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = t;
}

int separa(int *v, int l, int r, int *z, int *x){
  int pivo = v[r];
  int i = l - 1;
  for(int j = l; j < r; ++j){
    ++*z;
    if(v[j] <= pivo){
      ++*x;
      ++i;
      troca(v, j, i);
    }
  }
  ++*x;
  troca(v, r, (i+1));
  return (i+1);
}

void insertionSort(int *v, int n, int *totalTroca, int *totalComparacoes, double *tempoTotal, clock_t *tTotal) {
  clock_t t = clock();
  int chave;
  int j;

  for (int i = 1; i < n; i++) {
    chave = v[i];
    j = i-1;
    ++*totalComparacoes;
    while ((j>=0) && (v[j] > chave)) {
      ++*totalComparacoes;
      ++*totalTroca;
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = chave;
  }
  t = clock() - t;
  *tTotal += t;
  double d = ((double)t)/CLOCKS_PER_SEC;
  *tempoTotal += d;
}

/*void bubbleSort(int v[], int n){
  int comparacoes = 0;
  int numeroTrocas = 0;
  clock_t t = clock();
  for (int i = 0; i < (n-1); i++) {
    for (int j = i+1; j < n; j++) {
      ++comparacoes;
      if(v[i]>v[j]){
        ++numeroTrocas;
        troca(v, i, j);
      }
    }
  }
  t = clock() - t;
  double d = ((double)t)/CLOCKS_PER_SEC;
  documentoAnalise(n, t, "BubbleSort.dat", comparacoes, numeroTrocas, d);
}*/

void selectionSort(int *v, int n, int *totalTroca, int *totalComparacoes, double *tempoTotal, clock_t *tTotal){
  clock_t t = clock();
  int min;
  for (int i = 0; i < (n-1); i++) {
    min = i;
    for (int j = i+1; j < n; j++) {
      ++*totalComparacoes;
      if(v[min]>v[j]){
        min = j;
      }
    }
    if(v[min] != v[i]){
    troca(v, min, i);
    ++*totalTroca;
  }
  }
  t = clock() - t;
  *tTotal += t;
  double d = ((double)t)/CLOCKS_PER_SEC;
  *tempoTotal += d;
}

void shellSort(int *v, int n, int *totalTroca, int *totalComparacoes, double *tempoTotal, clock_t *tTotal){
  clock_t t = clock();
  int h = 1;
  int j;
  int chave;
  while(h < n){
    h = 3*h+1;
  }
  while(h > 1){
    h /= 3;
    for(int i = h; i < n; i++){
      chave = v[i];
      j = i;
      ++*totalComparacoes;
      while ((j >= h) && (chave < v[j-h])){
        ++*totalComparacoes;
        ++*totalTroca;
        v[j] = v[j - h];
        j = j - h;
      }
      v[j] = chave;
    }
  }
  t = clock() - t;
  *tTotal += t;
  double d = ((double)t)/CLOCKS_PER_SEC;
  *tempoTotal += d;
}

void quickSort(int *v, int l, int r, int *comparacoes, int *trocas){
  if(l >= r){
  return;
  }
  int h = separa(v, l, r, comparacoes, trocas);
  quickSort(v, h+1, r, comparacoes, trocas);
  quickSort(v, l, h-1, comparacoes, trocas);
}
