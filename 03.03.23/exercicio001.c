#include<stdio.h>
#include<locale.h>

float numerica(float a, float b, float c){
	float d;
	d = a + b + c;

	return d;
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	float x, y, z;	
	
	printf("digite o 1° termo: ");
	scanf("%f", &x);
	printf("digite o 1° termo: ");
	scanf("%f", &y);
	printf("digite o 1° termo: ");
	scanf("%f", &z);
	
	printf("a soma de %.2f, %.2f e %.2f é de %.2f", x, y, z, numerica(x, y, z));
	
	return 0;
}
