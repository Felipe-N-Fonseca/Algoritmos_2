#include <stdio.h>

int main () {
    int n1,n2;

    printf("forneça 1° número: ");
    scanf("%d", &n1);
    printf("forneça 2° número: ");
    scanf("%d", &n2);

    printf("%d+%d=%d \n", n1, n2, n1+n2);
    printf("%d-%d=%d \n", n1, n2, n1-n2);
    printf("%d*%d=%d \n", n1, n2, n1*n2);
    printf("%d/%d=%d \n", n1, n2, n1/n2);

    return 0;
}