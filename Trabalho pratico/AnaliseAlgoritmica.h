#include <time.h>
void insertionSort(int v[], int n, int *totalTroca, int *totalComparacoes, double *tempoTotal, clock_t *tTotal);

//void bubbleSort(int v[], int n);

void shellSort(int v[], int n, int *totalTroca, int *totalComparacoes, double *tempoTotal, clock_t *tTotal);

void selectionSort(int v[], int n, int *totalTroca, int *totalComparacoes, double *tempoTotal, clock_t *tTotal);

void quickSort(int v[], int l, int r, int *comparacoes, int *trocas);

int separa(int v[], int l, int r, int *z, int *x);
