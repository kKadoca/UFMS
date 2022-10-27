#include <stdio.h>
// estava dando erro com o nome da função sendo "remove",
// então alterei para "remover".

#define MAX 15

int v[MAX] = {10,2,3,9,21,43,28,40,72,32,7,50,26,47,50};
int i;

//função não-recursiva
int remover (int n, int v[MAX], int k) {

    for (i = 0; i < n; i++) {
        if (i >= k) {
            v[i] = v[i+1];
        }
    }

    return n-1;
}

// função recursiva
int remover_R (int n, int v[MAX], int k) {

    if (k < n-1) {
        v[k] = v[k+1];
        return remover_R(n, v, k+1);    
    }
    
    return n-1;
}

int main() {
    
    int n = MAX; 
    int k;

    scanf("%d", &k);

    printf("novo n = %d\n", remover(n, v, k));

    printf("novo v = ");
    for (i = 0; i < n-1; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}




