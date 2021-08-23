//Inversão de cadeia de caracteres

#include <stdio.h>
#include "pilha.h"

int main(void) {
    char c[513];  //Strings em C são vetores de caracteres
    Pilha P = pilha(513);

    printf("Qual a cadeia de caracteres? ");
    gets(c);

    for(int i=0; c[i]; i++) //percorrer os indices da cadeia
        empilha(c[i],P);
    printf("Inverso: ");

    while( !vaziap(P) )
        printf("%c", desempilha(P));
    puts("\n");

    destroip(&P);

    return 0;
}