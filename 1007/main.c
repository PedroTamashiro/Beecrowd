#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
    int A, B, C, D, Dif;
    scanf("%i", &A);
    scanf("%i", &B);
    scanf("%i", &C);
    scanf("%i", &D);
    Dif = ((A*B)-(C*D));

    printf("DIFERENCA = %i\n",  Dif);
}