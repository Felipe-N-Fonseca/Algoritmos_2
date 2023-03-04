#include<stdio.h>
#include<locale.h>

void tabuada(int n){
	printf("digite um número: ");
	scanf("%d", &n);
	printf("01*%d = %d\n02*%d = %d\n03*%d = %d\n04*%d = %d\n05*%d = %d\n06*%d = %d\n07*%d = %d\n08*%d = %d\n09*%d = %d\n10*%d = %d\n", n, n, n, n*2, n, n*3, n, n*4, n, n*5, n, n*6, n, n*7, n, n*8, n, n*9, n, n*10);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
		
	tabuada(0);
	
	return 0;
}
