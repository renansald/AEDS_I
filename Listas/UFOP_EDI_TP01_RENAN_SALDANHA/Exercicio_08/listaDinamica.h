
typedef struct celula *apontador;

typedef struct celula{
  char sites[1000];
  char link[1000];
  int nbusca;
  apontador proximo;
} celula;

typedef struct tLista{
  apontador inicio, fim;
  int count;
} tLista;

void fazLista(tLista *lista);

int ehVazia(tLista lista);

void add(tLista *lista, char s[1000], char link[1000]);

void removes(tLista *lista, char s[1000], char link[1000]);

void imprimeLista(tLista lista);

void busca(tLista *lista, char site[1000]);

void atualizaOrdem(tLista *lista);
