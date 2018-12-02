#include "listaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  tLista lista;
  fazLista(&lista);
  printf("Imprime se vazia\n");
  if(ehVazia(lista))
  printf("E vazia\n");
  char site[1000] = "Google fotos";
  char link[1000] = "www.goole.com.br";
  add(&lista, site, link);
  char site2[1000] = "my giterrr";
  char link2[1000] = "mygit.com";
  add(&lista, site2, link2);
  char site3[1000] = "my life";
  char link3[1000] = "mygit.com";
  add(&lista, site3, link3);
  printf("Imprime a Lista com um site\n");
  imprimeLista(lista);
  busca(&lista, site3);
  busca(&lista, site3);
  busca(&lista, site3);
  busca(&lista, site3);
  busca(&lista, site2);
  busca(&lista, site2);
  busca(&lista, site);
  busca(&lista, site);
  busca(&lista, site);
  printf("Imprime lista\n");
  imprimeLista(lista);
  return 0;
}
