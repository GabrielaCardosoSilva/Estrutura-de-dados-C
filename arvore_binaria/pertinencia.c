#include <stdio.h>
#include <stdlib.h>

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

int pertence(Item x, Arv A) {
    if( A == NULL ) return printf("valor inexistente");
    if( x == A->item ) return printf("valor encontrado");
    return pertence(x, A->esq) || pertence(x, A->dir);
}
  
int main (void){
    Arv I = arv(arv(NULL, 2, NULL), 1, arv(NULL, 3, arv(NULL, 4, NULL))); 
    printf("Pertinecia = ");
    pertence(5, I);
    return 0;
}


