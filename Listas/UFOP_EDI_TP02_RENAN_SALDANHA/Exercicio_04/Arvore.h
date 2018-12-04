typedef struct No *apontador;

struct No{
    int numero;
    struct No *esquerda;
    struct No *direita;
};
typedef struct No No;

void criarArvore(No **pRaiz);

void insercao(No **pRaiz, int numero2);

void exibirEmOrdem(No *pRaiz);

int Profundidade(No *pRaiz, int n);

int verificaEstritamenteBinaria(apontador a, int n, int v);

int nNos(No *pRaiz, int n);

int verificaCompleta(apontador a, int n, int v);

int verificarCheia(apontador a, int n, int v);
