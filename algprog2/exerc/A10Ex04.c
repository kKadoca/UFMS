#include <stdio.h>
#define MAX 25

int *maximo(int n, int v[MAX]) {
    int i;          // contador
    int aux = 0;    // controle de valor
    int *maior;     // controle de endereço

    for (i = 0; i < n; i++) {
        if (v[i] > aux) {
            aux = v[i];         
            maior = &v[i];
        } 
    }
    
    return maior;   // retorna o endereço
}

int main(void) {
    int j, n = MAX;
    int vetor[MAX+1];

    for (j = 0; j < n; j++) {
        scanf("%d", &vetor[j]);
    }
    
    printf("%d\n", maximo(n, vetor));   // printa o endereço
    printf("%d", *maximo(n, vetor));    // printa o valor no endereço

    return 0;
}