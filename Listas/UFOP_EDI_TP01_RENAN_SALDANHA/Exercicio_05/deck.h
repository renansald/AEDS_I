#define Max 7

typedef int tipoItem;

typedef struct Deque {
  tipoItem dek[Max];
  int primeiroEsq, finalEsq, primeiroDir, finalDir;
} Deque;

void fazDeque(Deque *d);

int ehVazio(Deque d);

void InsDir(Deque *d, tipoItem x);

void InsEsq(Deque *d, tipoItem x);

void RemDir(Deque *d, tipoItem *x);

void RemEsq(Deque *d, tipoItem *x);

void imprimeDeque(Deque d);
