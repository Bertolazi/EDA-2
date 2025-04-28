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

// Função para contabilizar uma chave no vetor (ordenado)
void contabiliza_ordenado(int ch) {
    // Procura a posição correta para inserir a nova célula
    int i;
    for (i = 0; i < distinct_keys; i++) {
        if (tb[i].chave >= ch) {
            break;
        }
    }

    // Verifica se a chave já existe no vetor
    if (i < distinct_keys && tb[i].chave == ch) {
        tb[i].ocorr++;
        return;
    }

    // Insere a nova célula na posição correta
    if (distinct_keys == tb_size) {
        resize_tb();
    }
    for (int j = distinct_keys; j > i; j--) {
        tb[j] = tb[j - 1];
    }
    tb[i].chave = ch;
    tb[i].ocorr = 1;
    distinct_keys++;
}

// Função para contabilizar uma chave no vetor (sem ordenação)
void contabiliza_desord(int ch) {
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
        // Teste com vetor ordenado
        clock_t start_ordenado = clock();
        printf("Processando arquivo %s (vetor ordenado):\n", filenames[i]);
        tb_size = 1024;
        tb = malloc(tb_size * sizeof(celula));
        distinct_keys = 0;
        fp = fopen(filenames[i], "r");
        if (fp == NULL) {
            printf("Falha ao abrir o arquivo %s.\n", filenames[i]);
            return 1;
        }
        int N = 0;
        while (fscanf(fp, "%d", &ch) == 1) {
            contabiliza_ordenado(ch);
            N++;
        }
        fclose(fp);
        for (int j = 0; j < distinct_keys; j++) {
            if (tb[j].ocorr > max_count) {
                max_count = tb[j].ocorr;
                max_ch = tb[j].chave;
            }
        }
        printf("Tamanho do fluxo de entrada (N): %d\n", N);
        printf("Número de chaves distintas: %d\n", distinct_keys);
        printf("Chave mais frequente: %d\n", max_ch);
        printf("Número de ocorrências da chave mais frequente: %d\n", max_count);
        clock_t end_ordenado = clock();
        double elapsed_ordenado = (double)(end_ordenado - start_ordenado) / CLOCKS_PER_SEC;
        printf("Tempo de execução (vetor ordenado): %.6f segundos\n\n", elapsed_ordenado);
        free(tb);

        // Teste com vetor não ordenado
        clock_t start_desord = clock();
        printf("Processando arquivo %s (vetor não ordenado):\n", filenames[i]);
        tb_size = 1024;
        tb = malloc(tb_size * sizeof(celula));
        distinct_keys = 0;
        fp = fopen(filenames[i], "r");
        if (fp == NULL) {
            printf("Falha ao abrir o arquivo %s.\n", filenames[i]);
            return 1;
        }
        N = 0;
        while (fscanf(fp, "%d", &ch) == 1) {
            contabiliza_desord(ch);
            N++;
        }
        fclose(fp);
        max_count = 0;
        max_ch = 0;
        for (int j = 0; j < distinct_keys; j++) {
            if (tb[j].ocorr > max_count) {
                max_count = tb[j].ocorr;
                max_ch = tb[j].chave;
            }
        }
        printf("Tamanho do fluxo de entrada (N): %d\n", N);
        printf("Número de chaves distintas: %d\n", distinct_keys);
        printf("Chave mais frequente: %d\n", max_ch);
        printf("Número de ocorrências da chave mais frequente: %d\n", max_count);
        clock_t end_desord = clock();
        double elapsed_desord = (double)(end_desord - start_desord) / CLOCKS_PER_SEC;
        printf("Tempo de execução (vetor não ordenado): %.6f segundos\n\n", elapsed_desord);
        free(tb);
    }

    return 0;
}
