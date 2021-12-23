#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;
typedef struct arv {
   struct arv *esq;
   Item item;
   struct arv *dir;
} *Arv;

Arv arv(Arv e, Item x, Arv d) {
   Arv n = malloc(sizeof(struct arv));
   n->esq  = e;
   n->item = x;
   n->dir  = d;
   return n;
}

void exibe(Arv A, int h){
    if (A == NULL) return;
    exibe(A->dir, h+1);
    printf("%*s %d\n", 3*h, ".", A->item);
    exibe(A->esq, h+1);
}

//n = número de itens
//ne = número de itens à esquerda ((n-1) por causa da raíz)
Arv balanceada(int n) {
   if(n == 0) return NULL;
   int ne = (n-1) / 2;
   return arv(balanceada(ne), rand()%100, balanceada(n-1-ne));
}

int main (void){
    srand(time(NULL));
    exibe (balanceada(9), 0);
    return 0;
}