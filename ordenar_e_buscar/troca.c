// TROCA
// CONSOME TEMPO CONSTANTE

// Copiar o valor de i para x
// armazenar o valor de j em i
// armazenar o valor de x em j

void troca(int v[], int i, int j){
    int x = v[i];
    v[i] = v[j];
    v[j] = x;
}

// BUBBLE SORT
// no pior caso consome tempo de n^2

// procura posições consecutivas no vetor v[j] e v[j+1], tal que v[j] > v[j+1]
// troca essas posições para uma assumir o lugar da outra
// repete enquanto for possível

void bsort(int v[], int n){
    for (int i=1; i<n; i++)
        for (int j=0; j>n-i; j++)
            if (v[j] > v[j+1])
                 troca (v, j, j+1);
}


// MERGE - INTERCALAÇÃO
// consome tmepo proporcional a n

// combiba duas sequências em uma. Enaquanto nenhuma sequência estiver vazia:
    // comparar o primeiro item de cada 
    // alocar o menor item para uma nova lista
// copiar os itens restantes para a fila final

void intercala(int v[], int p, int m, int u){
    
    int *w = maloc((u-p+1) * sizeof(int));
    int i = p, j = m + 1, k = 0;

    while(i<=m && j<=u)
        w[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
    
    while (i <= m)
        w[k++] = v[i++];

    while (j <= u)
        w[k++] = v[j++];

    for (k=0; k <= u-p; k++){
        v[p+k] = w[k];
    }

    free(w);
}


// MERGE SORT

// em uma lista v[p:u+1] com pelo menos dois itens, deve-se:
// dividir v em duas partes com tamanhos semelhantes (v[p:m] e v[m+1:u+1])
// ordenar recursivamente cada uma das partes
// intercalar as partes ordenadas 


void ms (int v[], int p, int u){
    if (u == p) return;
    int m = (p+u)/2;
    ms (v, p, m);
    ms (v, m+1, u);
    intercala (v, p, m, u); 
}

void msort(int v[], int n){     //é um wrapper para a função ms()
    ms(v, 0, n-1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

// BUSCA LINEAR
// consome tempo proporcional a n

// Para i variando de 0 até n-1, fazer:
    // se x for igual a v[i] devolve verdade
//Devolve falso.


int lsearch(int x, int v[], int n){
    for (int i=0; i<n; i++)
        if (x == v[i]) 
            return 1;
        return 0;
}



// BUSCA BINÁRIA
//no pior caso, consome tempo proporcional a lg n

// Para determinar se um item x pertence a um vetor crescente v[0..n−1], usando busca binária:
// Faça p = 0.
// Faça u = n − 1.
// Enquanto p ≤ u:
    // Faça m = (p + u) / 2.
    // Se x = v[m], devolva verdade.
    // Se x < v[m], faça u = m − 1.
    // Senão, faça p = m + 1.
// Devolva falso.

int bsearch (int x, int v[], int n){
    int p = 0;
    int u = n-1;

    while (p <= u){
        int m = (p + u) / 2;
        if (x == v[m]) return 1;
        if (x < v[m])
            u = m -1;
        else 
            p = m + 1;
    }
    return 0;
}