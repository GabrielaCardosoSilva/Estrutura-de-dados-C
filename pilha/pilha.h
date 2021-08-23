// pilha.h - implementacao dinamica sequencial de pilha

//FUNCIONAMENTO:
// pilha (m) - Cria e devolve uma pilha vazia P, com tmanho m.
// vaziap(P) - Devolve verdade se, e só se, a pilha P estiver vazia.
// cheiap(P) - Devolve verdade se, e só se, a pilha P estiver cheia.
// empilha(x,P) - Insere o item x no topo da pilha P.
// desempilha(P) - Remove e devolve o item que estiver no topo de P.
// topo(P) - Acessa e devolve o item que estiver no topo de P.
// destroip(&P) - Destrói a pilha P.

#include <stdlib.h>

typedef int Itemp;

typedef struct pilha {
   int    max;
   int    topo;
   Itemp *item;
} *Pilha;

Pilha pilha(int m) {
   Pilha P = malloc(sizeof(struct pilha));
   P->max  = m;
   P->topo = -1;
   P->item = malloc(m*sizeof(Itemp));
   return P;
}

int vaziap(Pilha P) {
   if( P->topo == -1 ) return 1;
   else return 0;
}

int cheiap(Pilha P) {
   if( P->topo == P->max-1 ) return 1;
   else return 0;
}

void empilha(Itemp x, Pilha P) {
   if( cheiap(P) ) {printf("pilha cheia!"); abort(); }
   P->topo++;
   P->item[P->topo] = x;
}

Itemp desempilha(Pilha P) {
   if( vaziap(P) ) { printf("pilha vazia!"); abort(); }
   Itemp x = P->item[P->topo];
   P->topo--;
   return x; 
}

Itemp topo(Pilha P) {
   if( vaziap(P) ) { printf("pilha vazia!"); abort(); }
   return P->item[P->topo];
}

void destroip(Pilha *Q) {
   free((*Q)->item);
   free(*Q);
   *Q = NULL;
}