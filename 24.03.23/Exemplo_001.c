#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");

	FILE * arq;
	
	// modo write
	
	arq = fopen("series.txt", "w"); // modo write escreve por cima do que estiver no arquivo

	if(arq == NULL){
		printf("Erro ao abrir o arquivo\n");
		return -1;
	}

	fprintf(arq, "braking bad\n");
	fprintf(arq, "The Flash\n");
	fprintf(arq, "seinfeld\n");
	fprintf(arq, "mandalorian\n");
	
	fclose(arq);

	// modo append

	arq = fopen("series.txt", "a"); // modo append escreve após o que estiver no arquivo

	if(arq == NULL){
		printf("Erro ao abrir o arquivo\n");
		return -1;
	}

	fprintf(arq, "braking bode\n");
	fprintf(arq, "The big bang theori\n");
	fprintf(arq, "sea\n");
	fprintf(arq, "marciano\n");
	
	fclose(arq);
	
	// modo read
	
	arq = fopen("series.txt", "r"); // modo read lê o que estiver no arquivo
	
	linha[100];
	
	fscanf();
	fgets(linha, 100, arq); // (variavel, capacidade, arquivo) 
	
	fclose(arq);
	
	return 0;
}
