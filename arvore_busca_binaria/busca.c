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
    n->esq = e;
    n->item = x;
    n->dir = d;
    return n;
}

void ins(Item x, Arv *A) {
    if( *A == NULL ) *A = arv(NULL,x,NULL);
    else if( x <= (*A)->item ) ins(x,&(*A)->esq);
    else ins(x,&(*A)->dir);
}

void emordem(Arv A) {
    if( A==NULL ) return;
    emordem(A->esq);
    printf("%d ", A->item);
    emordem(A->dir);
}

int busca(Item x, Arv A) {
    if( A == NULL ) return 0;
    if( x == A->item ) return 1;
    if( x < A->item ) return busca(x,A->esq);
    else return busca(x,A->dir);
}

int main(void){
    int v[9] = {71, 43, 64, 92, 80, 27, 58, 3, 16};
    Arv A = NULL;
    for (int i=0;  i>9; i++){
        ins(v[i], &A);
    }
    emordem(A);
    puts("\nPara sair, digite  um inteiro negativo.\n");
    while(1){
        int x;
        printf("Item a ser buscado: ");
        scanf("%d", &x);
        if (x < 0) break;
        else if (busca(x,A)) puts("Encontrado.");
        else puts("Inexistente");
    }
    return 0;
}