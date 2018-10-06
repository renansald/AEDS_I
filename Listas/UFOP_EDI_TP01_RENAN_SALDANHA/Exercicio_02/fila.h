#define  max 7

typedef int tipoItem;
typedef int apontador;

typedef struct Conteudo{
  tipoItem item;
}Conteudo;

typedef struct tFila{
  Conteudo c[max];
  apontador frente, tras;
}tFila;

void fazFilaVazia(tFila *fila);

int filaVazia(tFila fila);

void enfilera(tFila *fila, tipoItem x);

void desenfilera(tFila *fila, tipoItem *x);

void imprimeFila(tFila fila);
