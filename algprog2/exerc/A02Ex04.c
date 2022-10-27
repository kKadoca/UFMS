#include <stdio.h>
#define MAX 15

int n, i;
float v[MAX];

float soma(int n, float v[MAX]) {
    if (n <= 1) {
	    return v[0];
    }
    else {
	    return soma(n-1, v) + v[n-1];
    }
}

int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%f", &v[i]);    
    }
    printf("%.1f", soma(n, v));
}
    
