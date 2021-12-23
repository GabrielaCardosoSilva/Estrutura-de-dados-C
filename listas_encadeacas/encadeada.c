//tipo Lista:
typedef int Item;
typedef struct no {
   Item item;
   struct no *prox;
} *Lista;


//criação de nó:
Lista no(Item x, Lista p) {
   Lista n = malloc(sizeof(struct no));
   n->item = x;
   n->prox = p;
   return n;
}

//criação de lista:
Lista I = no(3, no(1, no(5, NULL)));

//Exibição de lista:
void exibe(Lista L) {
   while( L != NULL ) {
      printf("%d\n",L->item);
      L = L->prox;
   }
}

//tamanho da lista:
int tamanho(Lista L) {
   int t = 0;
   while( L ) {
      t++;
      L = L->prox;
   }
   return t; 
}

//criação de listas aleatórias
//n = tamanho da lista
//m = intervalo
Lista aleatoria(int n, int m) {
   Lista L = NULL;
   while( n>0 ) {
      L = no(rand()%m, L);
      n--;
   }
   return L;
}

//anexação de listas
void anexa(Lista *A, Lista B) {
   if( !B ) return;
   while( *A )
      A = &(*A)->prox;
   *A = B;
}

//Destruição de listas
void destroi(Lista *L) {
   while( *L ) {
      Lista n = *L;
      *L = n->prox;
      free(n);
   }
}