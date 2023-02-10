#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
    float A, B, C,  MEDIA, SOMA;
    scanf("%f", &A);
    A = A*2;
    scanf("%f", &B);
    B = B*3;
    scanf("%f", &C);
    C = C*5;

    SOMA =  A + B + C;
    MEDIA = SOMA/10;
    printf("MEDIA = %.1f\n", MEDIA);
}