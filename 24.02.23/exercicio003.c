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
		printf("Parabéns!!! Você acertou de primeira!");
	} else {
		while (palpite != dado){
			if (palpite < dado) {
				printf("Você chutou muito baixo! digite outro palpite: ");	
				scanf("%d", &palpite);
			}else {
				printf("Você chutou muito alto! digite outro palpite: ");
				scanf("%d", &palpite);
			}
			tentativas++;
			if (tentativas ==5){
				break;
			}
		}
		if (tentativas == 5){
			printf("você excedeu o número máximo de tentativas, o valor era: %d", dado);
		} else {
			printf("Parabéns!!! Você acertou em %d tentativas", tentativas);
		}
	}
	


    return 0;
}
