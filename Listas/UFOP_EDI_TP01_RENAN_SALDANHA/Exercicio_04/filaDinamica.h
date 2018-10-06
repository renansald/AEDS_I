#define maxI 5

typedef int tipoItem;

typedef struct Conteudo{
  tipoItem *item;
  int cont;
} conteudo;

typedef struct celula *apontador;

typedef struct celula{
  conteudo c;
  apontador proximo;
} celula;

typedef struct fila{
  apontador frente, tras;
}tFila;

void fazFila(tFila *fila);

int ehVazia(tFila fila);

void enfilera(tFila *fila, tipoItem *y, int n);

//void desenfileira(tFila *fila, tipoItem y[], int n);
tipoItem *desenfileira(tFila *fila, int *n);

void imprime(tFila fila);
