#include<stdio.h>
#include<locale.h>

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
	setlocale(LC_ALL, "Portuguese");
	
	int numeros[] = {1, 2, 7, 8, 9};
	int N = 5;
	printf("elemento a ser buscado: ");
	int elemento;
	scanf("%d", &elemento);
	printf("Resposta: %d\n", busca_binaria(numeros, N, elemento));
	
	return 0;
}
