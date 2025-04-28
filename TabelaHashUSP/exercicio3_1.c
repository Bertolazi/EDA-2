#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da estrutura de célula da lista encadeada
typedef struct reg celula;
struct reg {
    int chave, ocorr;
    celula *prox;
};

// Ponteiro global para o início da lista encadeada
celula *tb;

// Função para contabilizar uma chave na lista encadeada
void contabiliza(int ch) {
    celula *p;
    p = tb;
    if (p != NULL) {
        // Procura a chave na lista
        while (p->chave != ch && p->prox != NULL) {
            p = p->prox;
        }
        if (p->chave == ch) {
            // Incrementa o contador de ocorrências
            p->ocorr++;
        } else {
            // Cria uma nova célula e insere no início da lista
            p = malloc(sizeof(celula));
            p->chave = ch;
            p->ocorr = 1;
            p->prox = tb;
            tb = p;
        }
    } else {
        // Cria a primeira célula da lista
        p = malloc(sizeof(celula));
        p->chave = ch;
        p->ocorr = 1;
        p->prox = NULL;
        tb = p;
    }
}

int main() {
    FILE *fp;
    char *filenames[] = {"teste10k.txt", "teste100k.txt", "teste1m.txt"};
    int i, ch, max_count = 0, max_ch = 0, distinct_keys = 0;

    for (i = 0; i < 3; i++) {
        clock_t start = clock();
        printf("Processando arquivo %s:\n", filenames[i]);

        // Inicializa a lista encadeada
        tb = NULL;

        // Ler o fluxo de entrada e contabilizar as chaves
        fp = fopen(filenames[i], "r");
        if (fp == NULL) {
            printf("Falha ao abrir o arquivo %s.\n", filenames[i]);
            return 1;
        }
        int N = 0;
        while (fscanf(fp, "%d", &ch) == 1) {
            contabiliza(ch);
            N++;
        }
        fclose(fp);

        // Encontrar a chave mais frequente
        celula *p = tb;
        while (p != NULL) {
            if (p->ocorr > max_count) {
                max_count = p->ocorr;
                max_ch = p->chave;
            }
            distinct_keys++;
            p = p->prox;
        }

        // Imprimir o relatório
        printf("Tamanho do fluxo de entrada (N): %d\n", N);
        printf("Número de chaves distintas: %d\n", distinct_keys);
        printf("Chave mais frequente: %d\n", max_ch);
        printf("Número de ocorrências da chave mais frequente: %d\n", max_count);

        clock_t end = clock();
        double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Tempo de execução: %.6f segundos\n\n", elapsed);

        // Libera a memória alocada para a lista encadeada
        p = tb;
        while (p != NULL) {
            celula *temp = p;
            p = p->prox;
            free(temp);
        }
    }

    return 0;
}
