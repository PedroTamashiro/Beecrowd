#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
    float A, B, MEDIA, SOMA;
    scanf("%f", &A);
    A = A*3.5;
    scanf("%f", &B);
    B = B*7.5;

    SOMA =  A + B;
    MEDIA = SOMA/11;
    printf("MEDIA = %.5f\n", MEDIA);
}