typedef int Item;

typedef struct tipoItem{
  Item chave;
} tipoItem;

typedef struct celula *apontador;

typedef struct celula{
  tipoItem item;
  apontador proximo;
} celula;

typedef struct tLista{
  apontador inicio, fim;
  int count;
} tLista;

void fazLista(tLista *lista);

int ehVazia(tLista lista);

void add(tLista *lista, Item x);

void removes(tLista *lista, Item *x);

void imprime(tLista lista);

void removePar(tLista *lista);
