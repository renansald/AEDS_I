#ifndef CONT_H_INCLUDED
#define CONT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

struct contato{
  int codigo;
  char nome[51], email[51], telefone[21];
};

void encontraContatos(char nome[51], int *i, int *n, struct contato *contatos);
void insereContato(struct contato *contatos, int *n);
void listaContatos(struct contato *contatos, int *n);
void pesquisaContato(struct contato *contatos, int *n);
void alteraContato(struct contato *contatos, int *n);
void realocaContatosMemoria(int i, struct contato *contatos, int *n);
void excluiContato(struct contato *contatos, int *n);



#endif // CONT_H_INCLUDED
