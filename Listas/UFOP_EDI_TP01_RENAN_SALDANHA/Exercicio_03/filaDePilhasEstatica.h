#define maxF 7
#define maxP 3

typedef int apontador;
typedef int tipoItem;

typedef struct Conteudo{
  tipoItem item;
} Conteudo;

typedef struct tPilha{
  Conteudo c[maxP];
  apontador topo;
} tPilha;

typedef struct tFila{
  tPilha pilha[maxF];
  apontador frente, tras;
}tFila;

void fazFilaDePilhas(tFila *fila);

void fazPilha(tPilha *pilha);

int verificaFilaVazia(tFila fila);

int verificaPilhavazia(tPilha pilha);

void empilha(tPilha *pilha, tipoItem x);

void enfileraPilha(tFila *fila, tPilha pilha);

void desempilha(tPilha *pilha, tipoItem *x);

void desenfileraPilha(tFila *fila, tPilha *pilha);

void imprimePilha(tPilha pilha);

void imprimeFiladePilha(tFila fila);
