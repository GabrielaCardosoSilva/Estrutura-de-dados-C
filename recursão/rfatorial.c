//criar a função recursiva para calcular o fatorial de um número natural

#include<stdio.h>

int fat(int n){
    if (n==0) return 1; //base
    else return n*fat(n-1); //passo
}

int main(){
    int n;
    printf("Digite um numero natural: \n");
    scanf("%d", &n);
    printf("Fatorial = %d\n", fat(n));
    return 0;
}