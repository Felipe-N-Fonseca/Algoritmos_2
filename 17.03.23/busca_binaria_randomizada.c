#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

void randomizador(int qtd, int lista[]){
	srand(time(NULL));
	int numero, i;
	lista[0] = (rand()%10) + 1;
	for(i = 1; i < qtd; i++){
		numero = (rand()%10) + 1;
		lista[i] = numero + lista[i-1];	
	}
}

int busca_binaria(int v[], int n, int e){
	int ini = 0;
	int fim = n-1;
	int meio;
	while(ini <= fim){
		meio = (ini + fim)/2;
		if(v[meio] == e){
			return meio;
		} else if(v[meio] > e){
			fim = --meio;
		} else {
			ini = ++meio;
		}
	}
	return -1;
}

int main(){
	setlocale(LC_ALL, "Portuguese"); // define o idioma pra portugês
	
	// inicia a contagem de tempo de execução
	clock_t t;
	t = clock();
	
	// cria a array com a quantidade certa de valores
	int N;
	printf("Digite quantos números deseja: ");
	scanf("%d", &N);
	int numeros[N];
	
	// gera uma quantiade de números definida pelo usuário e a adiciona a array "numeros"
	randomizador(N, numeros);
	
	// mostra os números dentro da array
	int i;
	printf("Números gerados:\n[%d, ", numeros[0]);
	for(i = 1; i < N-1; i++){
		printf("%d, ", numeros[i]);	
	}
	printf("%d]\n", numeros[N-1]);
	
	// procura o elemento desejado pelo usuário e retorna uma resposta
	printf("elemento a ser buscado: ");
	int elemento;
	scanf("%d", &elemento);
	printf("O índice do valor buscado é: %d\n", busca_binaria(numeros, N, elemento));
	
	// finaliza a contagem de tempo de execução e a mostra
	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("o programa demorou %.3f segundos para executar \n", time_taken);
	
	return 0;
}
