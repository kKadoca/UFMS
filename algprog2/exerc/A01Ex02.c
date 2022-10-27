#include<stdio.h>

int maior, menor;

typedef struct {
    int hh;
    int mm;
    int ss;
} horario;

int main(void) {
    // Cria registro
    horario horarios[3];

    // Lê dois valores de horario e armazena
    for (int i = 0; i < 2; i++) {
        scanf("%d:%d:%d", &horarios[i].hh, &horarios[i].mm, &horarios[i].ss);
    }

    // Verifica qual horário é maior
    if (horarios[0].hh == horarios[1].hh) {
        if (horarios[0].mm == horarios [1].mm) {
            if (horarios[0].ss > horarios[1].ss) {
                maior = 0;
                menor = 1;
            }
            else {
                maior = 1;
                menor = 0;
            }
        }
        if (horarios[0].mm > horarios[1].mm) {
            maior = 0;
            menor = 1;
        }
        else {
            maior = 1;
            menor = 0;
        }
    }
    if (horarios[0].hh > horarios[1].hh) {
        maior = 0;
        menor = 1;
    }
    else {
        maior = 1;
        menor = 0;
    }

    // Calcula e imprime horário final
    horarios[2].ss = horarios[maior].ss - horarios[menor].ss;
    horarios[2].mm = horarios[maior].mm - horarios[menor].mm;
    horarios[2].hh = horarios[maior].hh - horarios[menor].hh;  

    if (horarios[2].ss < 0) {
        horarios[2].ss += 60;
        horarios[2].mm -= 1;
    }
    if (horarios[2].mm < 0) {
        horarios[2].mm += 60;
        horarios[2].hh -= 1;
    }

    printf("%d:%d:%d", horarios[2].hh, horarios[2].mm, horarios[2].ss);
}