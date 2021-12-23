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

int folhas(Arv A) {
    if( A == NULL ) return 0;
    if( A->esq == A->dir ) return 1;
    return folhas(A->esq) + folhas(A->dir);
}
  
int main (void){
    Arv I = arv(arv(NULL,2,NULL), 1, arv(NULL,3,arv(NULL,4,NULL))); 
    printf ("\nFolhas = %d\n", folhas(I));
    return 0;
}