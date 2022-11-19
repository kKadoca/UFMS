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
void enfileira_enc_C(celula **f, double y, tipo_op o);
double desenfileira_enc_C(celula *i, celula **f, int t);
// funcoes de pilha
void empilha_enc_C(double y, celula *t);


int main() {
    int j, k = 1;
    //scanf("%d", &k);

    for (j = 0; j < k; j++) {
        char val[MAX+1];

        // inicializa-se uma fila com cabeça
        celula *i, *f;
        celula **ff = &f;
        i = (celula *) malloc(sizeof (celula));
        i->prox = NULL;
        f = i;

        // enfileira toda a linha de valores e operadores
        do {
            scanf("%s", &val);
            if (strlen(val) > 1) {
                // se for um valor numerico
                enfileira_enc_C(ff, atof(val), NUM);
                //printf("numero\n");
            } else {
                // se for um operador
                enfileira_enc_C(ff, val[0], val[0]);
                //printf("operador\n");
            }
            
        } while (val[0] != FIM);
        //printf("TUDO FOI ENFILEIRADO!\n");

        /*// percorre a fila imprimindo PARA TESTAR!!
        int w;
        do {
            w = desenfileira_enc_C(i, ff);
            printf("%d ", w);
        } while (w != INT_MIN);
        */

        // inicializa-se uma pilha com cabeça       
        celula *t;
        t = (celula *) malloc(sizeof (celula));
        t->prox = NULL;
        // inicializa-se variaveis para calculos
        int tipo;
        double n;
        
        n = desenfileira_enc_C(i, ff, tipo);
        while (tipo != FIM) {
            switch (tipo) {
            case NUM:
                empilha_enc_C(n, t);
                break;
            case ADD:
                /* code */
                break;
            case SUB:
                /* code */
                break;
            case MUL:
                /* code */
                break;
            case DIV:
                /* code */
                break;
            case EXP:
                /* code */
                break;
            case LOG:
                /* code */
                break;
            case FAT:
                /* code */
                break;
            case MOD:
                /* code */
                break;
            
            default:
                printf("Erro: tipo não definido");
                break;
            }
        }
        
        
    
    }
    return 0;
}

// funcoes de fila
void enfileira_enc_C(celula **f, double y, tipo_op o) {
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


double desenfileira_enc_C(celula *i, celula **f, int t) {
    double x;
    celula *p;
    x = INT_MIN;
    p = i->prox;
    t = p->tipo;
    
    if (p != NULL) {
        x = p->valor;
        i->prox = p->prox;
        free(p);
        if (i->prox == NULL) {
            *f = i;
        }
    } else {
        printf("FIM DA FILA!\n");
    }
    return x;
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
    double x;
    celula *p;

    if (t->prox != NULL) {
        p = t->prox;
        x = p->valor;
        t->prox = p->prox;
        free(p);
        return x;
    }
    else {
        printf("Pilha vazia!\n");
        return INT_MIN;
    }  
}

double soma_pilha_C_R(double n, celula *t){
    while (t->prox != NULL) {
        n = 0;
        return soma_pilha_C_R(t->valor, t); 
    }
    
        // return n + soma(n - 1);
}
