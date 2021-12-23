//Lista na qual os itens são inseridos em forma crescente
//cada novo item inserido, entra na posição correta
//nenhum item precisa ser movido da memória pra manter a ordem
//útil para guardar coleções dinâmicas nas quais a ordem importa


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

//inserção de itens (permite repetição):
void ins(Item x, Lista *L) {
   while( *L != NULL && (*L)->item < x ) 
      L = &(*L)->prox;
   *L = no(x,*L);
}

//remoção de itens:
void rem(Item x, Lista *L) {
   while( *L != NULL && (*L)->item < x ) 
      L = &(*L)->prox;
   if( *L == NULL || (*L)->item > x ) return;
   Lista n = *L;
   *L = n->prox;
   free(n);
}


//pertinência de um item:
int pert(Item x, Lista L) {
   while( L != NULL && L->item < x ) 
      L = L->prox;
   return (L != NULL && L->item == x);
}   