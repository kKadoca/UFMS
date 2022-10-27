#include <stdio.h>

// é possível alterar o valor de MAX para testes
#define MAX 10

// funcao do exercicio
void preenche_matriz(int A[MAX][MAX]) {
    int cont = 0;
    int *p;

    p = A[0];
    *p++ = 1;
    while (p <= &A[MAX][MAX]) {
        if (cont == MAX) {
            *p++ = 1;
            cont = 0;
        } else {
            *p++ = 0;
            cont++;
        }
    }
}

int main(void) {
    int i, j;
    int matriz[MAX][MAX];

    preenche_matriz(matriz);

    // saida        
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
