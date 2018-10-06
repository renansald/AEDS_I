#define  maxF 10
#define  maxP 7

typedef int apontador;
typedef int tipoItem;

typedef struct Conteudo{
  tipoItem item;
} Conteudo;

typedef struct tFila{
  Conteudo c[maxF];
  apontador frente, tras;
} tFila;

typedef struct tPilha{
  tFila fila[maxP];
  apontador topo;
} tPilha;

void fazPilhadeListas(tPilha *pilha);

void fazFila(tFila *fila);

int pilhaVazia(tPilha pilha);

int filaVazia(tFila fila);

void enfilera(tFila *fila, tipoItem x);

void desenfilera(tFila *fila, tipoItem *y);

void empilhaFila(tPilha *pilha, tFila fila);

void desempilhaFila(tPilha *pilha, tFila *fila);

void imprimeFila(tFila fila);

void imprimePilhadeFilas(tPilha pilha);
