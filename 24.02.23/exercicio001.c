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
		printf("Parab�ns!!! Voc� acertou!");
	} else if (palpite < dado) {
		printf("Voc� chutou muito baixo! O valor correto � %d", dado);		
	}else {
		printf("Voc� chutou muito alto! O valor correto � %d", dado);
	}
	


    return 0;
}
