typedef char tipoChave;

typedef struct tipoItem{
  tipoChave chave;
} tipoItem;

typedef struct celulaP *apontador;

typedef struct celulaP{
  tipoItem item;
  apontador proximo;
} celulaP;

typedef struct tPilha{
  apontador fundo, topo;
  int count;
} tPilha;

typedef struct tFila{
  apontador frente, tras;
  int count;
} tFila;

typedef struct tLista{
  apontador inicio, fim;
  int count;
} tLista;

void fazPilha(tPilha *pilha);

void fazFila(tFila *fila);

void fazLista(tLista *lista);

int ehVaziaP(tPilha pilha);

int ehVaziaF(tFila fila);

int ehVaziaL(tLista lista);

void empilha(tPilha *pilha, tipoChave x);

void enfilera(tFila *fila, tipoChave x);

void add(tLista *lista, tipoChave x);

void desempilha(tPilha *pilha, tipoChave *x);

void desenfilera(tFila *fila, tipoChave *chave);

void removes(tLista *lista, tipoChave *x);

void imprime(tLista lista);

int ehDigito(tipoChave x);

void reorganiza(tLista *lista, tLista lista2);
