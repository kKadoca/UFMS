#include <stdio.h>

#define MAX 15

int v[MAX] = {10,2,3,9,21,43,28,40,47,50};
int i;

//função não-recursiva
int insere (int n, int v[MAX], int k, int y) {

    for (i = n; i > k; i--) {
        v[i] = v[i-1];
    }


    return n+1;
}

//função recursiva
int insere_R (int n, int v[MAX], int k, int y) {

    if (k <= n) {
        int aux = v[k];
        v[k] = y;
        y = aux;
        return (insere_R(n, v, k+1, y));
    }

    return n+1;    
}

int main() {
    int n = 10;
    int k, y;

    scanf("%d %d", &k, &y);

    printf("novo n = %d\n", insere_R(n, v, k, y));

    printf("novo v = ");
    for (i = 0; i < n+1; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}



