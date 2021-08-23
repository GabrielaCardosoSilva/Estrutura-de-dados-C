#include <stdio.h>   //para arquivos padrão.
#include "pilha.h"   //para arquivos feito pelo programador.

int main(void) {
    int n; //4 bits
    Pilha P = pilha(8*sizeof(int)); //0000 0000 0000 0000 0000 0000 0000 0000

    printf("Qual o numero decimal? ");
    scanf("%d",&n);

    do {
        empilha(n % 2, P);
        n /= 2;
    } while( n > 0 );

    printf("Correspondente binario: ");
    
    while( !vaziap(P) )
        printf("%d",desempilha(P));

    destroip(&P);

    return 0;
}