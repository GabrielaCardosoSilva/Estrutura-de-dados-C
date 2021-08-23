// Crie a função recursiva cr(n), que exibe uma contagem progressiva de n≥0 até 1.

 #include <stdio.h>

 void cp(n){
    if (n == 0) return;
    printf("%d", n);
    cp(n-1);
 }

 int main(){
     int n;

     printf("Digite um numero: ");
     scanf("%d", &n);
     cp(n);

     return 0;
 }