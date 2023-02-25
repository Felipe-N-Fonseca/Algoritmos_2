#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
    int dado, palpite;
    srand(time(NULL));
    dado = 1 + rand()%100;
    printf("digite seu palpite: ");
    scanf("%d", &palpite);
    while (1 <= palpite && palpite >= 100){
	    printf("digite novamente: ");
	    scanf("%d", &palpite);	    
	}
	if (palpite == dado){
		printf("Parabéns!!! Você acertou!");
	} else if (palpite < dado) {
		printf("Você chutou muito baixo! O valor correto é %d", dado);		
	}else {
		printf("Você chutou muito alto! O valor correto é %d", dado);
	}
	


    return 0;
}
