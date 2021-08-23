// Crie a função recursiva pot(x,n), que calcula a potência de
// um número real x ≠ 0 elevado a um número natural n.

#include<stdio.h>

float pot(float b, int e){
    if (e==0) return 1;
    else return b * pot(b, e - 1);
}

int main(void){
    float b;
    int e;

    printf("Quais sao a base e o expoente? ");
    scanf("%f %d", &b,&e);
    printf("Potencia: %.1f\n", pot(b,e));
    
    return 0;
}

