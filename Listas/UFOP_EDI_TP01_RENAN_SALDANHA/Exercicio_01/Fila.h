
#define max 7


typedef int tipoItem;

typedef struct Conjunto{
  tipoItem item;
}Conjunto;

typedef int apontador;

typedef struct tFila{
  Conjunto c[max];
  apontador frente;
  apontador tras;
}tFila;

void fazFilaVazia(tFila *fila);

int filaVazia(tFila fila);

void enfilera(tFila *fila, tipoItem y);

void desenfilera(tFila *fila, tipoItem *y);

void imprimeFila(tFila fila);

void furaFila(tFila *fila, tipoItem x);
