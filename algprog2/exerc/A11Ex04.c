#include <stdio.h>
#define MAX 50

int main(void) {
    int c;
    char *p;
    char msg[MAX+1];

    // entrada
    p = msg;
    while ((c = getchar()) != '\n') {
        *p++ = (char)c;
    }
    *p = '.'; 

    // saida
    p = &msg[MAX];
    while (*p != '.') {
        p--;
    }
    p--;
    while (p >= msg) {
        putchar(*p);
        p--;
    }
    
    return 0;
}
