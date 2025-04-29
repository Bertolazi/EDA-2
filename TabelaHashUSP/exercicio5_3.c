#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da estrutura de célula da lista encadeada
typedef struct reg celula;
struct reg {
    int chave;
    int ocorr;
    celula *prox;
};

// Ponteiro global para a tabela de dispersão
celula **tb;
int M = 200003; // Tamanho da tabela de dispersão

// Função de hash
int hash(int ch) {
    return ch % M; // Função de hash simples
}

// Função para contabilizar uma chave na tabela de dispersão
void contabiliza(int ch) {
    int h = hash(ch); // Calcula o índice da tabela
    celula *p = tb[h];

    // Busca pela chave na lista encadeada
    while (p != NULL && p->chave != ch) {
        p = p->prox;
    }

    // Se a chave já existe, incrementa a contagem
    if (p != NULL) {
        p->ocorr += 1; // Incrementa o contador de ocorrências
    } else {
        // Caso contrário, cria uma nova célula
        p = malloc(sizeof(celula));
        p->chave = ch;
        p->ocorr = 1;
        p->prox = tb[h]; // Insere no início da lista
        tb[h] = p; // Atualiza o ponteiro da tabela
    }
}

// Função para calcular desempenho e imprimir resultados
void calculaDesempenho() {
    int total = 0;
    int distinct_keys = 0;
    int max_count = 0, max_ch = 0;

    for (int i = 0; i < M; i++) {
        celula *p = tb[i];
        while (p != NULL) {
            total += p->ocorr; // Total de ocorrências
            distinct_keys++; // Contagem de chaves distintas
            if (p->ocorr > max_count) {
                max_count = p->ocorr;
                max_ch = p->chave; // Chave mais frequente
            }
            p = p->prox;
        }
    }

    // Imprimir relatório
    printf("Tamanho do fluxo de entrada (N): %d\n", total);
    printf("Número de chaves distintas: %d\n", distinct_keys);
    printf("Chave mais frequente: %d\n", max_ch);
    printf("Número de ocorrências da chave mais frequente: %d\n", max_count);
}

int main() {
    FILE *fp;
    char *filenames[] = {"teste1m.txt"};
    int ch;

    // Aloca a tabela de dispersão
    tb = malloc(M * sizeof(celula *));
    for (int j = 0; j < M; j++) {
        tb[j] = NULL; // Inicializa a tabela com NULL
    }

    printf("Processando arquivo %s:\n", filenames[0]);

    clock_t start = clock();

    // Ler o fluxo de entrada e contabilizar as chaves
    fp = fopen(filenames[0], "r");
    if (fp == NULL) {
        printf("Falha ao abrir o arquivo %s.\n", filenames[0]);
        return 1;
    }

    while (fscanf(fp, "%d", &ch) == 1) {
        contabiliza(ch); // Chama a função para cada chave
    }
    fclose(fp);

    // Calcula e imprime o desempenho
    calculaDesempenho();

    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.6f segundos\n\n", elapsed);

    // Libera a memória alocada para a tabela
    for (int j = 0; j < M; j++) {
        celula *p = tb[j];
        while (p != NULL) {
            celula *temp = p;
            p = p->prox;
            free(temp);
        }
    }
    free(tb); // Libera a tabela

    return 0;
}

/*
Tamanho do fluxo de entrada (N): 1000000
Número de chaves distintas: 26396
Chave mais frequente: 6777
Número de ocorrências da chave mais frequente: 151
Tempo de execução: 0.047210 segundo
*/