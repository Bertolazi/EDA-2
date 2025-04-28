#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da estrutura de célula
typedef struct reg {
    int chave, ocorr;
} celula;

// Vetor de células
celula *tb;
int tb_size = 0, distinct_keys = 0;

// Função para redimensionar o vetor
void resize_tb() {
    tb_size *= 2;
    tb = realloc(tb, tb_size * sizeof(celula));
}

// Função para contabilizar uma chave no vetor
void contabiliza(int ch) {
    // Procura a chave no vetor
    for (int i = 0; i < distinct_keys; i++) {
        if (tb[i].chave == ch) {
            tb[i].ocorr++;
            return;
        }
    }

    // Chave não encontrada, insere uma nova célula no final
    if (distinct_keys == tb_size) {
        resize_tb();
    }
    tb[distinct_keys].chave = ch;
    tb[distinct_keys].ocorr = 1;
    distinct_keys++;
}

int main() {
    FILE *fp;
    char *filenames[] = {"teste10k.txt", "teste100k.txt", "teste1m.txt"};
    int i, ch, max_count = 0, max_ch = 0;

    for (i = 0; i < 3; i++) {
        clock_t start = clock();
        printf("Processando arquivo %s:\n", filenames[i]);

        // Inicializa o vetor de células
        tb_size = 1024;
        tb = malloc(tb_size * sizeof(celula));
        distinct_keys = 0;

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
        for (int j = 0; j < distinct_keys; j++) {
            if (tb[j].ocorr > max_count) {
                max_count = tb[j].ocorr;
                max_ch = tb[j].chave;
            }
        }

        // Imprimir o relatório
        printf("Tamanho do fluxo de entrada (N): %d\n", N);
        printf("Número de chaves distintas: %d\n", distinct_keys);
        printf("Chave mais frequente: %d\n", max_ch);
        printf("Número de ocorrências da chave mais frequente: %d\n", max_count);

        clock_t end = clock();
        double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Tempo de execução: %.6f segundos\n\n", elapsed);

        // Libera a memória alocada para o vetor
        free(tb);
    }

    return 0;
}
