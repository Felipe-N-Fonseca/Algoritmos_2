#include<stdio.h>
#include<string.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");

	FILE * arq;
	
	arq = fopen("filmes.txt", "r");
	
	if(NULL == arq){
		printf("erro");
		return -1;
	}
	
	char filme[150];
	while(!feof(arq)){
		if(NULL != fgets(filme, 150, arq)){
			int tamanho = strlen(filme);
			filme[tamanho-1] = "\0";
			printf("- %s ", filme);
		}
		
	}
	
	

	return 0;
}
