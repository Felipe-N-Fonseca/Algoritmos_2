#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
    int dado, palpite;
    int tentativas = 0;
    srand(time(NULL));
    dado = 1 + rand()%100;
    printf("digite seu palpite: ");
    scanf("%d", &palpite);
    while (1 <= palpite && palpite >= 100){
	    printf("digite novamente: ");
	    scanf("%d", &palpite);	    
	}
	tentativas++;
	if (palpite == dado){
		printf("Parab�ns!!! Voc� acertou de primeira!");
	} else {
		while (palpite != dado){
			if (palpite < dado) {
				printf("Voc� chutou muito baixo! digite outro palpite: ");	
				scanf("%d", &palpite);
			}else {
				printf("Voc� chutou muito alto! digite outro palpite: ");
				scanf("%d", &palpite);
			}
			tentativas++;
		}
		printf("Parab�ns!!! Voc� acertou em %d tentativas", tentativas);
	}
	


    return 0;
}
