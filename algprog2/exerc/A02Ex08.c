#include <stdio.h>

int n;
int comprimento = 1;

// Funcao nao recursiva
int ciclo(int n) {
    printf("%d ", n);
    while (n > 1) {
        if (n%2 == 1) {
            n = n*3 + 1;
        } 
        else {
            n = n/2;
        }
        printf("%d ", n);
        comprimento += 1;
    }
    printf("\n%d", comprimento);
}

// Funcao recursiva
int cicloR(int n) {
    printf("%d ", n);
    if (n == 1) {
        return comprimento;
    }
    if (n%2 == 1) {
        n = n*3 + 1;
        comprimento += 1;
        cicloR(n);
    } 
    else {
        n = n/2;
        comprimento += 1;
        cicloR(n);
    }
}

int main(void) {
    scanf("%d", &n);
    
    printf("\n%d", cicloR(n));

    return 0;
}