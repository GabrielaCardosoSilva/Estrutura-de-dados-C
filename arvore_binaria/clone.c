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

void exibe(Arv A, int h){
    if (A == NULL) return;
    exibe(A->dir, h+1);
    printf("%*s %d\n", 3*h, ".", A->item);
    exibe(A->esq, h+1);
}

Arv clone(Arv A) {
if( A == NULL ) return NULL;
return arv(clone(A->esq), A->item ,clone(A->dir));
}
  
int main (void){
    Arv I = arv(arv(NULL,2,NULL), 1, arv(NULL,3,arv(NULL,4,NULL))); 
    Arv J = clone(I);
    printf("Arvore I:\n");
    exibe(I, 0);
    printf("Arvore J:\n");
    exibe(J, 0);
    return 0;
}