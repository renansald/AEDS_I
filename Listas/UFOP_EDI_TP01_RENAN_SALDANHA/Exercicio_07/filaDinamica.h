typedef int tipoItem;

typedef struct Celulaf *apontadorF;

typedef struct Celulaf{
  tipoItem item;
  apontadorF proximo;
} celulaf;

typedef struct fila{
  apontadorF frente, tras;
  int count;
} tFila;

void fazFila(tFila *fila);

int ehVaziaf(tFila fila);

void enfilera(tFila *fila, tipoItem x);

void desenfilera(tFila *fila, tipoItem *x);

void imprimeFila(tFila fila);

int verificaNumeroFila(tFila fila, tipoItem x);

void cpyFila(tFila fila, tFila *fila1);

//void concatenaFila(tFila, tFila, tFila*);

void concatenaFila(tFila *fila, tFila fila2);

void intercalaFila(tFila fila1, tFila fila2, tFila *fila);

void intersecaoDeFila(tFila fila1, tFila fila2, tFila *fila);

void diferencaFila(tFila fila1, tFila fila2, tFila *fila);

void filaOrdenada(tFila fila);

void inverteFila(tFila *fila);
