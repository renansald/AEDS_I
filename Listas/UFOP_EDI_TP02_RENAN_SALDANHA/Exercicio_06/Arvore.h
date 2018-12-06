typedef struct No *apontador;

struct No{
    int numero;
    struct No *esquerda;
    struct No *direita;
};
typedef struct No No;

void criarArvore(No **pRaiz);

void insercao(No **pRaiz, int numero2);

void insercaoEspelho(No **pRaiz, int numero2);

void exibirEmOrdem(No *pRaiz);

int espelho(apontador a, apontador a1);
