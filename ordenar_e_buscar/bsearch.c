#include <stdio.h>

int bsearch (int x, int v[], int n){
    int p = 0;
    int u = n - 1;
    int t = 0;

    while (p < u) {
        int m = (u + p) / 2;
        
        if (x == v[m]) return 1;
        if (x < v[m])
            u = m - 1;
        else 
            p = m + 1; 
        t++; 
        printf ("%d\n", t); 
    }
    
    return 0;
}


int main (void) {
    int v[11] = {16,28,32,47,59,64,71,83,90,95};

    printf ("71: %d\n", bsearch(71, v, 11));
    // printf ("51: %d\n", bsearch(51, v, 8));

    return 0;
}