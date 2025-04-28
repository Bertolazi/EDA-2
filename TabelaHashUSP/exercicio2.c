#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void contabiliza(int *tb, int R, int ch) {
   if (ch >= 0 && ch < R) {
       tb[ch]++;
   }
}

int main() {
    FILE *fp;
    char *filenames[] = {"teste10k.txt", "teste100k.txt", "teste1m.txt"};
    int i, ch, max_count = 0, max_ch = 0, distinct_keys = 0;

    for (i = 0; i < 3; i++) {
        clock_t start = clock();
        printf("Processando arquivo %s:\n", filenames[i]);

        // Determinar o tamanho do universo R
        int R = 10000;
        int *tb = calloc(R, sizeof(int));
        if (tb == NULL) {
            printf("Falha ao alocar memória para a tabela de hash.\n");
            return 1;
        }

        // Ler o fluxo de entrada e contabilizar as chaves
        fp = fopen(filenames[i], "r");
        if (fp == NULL) {
            printf("Falha ao abrir o arquivo %s.\n", filenames[i]);
            free(tb);
            return 1;
        }
        int N = 0;
        while (fscanf(fp, "%d", &ch) == 1) {
            if (ch < 0 || ch >= R) {
                printf("Chave inválida lida do arquivo: %d\n", ch);
                continue;
            }
            contabiliza(tb, R, ch);
            N++;
            if (tb[ch] == 1) {
                distinct_keys++;
            }
        }
        fclose(fp);

        // Encontrar a chave mais frequente
        max_count = 0;
        max_ch = 0;
        for (int j = 0; j < R; j++) {
            if (tb[j] > max_count) {
                max_count = tb[j];
                max_ch = j;
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

        free(tb);
    }

    return 0;
}
