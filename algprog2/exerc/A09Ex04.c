/* 
Nesse algoritmo, são atribuidos valores à duas variáveis, int a e int b,
os quais são trocados com a utilização de uma variável ponteiro(dispensável),
também utilizando-se de uma variável auxiliar, int c.
*/
#include <stdio.h>

int main(void) {
    int a, b, c, *ptr;
    a = 3;
    b = 7;

    printf("a=%d, b=%d\n", a, b); // mostra valores de a e b

    ptr = &a;   // ponteiro recebe endereço de a
    c = *ptr;   // c recebe conteudo do ponteiro(valor de a)
    ptr = &b;   // ponteiro recebe endereço de b
    a = *ptr;   // a recebe conteudo do ponteiro(valor de b)
    ptr = &c;   // ponteiro recebe endereço de c(antigo a)
    b = *ptr;   // b recebe conteudo do ponteiro(valor de c(antigo a))

    printf("a=%d, b=%d\n", a, b); // mostra os novos valores de a e b

    return 0;
}
