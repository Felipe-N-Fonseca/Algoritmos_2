#include <stdio.h>

int main () {
    float raio, area;

    printf("forneça o raio da sua circunferência: ");
    scanf("%f", &raio);

    area = raio*raio*3.14;

    printf("Um círculo com raio %.2f tem área igual a %.2f. \n", raio, area);
    
    return 0;
}