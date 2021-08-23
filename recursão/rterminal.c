// Crie a função recursiva termial(n), que calcula a soma dos n primeiros números naturais (n ≥ 0).

#include <stdio.h>

int terminal (int n){
    if (n==0) return 0;
    return n+terminal(n-1);
}

int main(){
    int n;

    printf("Informe um numero natural: ");
    scanf("%d", &n);
    printf("Soma = %d\n", terminal(n));

    return 0;
}