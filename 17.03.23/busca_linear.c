#include<stdio.h>
#include<locale.h>

int busca_linear(int v[], int n, int e){
	int i;
	for(i = 0; i < n; i++){
		if(v[i] == e){
			return i;
		}
	}
	return -1;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int numeros[] = {88, 7, 999, 68, 4, 9};
	int N = 6;
	printf("elemento a ser buscado: ");
	int elemento;
	scanf("%d", &elemento);
	printf("Resposta: %d", busca_linear(numeros, N, elemento));
	
	return 0;
}
