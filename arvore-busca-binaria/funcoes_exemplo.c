#include <stdio.h>
#include <stdlib.h>


typedef int Item;
typedef struct arv *Arv;

struct arv{
    Arv esq;
    Item item;
    Arv dir;
};

Arv arv(Arv e, Item x, Arv d){
    Arv n = malloc(sizeof(struct arv));
    n->esq = e;
    n->item = x;
    n->dir = d;
    return n;
}

// Para exibir a árvore
void exibe(Arv A,int n){
    if(A == NULL) return;
    exibe(A->dir, n+1);
    printf("%*s%d\n",3*n,"", A -> item);
    exibe(A->esq, n+1);
}

// Para inserir valores
void ins(Item x, Arv *A){
    if(*A == NULL) *A = arv(NULL, x, NULL);
    else if(x <= (*A)->item) ins(x, &(*A)->esq);
    else ins(x, &(*A)->dir);
}

// Percorrer a árvore em ordem
void emordem(Arv A){
    if(A == NULL) return;
    emordem(A->esq);
    printf("%d ", A->item);
    emordem(A->dir);
}

// Percorrer a árvore em ordem inversa
void emordem_inversa(Arv A){
    if(A == NULL) return;
    emordem_inversa(A->dir);
    printf("%d ", A->item);
    emordem_inversa(A->esq);
}


//Buscar itens pela árvore
int busca(Item x, Arv A){
    if(A == NULL) return 0;
    if(x == A->item) return 1;
    if(x < A->item) return busca(x,A->esq);
    else return busca(x, A->dir);
}

//Remover o item máximo
Item remmax(Arv *A){
    if(*A == NULL) abort();
    if((*A)->dir == NULL){
        Arv n = *A;
        Item x = n->item;
        *A = n->esq;
        free(n);
        return x;
    }
    return remmax(&(*A)->dir);
}

//Remover a raiz
void remraiz(Arv *A){
    if(*A == NULL) abort();
    Arv n = *A;
    if(n->esq == NULL) *A = n->dir;
    else if(n->dir == NULL) *A = n->esq;
    else n->item = remmax(&n->esq);
    if(n != *A) free(n);
}

//Remover um item
void rem(Item x, Arv *A){
    if(*A == NULL) return;
    if(x == (*A)->item) remraiz(A);
    else if(x < (*A)->item) rem(x, &(*A)->esq);
    else rem(x, &(*A)->dir);
}

//inserir um item
void ins_sr(Item x, Arv *A){
    if(*A == NULL) *A = arv(NULL, x, NULL);
    else if(x < (*A)->item) ins_sr(x, &(*A)->esq);
    else if(x > (*A)->item) ins_sr(x, &(*A)->dir);
}

//remover todos os itens
void rem_todos(Item x, Arv *A){
    if(*A == NULL) return;
    if(x == (*A)->item){
        remraiz(A);
        rem_todos(x, A);
    }
    else if(x < (*A)->item) rem_todos(x, &(*A)->esq);
    else rem_todos(x, &(*A)->dir);
}

//Retornar o item máximo
Item maximo(Arv A) {
    if(A == NULL) abort();
    if(A->dir == NULL) return A->item;
    return maximo(A->dir);
}

//Contar itens da árvore
int conta(Item x, Arv A){
    if(A == NULL) return 0;
    return (x == A->item)
    + conta(x, A->esq)
    + conta(x, A->dir);
}

// Verificar igualdade
int iguais(Arv A, Arv B){
    if(A==NULL && B==NULL) return 1;
    if(A==NULL || B==NULL) return 0;
    if(A->item != B->item) return 0;
    return iguais(A->esq, B->esq) && iguais(A->dir, B->dir);
}

//retornar árvore em espelho
int espelho(Arv A, Arv B){
    if(A==NULL && B==NULL) return 1;
    if(A==NULL || B==NULL) return 0;
    if(A->item != B->item) return 0;
    return espelho(A->esq, B->dir) && espleho(A->dir, B->esq);
}

//programa aplicativo, exemplo 1
int main(void){
    Arv A = arv(arv(arv(NULL,3,NULL),7,arv(NULL,1,NULL)),3,arv(arv(NULL,3,NULL),3,arv(arv(NULL,3,NULL),6,NULL)));
    exibe(A, 0);
    printf("conta(3,A) = %d\n", conta(3,A));
    return 0;
}

//Programa aplicativo, exemplo 2
int main(void) {
    Arv I = NULL;
    ins(7,&I);
    ins(4,&I);
    ins(6,&I);
    ins(8,&I);
    ins(2,&I);
    ins(5,&I);
    ins(3,&I);
    ins(1,&I);
    exibe(I, 0);
    puts("-------------");
    emordem(I);
    puts("\n-------------");
    emordem_inversa(I);
    puts("\n-------------");
    return 0;
}
