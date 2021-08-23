// Crie a função recursiva h(n), que calcula a soma dos n≥1 primeiros termos da série harmônica (1 + 1/2 + 1/3 + ... + 1/n).

#include <stdio.h>

float h(n){
    if (n == 1) return 1;
    else return 1.0/n + h(n - 1);
}

int main(){
    int n;

    printf("Informe um numero: ");
    scanf("%d", &n);
    printf("Serie harmonica = %.2f\n", h(n));

    return  0;
}
