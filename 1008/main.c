#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
    int Num, Hora;
    float Valor, Salario;
    scanf("%i", &Num);
    scanf("%i", &Hora);
    scanf("%f", &Valor);
    Salario = Hora * Valor;
    printf("NUMBER = %i\n", Num);
    printf("SALARY = U$ %.2f\n", Salario);
}