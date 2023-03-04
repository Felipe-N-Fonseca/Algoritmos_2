#include<stdio.h>
#include<locale.h>
#include<stdbool.h>
#include<math.h>

float funcao(int n){
	float r;
	int k;
	r = 0.0;
	for(k = 1; k <= n; k++){
		r += ((k / pow(k,2)) * pow((-1.0),(k+1)));
	}
	return r;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int n1;
	
	printf("digite um número inteiro: ");
	scanf("%d", &n1);
	
	printf("%.7f", funcao(n1));
	
	
	return 0;
}
