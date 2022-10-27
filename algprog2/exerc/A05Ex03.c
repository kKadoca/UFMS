#include <stdio.h>

#define MAX 15

int i;

//função recursiva
int trocas_sucessivas_R (int n, int v[MAX]) {
    int aux;

    while (n > 0) {
        for (i = 0; i < n-1; i++) {
            if (v[i] > v[i+1]) {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
        return trocas_sucessivas_R (n-1 , v);  
    }
    
    return 1;
}

int main(void) {
    int n = 9;
    int v[MAX] = {10, 4, 89, 63, 23, 34, 60, 2, 47};

    if (trocas_sucessivas_R(n, v)) {
        printf("Ordenado!\n");
    }

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}

