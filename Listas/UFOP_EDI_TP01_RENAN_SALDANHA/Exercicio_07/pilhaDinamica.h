typedef int tipoItem;

typedef struct Conteudo{
  tipoItem item;
} Conteudo;

typedef struct Celula *apontador;

typedef struct Celula{
  Conteudo c;
  apontador proximo;
} Celula;

typedef struct tPilha{
  apontador fundo, topo;
  int cont;
} tPilha;

void fazPilha(tPilha *pilha);

int ehVazia(tPilha pilha);

void empilha(tPilha *pilha, tipoItem x);

void desempilha(tPilha *pilha, tipoItem *x);

void imprimePilha(tPilha pilha);

void verificaNumeroPilha(tPilha, tipoItem x);

void cpyPilha(tPilha pilha, tPilha *pilhac);

void concatenaPilha(tPilha pilha1, tPilha pilha2, tPilha *pilha);

void intercalaPilha(tPilha pilha1, tPilha pilha2, tPilha *pilha);
