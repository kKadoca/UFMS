#include <stdio.h>

#define MAX 15

void intercala(int p, int q, int r, int v[MAX]) {
    int i, j, k, w[MAX];
    
    i = p; j = q; k = 0;
    
    while (i < q && j < r) {
        if (v[i] <= v[j]) {   //ordenar crescente
        //if (v[i] >= v[j]) { //ordenar decrescente
            w[k] = v[i]; i++; 
        }
        else {
            w[k] = v[j]; j++;\
        }
        k++;
    }
    while (i < q) {
        w[k] = v[i]; i++; k++;
    }
    while (j < r) {
        w[k] = v[j]; j++; k++;
    }
    for (i = p; i < r; i++) {
        v[i] = w[i-p];
    }
}

void mergesort(int p, int r, int v[MAX]) {
    int q;

    if (p < r - 1) {
        q = (p + r) / 2;
    
        mergesort(p, q, v);
        mergesort(q, r, v);

        intercala(p, q, r, v);
    }
}

int main(void) {
    int i, n = 13;
    int v[] = {54,32,49,75,23,72,93,41,10,7,64,88,12};

    mergesort(0, n, v);

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    
    return 0;
}
