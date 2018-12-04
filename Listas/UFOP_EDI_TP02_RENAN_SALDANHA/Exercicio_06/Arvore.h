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

int nNos(No *pRaiz, int n);

int similaridade(apontador a, apontador a1);

void verificaSimilaridade(apontador a, apontador a1);

void verificarEspelho(apontador a, apontador a1);

void espelho(apontador a, int *v, int *x);
