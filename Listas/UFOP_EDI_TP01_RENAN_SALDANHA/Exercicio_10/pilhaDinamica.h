typedef struct tipoItem{
  char letra;
} tipoItem;

typedef struct celula* apontador;

typedef struct celula{
  tipoItem l;
  apontador proximo;
} celula;

typedef struct tPilha{
  apontador topo, fundo;
  int count;
} tPilha;

void fazPilha(tPilha *pilha);

int ehVazia(tPilha pilha);

void empilha(tPilha *pilha, char c[]);

void imprime(tPilha pilha);

void palindrome(tPilha pilha, char c[]);
