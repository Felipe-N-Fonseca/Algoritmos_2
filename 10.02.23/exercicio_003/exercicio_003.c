#include <stdio.h>

int main () {
    float celsius, fahrenheit;

    printf("forneça a sua temperatura em c°: ");
    scanf("%f", &celsius);

    fahrenheit = 9.0/5.0*celsius+32;

    printf("Uma temperatura de %.1f graus Celsius equivale a %.1f graus Fahrenheit. \n", celsius, fahrenheit);
    
    return 0;
}