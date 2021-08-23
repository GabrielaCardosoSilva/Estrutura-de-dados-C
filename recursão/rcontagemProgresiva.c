// Crie a função recursiva cp(n), que exibe uma contagem progressiva de 1 até n≥0.
 
 #include <stdio.h>

 void cp(n){
    if (n == 0) return;
    cp(n-1);
    printf("%d", n);
 }

 int main(){
     int n;

     printf("Digite um numero: ");
     scanf("%d", &n);
     cp(n);

     return 0;
 }