#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int digito, i, div;
	
	printf("Escreva um n�mero inteiro: ");
	scanf("%d", &digito);
	
	printf("Os divisores de %d s�o:", digito);
	
	for (i = 1; i < 1 + digito; i++){
		div = digito % i;
		if(div == 0){
			printf(" %d", i);
		}
	}
	
	return 0;
}
