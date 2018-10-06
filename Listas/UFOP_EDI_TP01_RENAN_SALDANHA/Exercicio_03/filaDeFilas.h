#define  maxF 7

typedef int tipoItem;
typedef int apontador;

typedef struct Conteudo{
  tipoItem item;
} Conteudo;

typedef struct tFila{
  Conteudo c[maxF];
  apontador frente, tras;
} tFila;

typedef struct tFilas{
  tFila fila[maxF];
  apontador frente, tras;
} tFilas;

int ehVazia(tFila fila);

int ehVaziaFF(tFilas ffila);

void fazFila2(tFila *fila);

void fazFilaF(tFilas *ffila);

void enfilera2(tFila *fila, tipoItem x);

void desenfilera2(tFila *fila, tipoItem *x);

void enfileraF(tFilas *ffila, tFila fila);

void desenfileraf(tFilas *ffila, tFila *fila);

void imprime(tFila fila);

void imprimef(tFilas ffila);
