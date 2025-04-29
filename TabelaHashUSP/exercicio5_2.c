#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int chave;
    int ocorr;
    struct reg *prox;
} celula;

celula **tb;
int M = 5003; // Tamanho da tabela de dispersão

int hash(int ch) {
    return ch % M; // Função de hash
}

void contabiliza(int ch) {
    int h = hash(ch);
    celula *p = tb[h];
    
    while (p != NULL && p->chave != ch)
        p = p->prox;

    if (p != NULL) {
        p->ocorr += 1; // Incrementa a contagem
    } else {
        p = malloc(sizeof(celula));
        p->chave = ch;
        p->ocorr = 1;
        p->prox = tb[h];
        tb[h] = p; // Insere na lista encadeada
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
        tb[i] = NULL; // Inicializa a tabela com NULL
    }

    // Simulação de leitura de N chaves (aqui você pode gerar ou ler chaves)
    for (int i = 0; i < 50000; i++) {
        int chave = rand() % 10000; // Gera chaves aleatórias
        contabiliza(chave); // Chama a função para cada chave
    }

    imprimeTabela(); // Imprime o estado final da tabela

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
