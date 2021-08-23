// Crie a função recursiva binário(n), que exibe um natural n≥0 em binário.

#include <stdio.h>

void binario(n){
    if (n == 0) return 0;
    else{
        binario(n/2);
        printf("%d", n%2);
    }
}

int main(void) {
   int n;
   printf("Informe um numero: ");
   scanf("%d",&n);
   binario(n);
   return 0;
}