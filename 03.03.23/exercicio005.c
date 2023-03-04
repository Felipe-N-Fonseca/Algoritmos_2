#include<stdio.h>
#include<locale.h>
#include<stdbool.h>

bool primo(int n){
	int qtd, i;
	qtd = 0;
	for(i = 1; i <= n; i++){
		if((n%i) == 0){
			qtd++;
		}
	}
	if(qtd == 2){
		return true;
	}else{
		return false;
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int n1, n2, c;
	
	printf("digite um número inteiro: ");
	scanf("%d", &n1);
	printf("digite outro número inteiro: ");
	scanf("%d", &n2);
	
	if(primo(n1) == true){
		printf("%d é primo\n", n1);	
	}else{
		printf("%d não é primo\n", n1);
	}
	
	for(c = ++n1; c < n2; c++){
		if(primo(c) == true){
			printf("%d é primo	\n", c);
		}
	}
	
	if(primo(n2) == true){
		printf("%d é primo", n2);	
	}else{
		printf("%d não é primo", n2);
	}
	
	
	return 0;
}
