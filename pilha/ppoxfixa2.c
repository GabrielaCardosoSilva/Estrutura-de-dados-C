// COVERSÃO DE INFIXA PARA POSFIXA COM PRIORIDADE DE OPERADORES

// Inicie com uma pilha P e uma expressão posfixa s vazias.
// Para cada elemento da expressão infixa, da esquerda para a direita, faça :
// Se for um parêntese de abertura, empilhe-o em P.
// Se for um operando, anexe-o à expressão posfixa s.
// Se for um operador, enquanto o operador no topo tiver maior ou igual prioridade,
// desempilhe-o e anexe-o a s; depois, empilhe o operador encontrado na expressão.
// Se for um parêntese de fechamento, enquanto o item no topo não for parêntese de
// abertura, desempilhe-o e anexe-o s; depois, desempilhe e descarte o parêntese.
// Enquanto a pilha P não estiver vazia, desempilhe um operador e anexe-o a s.
// Devolva s como resultado.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h";

int prio(char o) {
    switch( o ) {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }

    return -1; // operador inválido!
}

char *posfixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);

    for(int i=0; e[i]; i++)
        if ( e[i]=='(' ) 
            empilha('(', P);
        else if (isdigit(e[i]))
            s[j++] = e[i];
        else if (strchr("+-/*", e[i])) {
            while (!vaziap(P) && prio(topo(P)) >= prio(e[i]))
                s[j++] = desempilha(P);
            empilha(e[i], P);
        }
        else if( e[i] == ')' ) {
            while( topo(P)!='(' )
                s[j++] = desempilha(P);
            desempilha(P);
        }
        
    while (!vaziap(P))
        s[j++] = desempilha(P);
    s[j] = '\0';
    
    destroip(&P);
    
    return s;
}


int valor(char *e) {
    Pilha P = pilha(256);

    for(int i=0; e[i]; i++)
        if( isdigit(e[i]) ) empilha(e[i]-'0',P);
        else {
            int y = desempilha(P);
            int x = desempilha(P);
            switch( e[i] ) {
            case '+': empilha(x+y,P); break;
            case '-': empilha(x-y,P); break;
            case '*': empilha(x*y,P); break;
            case '/': empilha(x/y,P); break;
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