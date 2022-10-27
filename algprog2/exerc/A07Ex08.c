#include <stdio.h>

#define MAX 15

void troca (int *a, int *b) {
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

int separa (int p, int r, int v[MAX]) {
    int x, i, j;

    x = v[p];
    i = p - 1;
    j = r + 1;

    while (i < j) {
        do {
            j--;
        } while (v[j] < x);    //ordenar crescente
        //} while (v[j] > x);  //ordenar decrescente
        do {
            i++;
        } while (v[i] > x);    //ordenar crescente
        //} while (v[i] < x);  //ordenar decrescente
        if (i < j) {
            troca(&v[i], &v[j]);
        }
    }

    return j;
}

void quicksort (int p, int r, int v[MAX]) {
    int q;

    if (p < r) {
        q = separa(p, r, v);
        quicksort(p, q, v);
        quicksort(q+1, r, v);
    }
}

int main(void) {
    int i, n = 13;
    int v[] = {54,32,49,75,23,72,93,41,10,7,64,88,12};

    quicksort(0, n-1, v);

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    
    return 0;
}
