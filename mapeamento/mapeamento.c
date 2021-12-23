#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Chave;
typedef char Valor[22];
typedef struct map {​​​​​
Chave chave;
Valor valor;
struct map *prox;
}​​​​​ *Map;
Map no_map(Chave c, Valor v, Map p) {​​​​​
Map n = malloc(sizeof(struct map));
n->chave = c;
strcpy(n->valor,v);
n->prox = p;
return n;
}​​​​​
// iterativa
void insm(Chave c, Valor v, Map *M) {​​​​​
while( *M && c>(*M)->chave ) M = &(*M)->prox;
if( *M && c==(*M)->chave ) strcpy((*M)->valor,v);
else *M = no_map(c,v,*M);
}​​​​​
// recursiva
void insmr(Chave c, Valor v, Map *M) {​​​​​
if( *M==NULL || c<(*M)->chave ) *M = no_map(c,v,*M);
else if( c==(*M)->chave ) strcpy((*M)->valor,v);
else insmr(c, v, &(*M)->prox);
}​​​​​
void exibem(Map M) {​​​​​
printf("[");
while( M ) {​​​​​
printf("(%d,%s)",M->chave,M->valor);
if( M->prox ) printf(",");
M = M->prox;
}​​​​​
printf("]\n");
}​​​​​
int main(void) {​​​​​
Map I = NULL;
insmr(36,"Leo",&I);
insmr(15,"Ivo",&I);
insmr(42,"Eva",&I);
insmr(29,"Ana",&I);
exibem(I);
insmr(29,"Bia",&I);
exibem(I);
insmr(78,"Katia",&I);
exibem(I);
return 0;
}​​​​​

//////////////////////////////////////////////////////////////////////////////

void remm(Chave c, Map *M) {
while( *M && c>(*M)->chave ) M = &(*M)->prox;
if( *M==NULL || c!=(*M)->chave ) {
printf("Keyerror: %d\n", c);
abort();
}
Map n = *M;
*M = n->prox;
free(n);
}


///////////////////////////////////////////////////////////////////////////////

void destroim(Map *M) {
while( *M ) {
Map n = *M;
*M = n->prox;
free(n);
}
}

///////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Chave;

typedef int Valor;

typedef struct map {
Chave chave;
Valor valor;
struct map *prox;
} *Map;

Map no_map(Chave c, Valor v, Map p) {
Map n = malloc(sizeof(struct map));
n->chave = c;
n->valor = v;
n->prox = p;
return n;
}

void insm(Chave c, Valor v, Map *M) {
while( *M && c>(*M)->chave ) M = &(*M)->prox;
if( *M && c==(*M)->chave ) (*M)->valor = v;
else *M = no_map(c,v,*M);
}

void exibem(Map M) {
printf("[");
while( M ) {
printf("(%d,%d)",M->chave,M->valor);
if( M->prox ) printf(",");
M = M->prox;
}
printf("]\n");
}

void remm(Chave c, Map *M) {
while( *M && c>(*M)->chave ) M = &(*M)->prox;
if( *M==NULL || c!=(*M)->chave ) return;
Map n = *M;
*M = n->prox;
free(n);
}

int pertm(Chave c, Valor *v, Map M) {
while( M && c>M->chave ) M = M->prox;
if( M && c==M->chave ) *v = M->valor;
return (M && c==M->chave);
}

void destroim(Map *M) {
while( *M ) {
Map n = *M;
*M = n->prox;
free(n);
}
}

int main(void) {
Valor w;
Map I = NULL;
insm(36, 100, &I);
insm(15, 200, &I);
insm(42, 300, &I);
exibem(I);
getchar();
if( pertm(36,&w,I) ) printf("36 ==> %d\n", w);
else puts("Chave 36 inexistente!");
getchar();
if( pertm(99,&w,I) ) printf("36 ==> %d\n", w);
else puts("Chave 99 inexistente!");
getchar();
remm(36, &I);
exibem(I);
getchar();
destroim(&I);
exibem(I);
return 0;
}


////////////////////////////////////////////////////////////////////
void destroid(Dic *d) {
for(int i=0; i<(*d)->tam; i++)
destroim(&(*d)->vet[i]);
free((*d)->vet);
free(*d);