#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

void printvet( int v[], int n){
	int i;
	for(i=0;i<n;i++){
	printf("%d ,",v[i]);
}
}

void menu (){
	int opcao;
	printf("\nEscolha uma opcao para continuar\n\n -1) Construcao de Arquivos\n\n -2) Analise Comparativa\n\n -3) Sair\n");
	scanf("%d",&opcao);
	
	switch(opcao){
		
		case 1:
		
		 organiza();
		break;
		
		case 2:
			
			break;
			
			case 3:
				
				break;
				
				default:
					
					printf("Opcao invalida\n");
					return menu();
					break;
	}
}

int organiza(){
	int opcao,n,l,memoo;
	int v,aux;
	
	v = (int *) malloc(n*sizeof(int));
  	
	
	printf("Selecione o Numero de Chaves desejadas\n\n");
	scanf("%d",&n);

	printf("Por favor, selecione o modo de organição desejado\n\n -1) Ordenado Crescente\n\n -2)Ordenado Decrescente\n\n -3) Randomico\n ");
	scanf("%d",&opcao);
	
	
	switch (opcao){
		
		case 1:
		
		preenchevetorcrescente(n,v);
		printvet(v,n);
			printf("\n\n\nInforme o metodo de ordenacao desejado\n\n\n");
			printf("1-Insertion\n2-Selection\3-SHELL\n4-Quick\n5-sair\n");
			scanf("%d",&memoo);
			
			if(memoo==1){
				aux=copia(n,v);
			insertionsort (aux, l, n);
			//****
			}
			else if (memoo==2){
				aux=copia(n,v);
			selectionsort (aux, l, n);
			//*****
			}
			else if (memoo==3){
			
			}
			else if (memoo==4){
		
			}
			else if (memoo==5){
			
			}
			else{
				menu();
			}

			break;
			
			case 2:
			
		preenchevetordecrescente(n,v);
		printvet(v,n);
		
			printf("\n\n\nInforme o metodo de ordenacao desejado\n\n\n");
			printf("1-Insertion\n2-Selection\3-SHELL\n4-Quick\n5-sair\n");
			scanf("%d",&memoo);
			
			if(memoo==1){
				aux=copia(n,v);
			insertionsort (aux, l, n);
			//****
			}
			else if (memoo==2){
				aux=copia(n,v);
			selectionsort (aux, l, n);
			//*****
			}
			else if (memoo==3){
			
			}
			else if (memoo==4){
		
			}
			else if (memoo==5){
			
			}
			else{
				menu();
			}
		
			break;
				
			case 3:
			
		preencherandom(n,v);
		printvet(v,n);
		
			printf("\n\n\nInforme o metodo de ordenacao desejado\n\n\n");
			printf("1-Insertion\n\n2-Selection\n\n3-shell\n\n4-Quick\n\n5-sair\n");
			scanf("%d",&memoo);
			
			if(memoo==1){
				aux=copia(n,v);
			insertionsort (aux, l, n);
			//****
			}
			else if (memoo==2){
				aux=copia(n,v);
			selectionsort (aux, l, n);
			//*****
			}
			else if (memoo==3){
			
			}
			else if (memoo==4){
		
			}
			else if (memoo==5){
			
			}
			else{
				menu();
			}
		
		
					break;
					
					default:
					
					printf("Opcao invalida\n");
					menu();
					break;
	}

}

int preenchevetorcrescente(int n, int v[]){
	
	char str2[11];
	sprintf(str2, "%d", n);

	char str1[4]= "01_";
	strncat(str1, str2, 11);
	
	strcat(str1, ".dat");
	
	FILE *arquivo;
	arquivo= fopen (str1,"a");
	
	int i,aux;
	for (i=0;i<n;i++){
	 		aux=i;
			 v[i]=aux;
			 fprintf(arquivo," %d,",aux);	
			 }
		fclose(arquivo);
		 }


	int preenchevetordecrescente(int n, int v[]){
		
	char str2[11];
	sprintf(str2, "%d", n);

	char str1[4]= "02_";
	strncat(str1, str2, 11);
	
	strcat(str1, ".dat");
	
	FILE *arquivo;
	arquivo= fopen (str1,"a");
	

	int i,aux,a;
		for ((i=n-1)&&(a=0);i>=0;(i--)&&(a++)){
	 		aux=i;
			 v[a]=aux;	
			  fprintf(arquivo," %d,",aux);
			 }
			 fclose(arquivo);
		 }
	
		 
	int preencherandom(int n, int v[]){
		
	char str2[11];
	sprintf(str2, "%d", n);

	char str1[4]= "03_";
	strncat(str1, str2, 11);
	
	strcat(str1, ".dat");
	
	FILE *arquivo;
	arquivo= fopen (str1,"a");
	

	int opcao,i,aux;
		for (i=0;i<n;i++){
			v[i]=rand();
			 fprintf(arquivo," %d,",aux);
		}
		fclose(arquivo);
		 }
		


void exchangee (int *a,int *b){
	int aux;
	aux=*a;
	*a=*b;
	*b=aux;
}

void compexchangee (int a, int b){
	if(b<a){
			int aux;
	aux=a;
	a=b;
	b=aux;
	}
	exchangee(a,b);
}

void selectionsort (double v[], int l, int n){
	int i,j;
	printf("Insira a posicao inicial desejada\n Recomendamos escolher essa opcao como 0\n\n");
	scanf("%d",&l);
	
	for (i=l; i<n;i++){
		int min=i;
		for(j=i+1;j<=n;j++){
			if(v[j]<v[min]){
				min=j;
        break;
			}}
			compexchangee (v[i], v[min]);
	}
}

void insertionsort (double v[], int l, int n){
	int i,j;
	printf("Insira a posicao inicial desejada\n Recomendamos escolher essa opcao como 0\n\n");
	scanf("%d",&l);
	for(i= l+1; i<=n;i++)
	for (j=i;j>l;j--)
	compexchangee (v[j-1], v[j]);
}

int copia (int n, int v[]){
	
	int aux;
	aux = (int *) malloc(n*sizeof(int));
	
	int i=0;
	char str2[11];
	sprintf(str2, "%d", n);

	char str1[4]= "02_";
	strncat(str1, str2, 11);
	
	strcat(str1, ".dat");
	
	FILE *arquivo;
	arquivo= fopen (str1,"rt");
	
	while(!feof(arquivo)){
		fscanf("%d",v[i]);
		aux = v;
		i++;
		}
	return aux;
}

int main(){
	
	 menu ();
	 
	return 0;
}
