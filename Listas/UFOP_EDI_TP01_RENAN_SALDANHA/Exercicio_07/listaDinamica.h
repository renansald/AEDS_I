typedef int tipoItem;

typedef struct Celulal *apontadorL;

typedef struct Celulal{
  tipoItem item;
  apontadorL proximo;
} celulaL;

typedef struct tLista{
  apontadorL primeiro, ultimo;
  int count;
} tLista;

void fazLista(tLista *lista);

int ehVaziaL(tLista lista);

void add(tLista *lista, tipoItem x);

void removes(tLista *lista, tipoItem *x);

void imprimeLista(tLista lista);

int verificaNumeroLista(tLista lista, tipoItem x);

void cpyLista(tLista lista1, tLista *lista);

void concatenaLista(tLista lista1, tLista lista2, tLista *lista);

void intercalaLista(tLista lista1, tLista lista2, tLista *lista);

void intersecaoDeLista(tLista lista1, tLista lista2, tLista *lista);

void diferencaLista(tLista lista1, tLista lista2, tLista *lista);

void listaOrdenada(tLista lista);

void addOrdenado(tLista *lista, tipoItem x);

void mesclaElemento(tLista *lista, tLista lista1);
