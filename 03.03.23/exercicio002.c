#include<stdio.h>
#include<locale.h>

float c2f(float c){
	return ((c*1.8)+32);
}

float f2c(float f){
	return ((f-32)*5/9);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int escolha;
	float temp;	
	
	printf("Escolha a conversão: \n(1) Converter de Celsius para Fahrenheit \n(2) Converter de Fahrenheit para Celsius \nResposta: ");
	scanf("%d", &escolha);
	
	if(escolha == 1){
		printf("digite a temperatura em celcius: ");
		scanf("%f", &temp);
		printf("A temperatura em fahrenheit é %.1f", c2f(temp));
	}else if(escolha == 2){
		printf("digite a temperatura em fahrenheit: ");
		scanf("%f", &temp);
		printf("A temperatura em celcius é %.1f", c2f(temp));
	}else{
		printf("valor inválido");
	}
	
	return 0;
}
