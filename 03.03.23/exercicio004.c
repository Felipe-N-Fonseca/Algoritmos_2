#include<stdio.h>
#include<locale.h>

int verifica(int n, int d){
	if((n%d) == 0){
		return 1;
	}else{
		return 0;
	}
}

int quantos(m){
	int qtd, i;
	qtd = 0;
	for(i = 1; i <= m; i++){
		if(verifica(m, i) == 1){
			qtd++;

		}
	}
	return qtd;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int num;
	
	printf("digite um número inteiro: ");
	scanf("%d", &num);
	printf("%d", quantos(num));
	
	return 0;
}
