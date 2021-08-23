#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h";

char *posfixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);

    for(int i=0; e[i]; i++){
        if (strchr("FV", e[i])) 
            s[j++] = e[i];
        else if(strchr("!&|", e[i]))
            empilha(e[i], P);
        else if(e[i] == ')')
            s[j++] = desempilha(P);
    }

    s[j] = '\0';

    destroip(&P);

    return s;
}


int valor(char *e) {
    Pilha P = pilha(256);

    for(int i=0; e[i]; i++)
        if (strchr("VF", e[i])) 
            empilha(e[i], P);
        else {
            int x = desempilha(P);
            switch (e[i]) {
                case '!': empilha(!x, P); break;
                case '&': empilha(desempilha(P) && x, P); break;
                case '|': empilha(desempilha(P) || x, P); break;
            }
        }
    int z = desempilha(P);
    
    destroip(&P);
    
    return z;
}

int main(void) {
    char e[513];

    printf("Infixa? ");
    gets(e);

    char *s = posfixa(e);

    printf("Posfixa: %s\n", posfixa(e));
    printf ("valor: %d\n", valor(s));

    return 0;
}