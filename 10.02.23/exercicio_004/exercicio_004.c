#include <stdio.h>
#include <math.h>

int main () {
    float c1, c2, hipo;

    printf("forneça o 1° cateto: ");
    scanf("%f", &c1);
    printf("forneça o 2° cateto: ");
    scanf("%f", &c2);

    hipo = sqrtf((c1*c1)+(c2*c2));

    printf("Um triângulo retângulo com lados %.2f e %.2f tem uma hipotenusa igual a %.2f. \n", c1, c2, hipo);
    
    return 0;
}