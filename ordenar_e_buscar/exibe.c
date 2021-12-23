#include <stdio.h>

void troca(int v[], int i, int j){
    int x = v[i];
    v[i] = v[j];
    v[j] = x;
}


void bsort(int v[], int n){
    for (int i=1; i<n; i++)
        for (int j=0; j<n-i; j++)
            if (v[j] > v[j+1])
                troca(v, j, j+1);
}

int exibe(int v[], int m){
    for (int i=0; i<=m; i++)
        v[i] = bsort(v, m);
    
    return printf("%d\n", v);  
}

int main(void){
    int v[10] = {83, 31, 91, 46, 27, 20, 96, 25, 96, 80};

    bsort(v, 10);
    exibe(v, 10);

    return 0;
}