#include <stdlib.h>
#include<stdio.h>
#include <locale.h>
#include "cont.h"

//Estrutura para salvamento de dados do contato
/*struct contato1{
  int codigo;
  char nome[51], email[51], telefone[21];
};
/*
void encontraContatos(char nome[51], int *i, int *n, struct contato *contatos) {
  int tam = 0;
  while(nome[tam] != '\0'){
    tam++;
  }
  for(int a = 0; a < *n; a++){
    for(int b = 0; b <= tam; b++){
      if ((nome[b] == '\0') && (contatos[a].nome[b] == '\0')){
        *i = a;
        return;
      }
      else if ((nome[b] == '\0') && (contatos[a].nome[b] != '\0')){
        break;
      }
      else if (nome[b] != contatos[a].nome[b]){
        break;
      }
    }
  }
  *i = -1;
}

//Procedimento para inserir um novo contato
void insereContato(struct contato *contatos, int *n){
  int x = 0; //Variável para controle no casp do ID já estiver atribuido a outro contato
  printf("\n\n"); //Impressão de espaço na tela pra separar o menu da aplicação
  printf("Insira o nome: ");
  scanf(" %[^\n]s", contatos[*n].nome);
  printf("Insira um ID: ");
  scanf("%d", &contatos[*n].codigo);
  //Estrutura para testa se o ID atribuido ao contato já existe, caso exista ele exibe uma mensagem e pede ao usuário para inserir um novo ID
  do {
    x = 0;
    for(int i = 0; i < *n; i++){ //Pra acessar todos os contatos salvos
      if (contatos[*n].codigo == contatos[i].codigo){ //Para testar se o ID digitado é igual a um já existente
        printf("O ID %d já existe, por favor insira um novo ID: ", contatos[*n].codigo); //Caso exista ele pede para inserir um novo ID
        scanf("%d", &contatos[*n].codigo);
        x = 1; //Atribui o valor o 1, para que não sai do laço de interação, e retorne para testar o novo ID inserido
        break; //Para o teste com o for
      }
    }
  } while(x == 1);

  printf("Insira o número de telefone: ");
  scanf(" %[^\n]s", contatos[*n].telefone);
  printf("Insira o email: ");
  scanf(" %[^\n]s", contatos[*n].email);
  *n = *n + 1;
  printf("\n\n");
}

//Procedimento para listar todos os contatos, salvos, na tela
void listaContatos(struct contato *contatos, int *n) {
  printf("\n\n"); //Impressão de espaço na tela pra separar o menu da aplicação
  for (int i = 0; i < *n; i++) { //Estrutura para percorer todos os contetor e imprimi-los na tela
    printf("Nome: %s\nID = %d\nNúmero de Telefone: %s\nEmail: %s\n\n", contatos[i].nome, contatos[i].codigo, contatos[i].telefone, contatos[i].email);
  }
}

//Procedimento para pesquisar um contato via ID
void pesquisaContato(struct contato *contatos, int *n) {
  printf("\n\n"); //Impressão de espaço na tela pra separar o menu da aplicação
  char nome[51];
  int i;
  printf ("Informe o nome do contato: "); //Frase para indicar ao usuário que ele deve digitar o ID a ser pesquisado
  scanf(" %[^\n]s", nome);
  encontraContatos(nome, &i, n, contatos);
  if(i >= 0){
    printf("Nome: %s\nID = %d\nNúmero de Telefone: %s\nEmail: %s\n\n", contatos[i].nome, contatos[i].codigo, contatos[i].telefone, contatos[i].email); //Impre o contato quando encontrado
    return; //Para retornar para a função main
  }
  else{
    printf("O ID %s não exite\n\n", nome); //Mensagem de erro caso o contato não exista
  }
}

//Procedimento para alterar configurações de um contato
void alteraContato(struct contato *contatos, int *n) {
  printf("\n\n"); //Impressão de espaço na tela pra separar o menu da aplicação
  int i, x, y, aux; //Variável de posicionamento,  de coontrole caso o novo iD ja exista, variável de controle de laço e para escolhaer parametro a ser modificado, respectivamente
  char confirma, nome[51]; //Variável utilizada para confirmar se o contato a ser alterado é aquele mesmo
  y = 0;
  do { //Laço de interação para o caso do usuário digitar um id errado ou de um contato diferente do que ele relamente quer alterar, possibilitando que ele troque o contato a ser alterado
    printf ("Informe o nome do contato que deseja alterar: ");
    scanf(" %[^\n]s", nome);
    encontraContatos(nome, &i, n, contatos);
    if (i >= 0){ //Estrutura para identificar o contato a ser alterado e permitir a sua modificação
      //Estrutura para confirmar se o contato escolhido é o que realemnte deve ser alterado
      printf("Realmente deseja alterar o seguinte contato:\nNome: %s\nID = %d\nNúmero de Telefone: %s\nEmail: %s\nDigite \"S\" para sim e \"N\" para não: ", contatos[i].nome, contatos[i].codigo, contatos[i].telefone, contatos[i].email);
      scanf(" %c", &confirma);
      //Estrutura para o caso do contato for realmente o que deve ser alterado, pemitindo escolher o que vai ser alterado no contato
      if ((confirma == 's') || (confirma == 'S')) {
        printf("1: Nome\n2: ID\n3: Telefone\n4: email\n5: Todos os campos\nInforme o campo que deseja mudar: ");
        scanf("%d", &aux);
          //Estrutura para escolher a logica a ser feita de acordo com o que o usuário quer modificar no contato
        switch (aux) {
          case 1:
            printf("Insira o novo nome: ");
            scanf(" %[^\n]s", contatos[i].nome);
            printf("Nome alterado com sucesso!!\n\n");
            return;
          case 2:
            printf("Insira o novo ID: ");
            scanf("%d", &contatos[i].codigo);
            do {
              x = 0;
              for(int k = 0; k < *n; k++){
                if(k != i){
                  if (contatos[i].codigo == contatos[k].codigo){
                    printf("O ID %d já existe, por favor insira um novo ID: ", contatos[i].codigo);
                    scanf("%d", &contatos[i].codigo);
                    x =1;
                    break;
                  }
                }
              }
            } while(x == 1);
            printf("ID alterado com sucesso!!\n\n");
            return;
          case 3:
            printf("Insira o novo número de telefone: ");
            scanf(" %[^\n]s", contatos[i].telefone);
            printf("Telefone alterado com sucesso!!\n\n");
            return;
          case 4:
            printf("Insira o novo email: ");
            scanf(" %[^\n]s", contatos[i].email);
            printf("Email alterado com sucesso!!\n\n");
            return;
          case 5:
            printf("Insira o novo nome: ");
            scanf(" %[^\n]s", contatos[i].nome);
            printf("Insira o novo ID: ");
            scanf("%d", &contatos[i].codigo);
            do {
              x = 0;
              for(int k = 0; k < *n; k++){
              if(k != i){
                if (contatos[i].codigo == contatos[k].codigo){
                  printf("O ID %d já existe, por favor insira um novo ID: ", contatos[i].codigo);
                  scanf("%d", &contatos[i].codigo);
                  x =1;
                  break;
                }
              }
              }
            } while(x == 1);
            printf("Insira o novo número de telefone: ");
            scanf(" %[^\n]s", contatos[i].telefone);
            printf("Insira o novo email: ");
            scanf(" %[^\n]s", contatos[i].email);
            printf("Contato alterado com sucesso!!\n\n");
            return;
          default:
            printf("Comando não reconhecido, vocêe será redirecionado para o menu principal\n\n");
        }
      }
          //Estrutura para o caso do contato não ser o que o usuário quer modificar, permitindo a escolhar de outro contato ou o fim da desta aplicação do app
      else if ((confirma == 'n') || (confirma =='N')){
        printf("Deseja alterar outro contato, digite \"S\" para sim e \"N\" para não: ");
        scanf(" %c", &confirma);
        if ((confirma == 'n') || (confirma == 'N')){
          printf("Você será redirecionado ao menu principal\n\n");
          return;
        }
        else if ((confirma != 's') && (confirma != 'S')){
          printf("Erro comando não reconhecido, você será rediriecionado ao menu princiapl");
          return;
        }
        i = (*n-2);
        }
      //Estrutura para mostrar uma mensagem de erro caso o usuário digite um comando errado nesta aplicação
      else{
        printf("Erro Comando não reconhecido, você será redirecionado para o menu principal\n\n");
        return;
      }
    }
          //Estrutura para o caso do ID não existir na agenda, indicando que o contato não existe e permitindo que o usuário procure o outro contato ou saia da aplicação
    else {
      printf("Contato não encontrado. Deseja procurar outro ID? Digite \"S\" para sim e \"N\" para não: ");
      scanf(" %c", &confirma);
      if ((confirma == 'n') || (confirma == 'N')){
        printf("Você será redirecionado ao menu principal\n\n");
        return;
      }
      else if ((confirma != 's') && (confirma != 'S')){
        printf("Erro comando não reconhecido, você será rediriecionado ao menu princiapl\n\n");
        return;
      }
    }
  } while(y <= 0);
}

//Estrutura de realoção dos contatos na memória quando um contato é excluído
void realocaContatosMemoria(int i, struct contato *contatos, int *n) {
  int u, e, t; //Variáveis para medir o tamanho dos vetores de char da struct
  u = e = t = 0;
  for (i; i < (*n-1); i++) { //Laço para percorer todos os contatos e copiar o contato a da posição a frento do que foi excluído para a posição do que foi excluído
    contatos[i].codigo = contatos[(i+1)].codigo;
    while(contatos[(1+i)].nome[u] != '\0'){ //Estrutura para saber o tamanho do vetor de char de nome, da posiça de memoria a frente
      u++;
    }
    for (int r = 0; r <= u; r++) { //Estrutura para copiar caracter por caracter até o caracter \0 do nome do contato da próxima posição de memória
      contatos[i].nome[r] = contatos[(i+1)].nome[r];
    }

    while(contatos[(1+i)].email[e] != '\0'){ //Estrutura para saber o tamanho do vetor de char de email, da posiça de memoria a frente
      e++;
    }
    for (int r = 0; r <= e; r++) { //Estrutura para copiar caracter por caracter até o caracter \0 do email do contato da próxima posição de memória
      contatos[i].email[r] = contatos[(i+1)].email[r];
    }

    while(contatos[(1+i)].telefone[t] != '\0'){ //Estrutura para saber o tamanho do vetor de char de telefone, da posiça de memoria a frente
      t++;
    }
    for (int r = 0; r <= e; r++) { //Estrutura para copiar caracter por caracter até o caracter \0 do telefone do contato da próxima posição de memória
      contatos[i].telefone[r] = contatos[(i+1)].telefone[r];
    }
  }
}

//Estrutura para exclui um contato da agenda
void excluiContato(struct contato *contatos, int *n){
  int i, aux; //Variáveis para controle de endereco na memória auxiliar para estrutura do do while
  char confirma, nome[51]; //Variável para conforma se um contato deve realmente ser excluído
  aux = 0;
  printf("\n\n");
  do { //Estrutura de repetição para o caso do usuário digitar um contato que ele não queria excluir ou que não existe, possibilitado procura outro contato pra excluir
    printf("Informe o nome do contato a ser excluido: ");
    scanf(" %[^\n]s", &nome);
    encontraContatos(nome, &i, n, contatos);
      if(i >= 0){ //Estrutura para encontrar o contato na agenda
        //estrutura para confirma se é aquele contato que relamente deve ser excluido
        printf("Realmente deseja excluir o segunite contato:\nNome: %s\nID = %d\nNúmero de Telefone: %s\nEmail: %s\nDigite \"N\" para não e \"S\" para sim:", contatos[i].nome, contatos[i].codigo, contatos[i].telefone, contatos[i].email);
        scanf(" %c", &confirma);
        //Estrutura para o caso de o usuaria ter digitado um contato errado possibilitar ele trocar o contato ou sair da aplicação
        if((confirma == 'n') || (confirma == 'N')) {
            printf("Deseja procurar outro contato? Digite \"S\" pra sim ou \"N\" para não: ");
            scanf(" %c", &confirma);
            if ((confirma == 'n') ||(confirma == 'N')){
              printf("\n\n");
              return;
            }
            else if ((confirma != 's') ||(confirma == 'S')){
              printf("Comoda não reconhecido, você será enchaminhado para o menu principal\n\n");
              return;
            }
          }
        //Estrutura para o caso de o contato digitado ser realmente o que deve ser excluído, excluido e realocando os outros contatos na memoria, coocando os contatos que estão a frente do que foi excluído no lugar do que foi excluído
        else if ((confirma == 'S') || (confirma == 's')){
            realocaContatosMemoria(i, contatos, n);
            *n = *n -1; //Redução do número total de contatos da agenda
            printf("Contato excluido com sucesso!!\n\n");
            return;
        }
        else{
          printf("Comando não reconhecido, você será encaminhado para o menu principal\n\n");
          return;
        }
      }
      else{
        printf("Contato não encontrado, digite \"S\" para procurar outro contato ou \"N\" não: ");
        scanf(" %c", &confirma);
        if ((confirma == 'n') ||(confirma == 'N')){
          printf("\n\n");
          return;
        }
        else if ((confirma != 's') ||(confirma == 'S')){
          printf("Comoda não reconhecido, você será enchaminhado para o menu principal\n\n");
          return;
        }
      }
  } while(aux == 0);
}*/

int main(int argc, char const *argv[]) {
  setlocale(LC_ALL, "portuguese");
  int menu = 0; //Variável para escolher a função do menu
  int aux = 0; //Variável para conrole do laço do menu, para que sempre que uma sub rotina retornar o menu seja apresentado
  int a = 0; //Variável de controle da quantidade de contatos
  int v = 2; //variável para alocação dinâmica
  struct contato *contatos; //Ponteiro de struct para armazenar o dados do contato epoder ser alocada dinâmicamente a memória
  contatos = (struct contato*) malloc(v * sizeof(struct contato)); //alocação dinâmica da memómoria de acoro com a quantidade de contatos

  while (aux == 0) {
    if (a == v){ //Estrutura para quando a quantidade de contato atingir o maximo que foi alocado para eles
      v += 100;
      contatos = (struct contato*) realloc(contatos, v * sizeof(struct contato)); //Estrutura para realocação da memóra, aumentando a qauntidade de memória disponivel para salvar os contatos
    }
    printf("MENU\n1: Insira um novo contato\n2: Lista todos os contatos\n3: Pesquisa contato\n4: Altera um contato\n5: Excluir um contato\n6: Sair do APP\nInforme a opcao desejada: ");
    scanf("%d", &menu);
    //Estrutura para escolher a aplicação do menu e chamar a sua aplicação
    switch (menu) {
      case 1:
        insereContato(contatos, &a);
        break;
      case 2:
        listaContatos(contatos, &a);
        break;
      case 3:
        pesquisaContato(contatos, &a);
        break;
      case 4:
        alteraContato(contatos, &a);
        break;
      case 5:
        excluiContato(contatos, &a);
        break;
      case 6:
        free(contatos);
        return 0;
        break;
}
}
}
