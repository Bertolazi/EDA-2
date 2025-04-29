#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int chave;
    int ocorr;
    struct reg *prox;
} celula;

celula **tb;
int M = 13;

int hash(int ch) {
    return ch % M;
}

void contabiliza(int ch) {
    int h = hash(ch);
    celula *p = tb[h];
    
    while (p != NULL && p->chave != ch)
        p = p->prox;

    if (p != NULL) {
        p->ocorr += 1;
    } else {
        p = malloc(sizeof(celula));
        p->chave = ch;
        p->ocorr = 1;
        p->prox = tb[h];
        tb[h] = p;
    }
}

void imprimeTabela() {
    for (int i = 0; i < M; i++) {
        printf("tb[%d]: ", i);
        celula *p = tb[i];
        while (p != NULL) {
            printf("(%d, %d) -> ", p->chave, p->ocorr);
            p = p->prox;
        }
        printf("NULL\n");
    }
}

int main() {
    tb = malloc(M * sizeof(celula *));
    for (int i = 0; i < M; i++) {
        tb[i] = NULL;
    }

    int chaves[] = {17, 21, 19, 4, 26, 30, 37};
    int n = sizeof(chaves) / sizeof(chaves[0]);

    for (int i = 0; i < n; i++) {
        contabiliza(chaves[i]);
    }

    imprimeTabela();

    // Liberação de memória
    for (int i = 0; i < M; i++) {
        celula *p = tb[i];
        while (p != NULL) {
            celula *temp = p;
            p = p->prox;
            free(temp);
        }
    }
    free(tb);
    
    return 0;
}
