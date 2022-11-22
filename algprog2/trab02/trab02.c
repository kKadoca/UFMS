/**************************************************
*
* Carlos Eduardo Cavalheira Soares Terra de Oliveira - 2020.1907.009-7
* Trabalho 2
* Professor: Diego Padilha Rubert
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX 14

// catalogando tipos de dados
typedef enum {
    NUM,       // 0
    ADD = '+', // 43 
    SUB = '-', // 45 
    MUL = '*', // 42 
    DIV = '/', // 47 
    EXP = '^', // 94 
    LOG = 'L', // 76 
    FAT = '!', // 33 
    MOD = '%', // 37 
    FIM = '@'  // 64 
} tipo_op;

// estrutura de uma celula
typedef struct cel {
    double valor;
    tipo_op tipo;
    struct cel *prox;
} celula;

// funcoes de fila
void enfileira_enc_C(celula **f, double y, int o);
void desenfileira_enc_C_R(celula *i, celula **f, celula *t);

// funcoes de pilha
void empilha_enc_C(double y, celula *t);
double desempilha_enc_C(celula *t);
double desempilhaCalculando_C(celula *t, int o);

// funcoes matematicas
int piso(double n);
double logbase2(double n);
double fatorial(int n);
double exponenciacao(double n1, double n2);


int main() {
    int j, k;
    scanf("%d", &k);

    for (j = 0; j < k; j++) {

        // inicializa-se uma fila com cabeça
        celula *i, *f;
        celula **ff = &f;
        i = (celula *) malloc(sizeof (celula));
        i->prox = NULL;
        f = i;

        // inicializa-se uma pilha com cabeça       
        celula *t;
        t = (celula *) malloc(sizeof (celula));
        t->prox = NULL;

        // enfileira toda a linha de valores e operadores
        char val[MAX+1];
        do {
            scanf("%s", &val);
            if (strlen(val) > 1) {
                // se for um valor numerico
                enfileira_enc_C(ff, atof(val), NUM);
            } else {
                // se for um operador
                enfileira_enc_C(ff, val[0], val[0]);
            }
            
        } while (val[0] != FIM);

        // desenfileira os valores  
        celula *q;
        q = i->prox;

        if (q != NULL) {
            while (q->tipo != FIM) {
                desenfileira_enc_C_R(i, ff, t);
                // se numero - empilha
                // se operador - calcula
                q = i->prox;   
            }
        }

        // imprime a pilha
        double w = 0;
        while (w != INT_MIN) {
            w = desempilha_enc_C(t);
            if (w != INT_MIN) {
                printf("%.2f\n", w);
            }
        }
    }
    return 0;
}

// funcoes de fila
void enfileira_enc_C(celula **f, double y, int o) {
    celula *nova;
    nova = (celula *) malloc(sizeof (celula));
    nova->valor = y;
    // atribui-se tipo a celula
    switch (o) {
    case NUM:
        nova->tipo = NUM;
        break;
    case ADD:
        nova->tipo = ADD;
        break;
    case SUB:
        nova->tipo = SUB;
        break;
    case MUL:
        nova->tipo = MUL;
        break;
    case DIV:
        nova->tipo = DIV;
        break;
    case EXP:
        nova->tipo = EXP;
        break;
    case LOG:
        nova->tipo = LOG;
        break;
    case FAT:
        nova->tipo = FAT;
        break;
    case MOD:
        nova->tipo = MOD;
        break;
    default:
        nova->tipo = FIM;
        break;
    }
    nova->prox = NULL;
    (*f)->prox = nova;
    *f = nova;
}

void desenfileira_enc_C_R(celula *i, celula **f, celula *t) {
    double x, n;
    int o;
    celula *p;
    p = i->prox;
    o = p->tipo;

    if (p != NULL) {
        if (o == NUM) {
            x = p->valor;
            empilha_enc_C(x, t);
        } else {
            n = desempilhaCalculando_C(t, o);
            empilha_enc_C(n, t);
        }
        
        i->prox = p->prox;
        free(p);
        if (i->prox == NULL) {
            *f = i;
        }
    }
}

// funcoes de pilha
void empilha_enc_C(double y, celula *t) {
    celula *nova;
    nova = (celula *) malloc(sizeof (celula));
    nova->valor = y;
    nova->prox = t->prox;
    t->prox = nova;
}

double desempilha_enc_C(celula *t) {
    double z;
    celula *p;
    
    if (t->prox != NULL) {
        p = t->prox;
        z = p->valor;
        t->prox = p->prox;
        free(p);
        return z;
    }
    else {
        return INT_MIN;
    }
}

double desempilhaCalculando_C(celula *t, int o){
    double res, n1, n2;

    switch (o) {
    case ADD:
        /* soma */
        n1 = desempilha_enc_C(t);
        n2 = desempilha_enc_C(t);
        res = n2 + n1;
        break;
    case SUB:
        /* subtracao */
        n1 = desempilha_enc_C(t);
        n2 = desempilha_enc_C(t);
        res = n2 - n1;
        break;
    case MUL:
        /* multiplicacao */
        n1 = desempilha_enc_C(t);
        n2 = desempilha_enc_C(t);
        res = n2 * n1;
        break;
    case DIV:
        /* divisao */
        n1 = desempilha_enc_C(t);
        n2 = desempilha_enc_C(t);
        res = n2 / n1;
        break;
    case EXP:
        /* exponenciacao inteira */
        n1 = desempilha_enc_C(t);
        n2 = desempilha_enc_C(t);
        res = exponenciacao(n2, n1);
        break;
    case LOG:
        /* piso do log2 */
        n1 = desempilha_enc_C(t);
        res = piso(logbase2(n1));
        break;
    case FAT:
        /* fatorial do piso */
        n1 = desempilha_enc_C(t);
        res = fatorial(piso(n1));
        break;
    case MOD:
        /* modulo do piso */
        n1 = desempilha_enc_C(t);
        n2 = desempilha_enc_C(t);
        res = piso(n2) % piso(n1);
        break;
    default:
        break;
    }

    return res;
}

// funcoes matematicas
int piso(double n) {
  if (n >= 0)
    return (int) n;
  else
    return (int)(n + ((int)(-n)+1)) - ((int)(-n)+1);
}

double exponenciacao(double n1, double exp) {
    double r = n1;

    if (exp == 0) {    // expoente 0
        return 1;
    }
    if (exp > 0) {    // expoente positivo
        for (int i = 2; i <= exp ; i++) {
            r *= n1;
        }
    } else {        // expoente negativo
        for (int i = -2; i >= exp; i--) {
            r *= n1;
        }
        r = 1 / r;
    }

    return r;
}

double logbase2(double n) {
    int r = 0;

    while (n > 1) {
        n /= 2;
        r += 1;
    }
    return r; 
}

double fatorial(int n) {
    int exp = n - 1;

    if (n != 0) {
        for (int i = exp; i > 1; i--) {
            n *= exp;
            exp--;
        }
    }

    return n;
}


