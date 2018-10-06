typedef int tipoItem;

typedef struct celula *apontador;

typedef struct Conteudo{
  tipoItem item;
} Conteudo;

typedef struct celula{
  Conteudo c;
  apontador proximo;
} Celula;

typedef struct lista{
  apontador inicio, fim;
  int cont;
} tLista;

void fazLista(tLista *lista);

int ehVazia(tLista lista);

void add(tLista *lista, tipoItem x);

void removes(tLista *lista, tipoItem *x);

void imprime(tLista lista);

void listaA(tLista *a, tLista lista);

void listaB(tLista *a, tLista lista);

void listaC(tLista *a, tLista lista);
