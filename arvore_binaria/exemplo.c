#include <stdio.h>
#include <stdlib.h>
#include <minmax.h>

//Tipo árvore:
typedef int Item;
typedef struct arv {
   struct arv *esq;
   Item item;
   struct arv *dir;
} *Arv;


//criação de nós:
Arv arv(Arv e, Item x, Arv d) {
   Arv n = malloc(sizeof(struct arv));
   n->esq  = e;
   n->item = x;
   n->dir  = d;
   return n;
}

//criação de árvore binária:
Arv I = arv(avr(NULL,2,NULL), 1, arv(NULL,3,arv(NULL,4,NULL))); 

//Exibição de árvore binária
void exibe(Arv A, int h){
    if (A == NULL) return;
    exibe(A->dir, h+1);
    printf("%*s %d/n", 3*h, ".", A->item);
    exibe(A->esq, h+1);
}

//quando tem um *s, o asterisco exige que vc mostre quantos espaços terá.

int main(void){
    Arv I = arv(arv(NULL,2,NULL),1, arv(NULL, 3, arv(NULL, 4, NULL)));
    exibe (I, 0);
    return 0;
}

// _______________________________________________________
//Criação de árvore completa aleatória, com altura h:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


Arv completa(int h) {
   if(h == 0) return NULL;
   return arv(completa(h-1), rand()%100, completa(h-1));
}

int main (void){
    srand(time(NULL));
    Arv A = completa(3);
    exibe (A, 0);
    return 0;
}

// _______________________________________________________
//Árvore aleatória balanceada (com no máx 1 descendente de diferença entre os lados)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//n = número de itens
//ne = número de itens à esquerda ((n-1) por causa da raíz)
Arv balanceada(int n) {
   if(n == 0) return NULL;
   int ne = (n-1) / 2
   return arv(balanceada(ne), rand()%100, balanceada(n-1-ne));
}

int main (void){
    Srand(time(NULL));
    Arv A = balanceada(7);
    exibe (A, 0);
    return 0;
}

// _____________________________________________________________
//Árvore aleatória
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


Arv aleatoria(int n) {
   if(n == 0) return NULL;
   int ne = rand()%n;
   return arv(aleatoria(ne), rand()%100, aleatoria(n-1-ne));
}

int main (void){
    Srand(time(NULL));
    Arv A = aleatoria(7);
    exibe (A, 0);
    return 0;
}

// ______________________________________________
//Quantidade de nós na árvore

int nos(Arv A){
    if (A == NULL) return 0;
    return 1 + nos(A -> esq) + nos(A -> dir);
}

// No pgm principal:
// printf ("\nnos = %d/n", nos(A));


// ______________________________________________
//Soma dos nós na árvore
Item soma (Arv A){
    if (A == NULL) return 0;
    return A->item + soma(A->dir) + soma(A->esq);
}

// No pgm principal:
// printf ("\nSoma = %d/n", soma(A));

// ______________________________________________
//Soma das folhas da árvore
int folhas (Arv A){
    if (A == NULL) return 0;
    if (A->esq == NULL && A->dir == NULL) return 1;
    return folhas(A->esq) + folhas(A->dir);
}

//2ª versão:
int folhas(Arv A) {
    if( A==NULL ) return 0;
    if( A->esq == A->dir ) return 1;
    return folhas(A->esq) + folhas(A->dir);
}

// No pgm principal:
// printf ("\nFolhas = %d/n", folhas(A));

// _________________________________________________
//Altura da árvore

int altura(Arv A){
    if(A == NULL) return 0;
    return 1 + (altura(A->esq), altura(A->dir));
}

// _________________________________________________
//Clone da árvore

Arv clone(Arv A) {
if( A==NULL ) return NULL;
return arv(clone(A->esq), A->item ,clone(A->dir));
}


// No pgm principal:
// Arv A = ...;
// Arv B = clone (A)

//____________________________________________
int pertence(Item x, Arv A) {
if( A==NULL ) return 0;
if( x==A->item ) return 1;
return pertence(x,A->esq) || pertence(x,A->dir);
}


//___________________________________________________
void preordem(Arv A) {
    if( A==NULL ) return;
    printf("%d ", A->item); // R
    preordem(A->esq); // E
    preordem(A->dir); // D
}



void emordem(Arv A) {
    if( A==NULL ) return;
    emordem(A->esq); // E
    printf("%d ", A->item); // R
    emordem(A->dir); // D
}



void posordem(Arv A) {
    if( A==NULL ) return;
    posordem(A->esq); // E
    posordem(A->dir); // D
    printf("%d ", A->item); // R
}


// ---------------------------------
[12:49] SILVIO DO LAGO PEREIRA
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <minmax.h>

typedef int Item;typedef struct arv {​​​​
struct arv *esq;
Item item;
struct arv *dir;
}​​​​ *Arv;Arv arv(Arv e, Item x, Arv d) {​​​​
Arv n = malloc(sizeof(struct arv));
n->esq = e;
n->item = x;
n->dir = d;
return n;
}​​​​// percurso em-ordem inversavoid exibe(Arv A, int h) {​​​​
if( A==NULL ) return;
exibe(A->dir, h+1); // D
printf("%*s%d\n", 3*h, "", A->item); // R
exibe(A->esq, h+1); // E
}​​​​Arv completa(int h) {​​​​
if( h==0 ) return NULL;
return arv(completa(h-1), rand()%100, completa(h-1));
}​​​​Arv balanceada(int n) {​​​​
if( n==0 ) return NULL;
int ne = (n-1)/2;
return arv(balanceada(ne), rand()%100, balanceada(n-1-ne));
}​​​​Arv aleatoria(int n) {​​​​
if( n==0 ) return NULL;
int ne = rand()%n;
return arv(aleatoria(ne), rand()%100, aleatoria(n-1-ne));
}​​​​int nos(Arv A) {​​​​
if( A == NULL ) return 0;
return 1 + nos(A->esq) + nos(A->dir);
}​​​​Item soma(Arv A) {​​​​
if( A==NULL ) return 0;
return A->item + soma(A->esq) + soma(A->dir);
}​​​​int folhas(Arv A) {​​​​
if( A==NULL ) return 0;
if( A->esq==A->dir ) return 1;
return folhas(A->esq) + folhas(A->dir);
}​​​​int altura(Arv A) {​​​​
if( A==NULL ) return 0;
return 1 + max(altura(A->esq), altura(A->dir));
}​​​​Arv clone(Arv A) {​​​​
if( A==NULL ) return NULL;
return arv(clone(A->esq), A->item ,clone(A->dir));
}​​​​int pertence(Item x, Arv A) {​​​​
if( A==NULL ) return 0;
if( x==A->item ) return 1;
return pertence(x,A->esq) || pertence(x,A->dir);
}​​​​void preordem(Arv A) {​​​​
if( A==NULL ) return;
printf("%d ", A->item); // R
preordem(A->esq); // E
preordem(A->dir); // D
}​​​​void emordem(Arv A) {​​​​
if( A==NULL ) return;
emordem(A->esq); // E
printf("%d ", A->item); // R
emordem(A->dir); // D
}​​​​void posordem(Arv A) {​​​​
if( A==NULL ) return;
posordem(A->esq); // E
posordem(A->dir); // D
printf("%d ", A->item); // R
}​​​​void poda(Arv *A) {​​​​
if( *A == NULL ) return;
if( (*A)->esq == (*A)->dir ) {​​​​ // R
free(*A);
*A = NULL;
}​​​​
else {​​​​
poda(&(*A)->esq); // E
poda(&(*A)->dir); // D
}​​​​
}​​​​void destroi(Arv *A) {​​​​
if( *A == NULL ) return;
destroi(&(*A)->esq); // E
destroi(&(*A)->dir); // D
free(*A); // R
*A = NULL;
}​​​​int main(void) {​​​​
srand(time(NULL));
Arv A = arv(arv(arv(NULL,
9,
NULL),
2,
arv(NULL,
5,
NULL)),
1,
arv(NULL,
3,
NULL)); exibe(A, 0);
printf("-----------\n");
getchar();
poda(&A);
exibe(A, 0);
printf("-----------\n");
getchar();
destroi(&A);
exibe(A, 0);
printf("-----------\n");
return 0;
}​​​​/*
Arv I = arv(arv(arv(NULL,
9,
NULL),
2,
arv(NULL,
5,
NULL)),
1,
arv(arv(NULL,
0,
NULL),
3,
arv(NULL,
4,
NULL)));
*/

void poda(Arv *A) {
    if( *A == NULL ) return;
    if( (*A)->esq == (*A)->dir ) { // R
    free(*A);
    *A = NULL;
    }
    else {
    poda(&(*A)->esq); // E
    poda(&(*A)->dir); // D
}
}

void destroi(Arv *A) {
    if( *A == NULL ) return;
    destroi(&(*A)->esq); // E
    destroi(&(*A)->dir); // D
    free(*A); // R
    *A = NULL;
    }
