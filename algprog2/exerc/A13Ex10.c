#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int i;
    int soma = 0;

    for (i = 1; i < argc; i++) {
        soma += atoi(argv[i]);
    }
    
    printf("soma = %d", soma);

    return 0;
}

