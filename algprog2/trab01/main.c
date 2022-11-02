/**************************************************
*
* Carlos Eduardo Cavalheira Soares Terra de Oliveira - 2020.1907.009-7
* Trabalho 1
* Professor: Diego Padilha Rubert
*
*/
#include <stdio.h>
#include <string.h>
#define MAX 50

// estrutura de uma tarefa
typedef struct {
int hi;                     // hora de inicio
int mi;                     // minuto de inicio
int hf;                     // hora de fim
int mf;                     // minuto de fim
char nome[MAX+1];           // nome da tarefa
} tarefa;

// estrutura de uma capivara
typedef struct {
char nome[MAX+1];           // nome da capivara
int nt;                     // numero de tarefas
tarefa agenda[MAX];         // agenda com tarefas
} capivara;

// funcoes utilizadas
void mergesort(int p, int r, tarefa v[MAX]);
void intercala(int p, int q, int r, tarefa v[MAX]);

int corrigeAgenda(int n, tarefa v[MAX]);

int main(void) {
    int i, j, k, c;

    scanf("%d", &k);
    capivara capivaras[k];

    // lê uma capivara e suas infos
    for (i = 0; i < k; i++) {      
        scanf(" %[^\n]%*c", capivaras[i].nome);
        scanf("%d", &capivaras[i].nt);
        for (j = 0; j < capivaras[i].nt; j++) {
            scanf("%d:%d %d:%d\n", &capivaras[i].agenda[j].hi, &capivaras[i].agenda[j].mi, &capivaras[i].agenda[j].hf, &capivaras[i].agenda[j].mf);
            fgets(capivaras[i].agenda[j].nome, MAX+2, stdin);
        }
        printf("\n");
    }

    // ordena as tarefas de cada capivara
    for (i = 0; i < k; i++) {
        mergesort(0, capivaras[i].nt, capivaras[i].agenda);
    }
    
    // retira tarefas de conclusão impossível
    for (i = 0; i < k; i++) {
        capivaras[i].nt = corrigeAgenda(capivaras[i].nt, capivaras[i].agenda);
    }
    
    // imprime as tarefas
    for (i = 0; i < k; i++) {
        printf("\n%s\n", capivaras[i].nome);
        printf("%d\n", capivaras[i].nt);          
        for (j = 0; j < capivaras[i].nt; j++) {
            printf("%02d:%02d %02d:%02d %s", capivaras[i].agenda[j].hi, capivaras[i].agenda[j].mi, capivaras[i].agenda[j].hf, capivaras[i].agenda[j].mf, capivaras[i].agenda[j].nome);
        }   
    }
    printf("\n");
    return 0;
}


int corrigeAgenda(int n, tarefa v[MAX]) {
    int j;
    int d = 0, x = 0, z = 1; 
    tarefa w[MAX];                                      // agenda nova temporaria

    w[x] = v[x];                                        // recebe o primeiro sempre
    for (j = 0; j < n-1; j++) {                         // constroi agenda nova
        if (w[x].hf == v[z].hi) {
            if (w[x].mf <= v[z].mi) {
                x++;
                w[x] = v[z];
                z++;
            } else {
                z++;
                d++;
            }
        } else if (w[x].hf <= v[z].hi) {
            x++;
            w[x] = v[z];
            z++;
        } else {
            z++;
            d++;
        }
    }
    for (j = 0; j < n - d; j++) {                       // sobrescreve agenda antiga
        v[j] = w[j];                                  
    }

    return n-d;                                         // retorna nt atualizado
}

void intercala(int p, int q, int r, tarefa v[MAX]) {
    int x, y, z;
    tarefa w[MAX];
    
    x = p; y = q; z = 0;
    
    while (x < q && y < r) {                       // enquanto nenhuma metade acabar
        if (v[x].hf == v[y].hf) {                       // se hora final iguais
            if (v[x].mf == v[y].mf) {                   // e se minuto final iguais
                if (v[x].hi == v[y].hi) {               // e se hora inicial iguais
                    if (v[x].mi == v[y].mi) {           // e se minuto inicial iguais
                        if (strcmp(v[x].nome, v[y].nome) < 0) {     // ordena alfabeticamente
                            w[z] = v[x]; x++; 
                        } else {
                            w[z] = v[y]; y++;
                        }
                    } else if (v[x].mi < v[y].mi) {     // se minuto inicial diferentes
                        w[z] = v[x]; x++;                           
                    } else {
                        w[z] = v[y]; y++;
                    }
                } else if (v[x].hi < v[y].hi) {         // se hora inicial diferentes
                    w[z] = v[x]; x++;                           
                } else {
                    w[z] = v[y]; y++;
                }        
            } else if (v[x].mf < v[y].mf) {             // se minuto final diferentes
                w[z] = v[x]; x++;                           
            } else {
                w[z] = v[y]; y++;
            }           
        } else if (v[x].hf < v[y].hf) {                 // se hora final diferentes
            w[z] = v[x]; x++;                           
        } else {
            w[z] = v[y]; y++;                           
        } 
        z++;                                  
    }
    while (x < q) {                                     
        w[z] = v[x]; x++; z++;
    }
    while (y < r) {                                     
        w[z] = v[y]; y++; z++;
    }
    for (x = p; x < r; x++) {                           
        v[x] = w[x-p];                                  
    }
}

void mergesort(int p, int r, tarefa v[MAX]) {
    int q;

    if (p < r - 1) {
        q = (p + r) / 2;
    
        mergesort(p, q, v);
        mergesort(q, r, v);

        intercala(p, q, r, v);
    }
}
