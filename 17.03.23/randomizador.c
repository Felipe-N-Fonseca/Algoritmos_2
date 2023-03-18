#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	srand(time(NULL));
	int numero, i;
	int lista[1000];
	lista[0] = 1;
	for(i = 1; i < 1000; i++){
		numero = (rand()%10) + 1;
		lista[i] = numero + lista[i-1];	
	}
	for(i = 0; i < 1000; i++){
		printf(", %d", lista[i]);	
	}
	
	return 0;
}
