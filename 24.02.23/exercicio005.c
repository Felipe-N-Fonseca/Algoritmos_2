#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int digito, i, div, soma;
	soma = 0;
	
	printf("Escreva um número inteiro: ");
	scanf("%d", &digito);
	
	for (i = 1; i < 1 + digito; i++){
		div = digito % i;
		if(div == 0){
			soma += i;
		}
	}
	if(soma == digito * 2){
		printf("%d é um número inteiro perfeito", digito);
	} else {
		printf("%d NÃO é um número inteiro perfeito", digito);
	}
	
	return 0;
}
