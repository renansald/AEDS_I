#include "cont.h"
#include <stdio.h>
#include <stdlib.h>

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
  int x = 0; //Vari�vel para controle no casp do ID j� estiver atribuido a outro contato
  printf("\n\n"); //Impress�o de espa�o na tela pra separar o menu da aplica��o
  printf("Insira o nome: ");
  scanf(" %[^\n]s", contatos[*n].nome);
  printf("Insira um ID: ");
  scanf("%d", &contatos[*n].codigo);
  /*Estrutura para testa se o ID atribuido ao contato j� existe, caso exista ele exibe uma mensagem e pede ao usu�rio para inserir um novo ID*/
  do {
    x = 0;
    for(int i = 0; i < *n; i++){ //Pra acessar todos os contatos salvos
      if (contatos[*n].codigo == contatos[i].codigo){ //Para testar se o ID digitado � igual a um j� existente
        printf("O ID %d já existe, por favor insira um novo ID: ", contatos[*n].codigo); //Caso exista ele pede para inserir um novo ID
        scanf("%d", &contatos[*n].codigo);
        x = 1; //Atribui o valor o 1, para que n�o sai do la�o de intera��o, e retorne para testar o novo ID inserido
        break; //Para o teste com o for
      }
    }
  } while(x == 1);

  printf("Insira o numero de telefone: ");
  scanf(" %[^\n]s", contatos[*n].telefone);
  printf("Insira o email: ");
  scanf(" %[^\n]s", contatos[*n].email);
  *n = *n + 1;
  printf("\n\n");
}

//Procedimento para listar todos os contatos, salvos, na tela
void listaContatos(struct contato *contatos, int *n) {
  printf("\n\n"); //Impress�o de espa�o na tela pra separar o menu da aplica��o
  for (int i = 0; i < *n; i++) { //Estrutura para percorer todos os contetor e imprimi-los na tela
    printf("Nome: %s\nID = %d\nNumero de Telefone: %s\nEmail: %s\n\n", contatos[i].nome, contatos[i].codigo, contatos[i].telefone, contatos[i].email);
  }
}

//Procedimento para pesquisar um contato via ID
void pesquisaContato(struct contato *contatos, int *n) {
  printf("\n\n"); //Impress�o de espa�o na tela pra separar o menu da aplica��o
  char nome[51];
  int i;
  printf ("Informe o nome do contato: "); //Frase para indicar ao usu�rio que ele deve digitar o ID a ser pesquisado
  scanf(" %[^\n]s", nome);
  encontraContatos(nome, &i, n, contatos);
  if(i >= 0){
    printf("Nome: %s\nID = %d\nNumero de Telefone: %s\nEmail: %s\n\n", contatos[i].nome, contatos[i].codigo, contatos[i].telefone, contatos[i].email); //Impre o contato quando encontrado
    return; //Para retornar para a fun��o main
  }
  else{
    printf("O ID %s nao exite\n\n", nome); //Mensagem de erro caso o contato n�o exista
  }
}

//Procedimento para alterar configura��es de um contato
void alteraContato(struct contato *contatos, int *n) {
  printf("\n\n"); //Impress�o de espa�o na tela pra separar o menu da aplica��o
  int i, x, y, aux; //Vari�vel de posicionamento,  de coontrole caso o novo iD ja exista, vari�vel de controle de la�o e para escolhaer parametro a ser modificado, respectivamente
  char confirma, nome[51]; //Vari�vel utilizada para confirmar se o contato a ser alterado � aquele mesmo
  y = 0;
  do { //La�o de intera��o para o caso do usu�rio digitar um id errado ou de um contato diferente do que ele relamente quer alterar, possibilitando que ele troque o contato a ser alterado
    printf ("Informe o nome do contato que deseja alterar: ");
    scanf(" %[^\n]s", nome);
    encontraContatos(nome, &i, n, contatos);
    if (i >= 0){ //Estrutura para identificar o contato a ser alterado e permitir a sua modifica��o
      //Estrutura para confirmar se o contato escolhido � o que realemnte deve ser alterado
      printf("Realmente deseja alterar o seguinte contato:\nNome: %s\nID = %d\nNumero de Telefone: %s\nEmail: %s\nDigite \"S\" para sim e \"N\" para nao: ", contatos[i].nome, contatos[i].codigo, contatos[i].telefone, contatos[i].email);
      scanf(" %c", &confirma);
      //Estrutura para o caso do contato for realmente o que deve ser alterado, pemitindo escolher o que vai ser alterado no contato
      if ((confirma == 's') || (confirma == 'S')) {
        printf("1: Nome\n2: ID\n3: Telefone\n4: email\n5: Todos os campos\nInforme o campo que deseja mudar: ");
        scanf("%d", &aux);
          //Estrutura para escolher a logica a ser feita de acordo com o que o usu�rio quer modificar no contato
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
                    printf("O ID %d ja existe, por favor insira um novo ID: ", contatos[i].codigo);
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
            printf("Insira o novo numero de telefone: ");
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
                  printf("O ID %d ja existe, por favor insira um novo ID: ", contatos[i].codigo);
                  scanf("%d", &contatos[i].codigo);
                  x =1;
                  break;
                }
              }
              }
            } while(x == 1);
            printf("Insira o novo numero de telefone: ");
            scanf(" %[^\n]s", contatos[i].telefone);
            printf("Insira o novo email: ");
            scanf(" %[^\n]s", contatos[i].email);
            printf("Contato alterado com sucesso!!\n\n");
            return;
          default:
            printf("Comando nao reconhecido, voce sera redirecionado para o menu principal\n\n");
        }
      }
          //Estrutura para o caso do contato n�o ser o que o usu�rio quer modificar, permitindo a escolhar de outro contato ou o fim da desta aplica��o do app
      else if ((confirma == 'n') || (confirma =='N')){
        printf("Deseja alterar outro contato, digite \"S\" para sim e \"N\" para nao: ");
        scanf(" %c", &confirma);
        if ((confirma == 'n') || (confirma == 'N')){
          printf("Voce sera redirecionado ao menu principal\n\n");
          return;
        }
        else if ((confirma != 's') && (confirma != 'S')){
          printf("Erro comando nao reconhecido, voce sera rediriecionado ao menu princiapl");
          return;
        }
        i = (*n-2);
        }
      //Estrutura para mostrar uma mensagem de erro caso o usu�rio digite um comando errado nesta aplica��o
      else{
        printf("Erro Comando nao reconhecido, voce sera redirecionado para o menu principal\n\n");
        return;
      }
    }
          //Estrutura para o caso do ID n�o existir na agenda, indicando que o contato n�o existe e permitindo que o usu�rio procure o outro contato ou saia da aplica��o
    else {
      printf("Contato nao encontrado. Deseja procurar outro ID? Digite \"S\" para sim e \"N\" para n�o: ");
      scanf(" %c", &confirma);
      if ((confirma == 'n') || (confirma == 'N')){
        printf("Voce sera redirecionado ao menu principal\n\n");
        return;
      }
      else if ((confirma != 's') && (confirma != 'S')){
        printf("Erro comando nao reconhecido, voce sera rediriecionado ao menu princiapl\n\n");
        return;
      }
    }
  } while(y <= 0);
}

//Estrutura de realo��o dos contatos na mem�ria quando um contato � exclu�do
void realocaContatosMemoria(int i, struct contato *contatos, int *n) {
  int u, e, t; //Vari�veis para medir o tamanho dos vetores de char da struct
  u = e = t = 0;
  for (i; i < (*n-1); i++) { //La�o para percorer todos os contatos e copiar o contato a da posi��o a frento do que foi exclu�do para a posi��o do que foi exclu�do
    contatos[i].codigo = contatos[(i+1)].codigo;
    while(contatos[(1+i)].nome[u] != '\0'){ //Estrutura para saber o tamanho do vetor de char de nome, da posi�a de memoria a frente
      u++;
    }
    for (int r = 0; r <= u; r++) { //Estrutura para copiar caracter por caracter at� o caracter \0 do nome do contato da pr�xima posi��o de mem�ria
      contatos[i].nome[r] = contatos[(i+1)].nome[r];
    }

    while(contatos[(1+i)].email[e] != '\0'){ //Estrutura para saber o tamanho do vetor de char de email, da posi�a de memoria a frente
      e++;
    }
    for (int r = 0; r <= e; r++) { //Estrutura para copiar caracter por caracter at� o caracter \0 do email do contato da pr�xima posi��o de mem�ria
      contatos[i].email[r] = contatos[(i+1)].email[r];
    }

    while(contatos[(1+i)].telefone[t] != '\0'){ //Estrutura para saber o tamanho do vetor de char de telefone, da posi�a de memoria a frente
      t++;
    }
    for (int r = 0; r <= e; r++) { //Estrutura para copiar caracter por caracter at� o caracter \0 do telefone do contato da pr�xima posi��o de mem�ria
      contatos[i].telefone[r] = contatos[(i+1)].telefone[r];
    }
  }
}

//Estrutura para exclui um contato da agenda
void excluiContato(struct contato *contatos, int *n){
  int i, aux; //Vari�veis para controle de endereco na mem�ria auxiliar para estrutura do do while
  char confirma, nome[51]; //Vari�vel para conforma se um contato deve realmente ser exclu�do
  aux = 0;
  printf("\n\n");
  do { //Estrutura de repeti��o para o caso do usu�rio digitar um contato que ele n�o queria excluir ou que n�o existe, possibilitado procura outro contato pra excluir
    printf("Informe o nome do contato a ser excluido: ");
    scanf(" %[^\n]s", &nome);
    encontraContatos(nome, &i, n, contatos);
      if(i >= 0){ //Estrutura para encontrar o contato na agenda
        //estrutura para confirma se � aquele contato que relamente deve ser excluido
        printf("Realmente deseja excluir o segunite contato:\nNome: %s\nID = %d\nNumero de Telefone: %s\nEmail: %s\nDigite \"N\" para nao e \"S\" para sim:", contatos[i].nome, contatos[i].codigo, contatos[i].telefone, contatos[i].email);
        scanf(" %c", &confirma);
        //Estrutura para o caso de o usuaria ter digitado um contato errado possibilitar ele trocar o contato ou sair da aplica��o
        if((confirma == 'n') || (confirma == 'N')) {
            printf("Deseja procurar outro contato? Digite \"S\" pra sim ou \"N\" para nao: ");
            scanf(" %c", &confirma);
            if ((confirma == 'n') ||(confirma == 'N')){
              printf("\n\n");
              return;
            }
            else if ((confirma != 's') ||(confirma == 'S')){
              printf("Comoda nao reconhecido, voce sera enchaminhado para o menu principal\n\n");
              return;
            }
          }
        //Estrutura para o caso de o contato digitado ser realmente o que deve ser exclu�do, excluido e realocando os outros contatos na memoria, coocando os contatos que est�o a frente do que foi exclu�do no lugar do que foi exclu�do
        else if ((confirma == 'S') || (confirma == 's')){
            realocaContatosMemoria(i, contatos, n);
            *n = *n -1; //Redu��o do n�mero total de contatos da agenda
            printf("Contato excluido com sucesso!!\n\n");
            return;
        }
        else{
          printf("Comando nao reconhecido, voce sera encaminhado para o menu principal\n\n");
          return;
        }
      }
      else{
        printf("Contato nao encontrado, digite \"S\" para procurar outro contato ou \"N\" nao: ");
        scanf(" %c", &confirma);
        if ((confirma == 'n') ||(confirma == 'N')){
          printf("\n\n");
          return;
        }
        else if ((confirma != 's') ||(confirma == 'S')){
          printf("Comoda nao reconhecido, voce sera enchaminhado para o menu principal\n\n");
          return;
        }
      }
  } while(aux == 0);
}
