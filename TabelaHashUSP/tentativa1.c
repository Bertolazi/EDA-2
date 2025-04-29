#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 200003 // Tamanho da tabela de dispersão

// Estrutura para armazenar a chave e o número de ocorrências
typedef struct {
    int chave;  // Chave armazenada
    int ocorr;  // Número de ocorrências
} celula;

// Ponteiro global para a tabela de dispersão
celula *tb;

// Função de hash
int hash(int ch) {
    return ch % M; // Função de hash simples
}

// Função para contabilizar uma chave na tabela de dispersão
void contabiliza(int ch) {
    int h = hash(ch); // Calcula o índice inicial
    int i = 0; // Contador para sondagem linear

    // Sondagem linear para encontrar uma posição livre ou a chave existente
    while (i < M) {
        int index = (h + i) % M; // Calcula o índice com sondagem linear

        // Se a célula está vazia, inserimos a nova chave
        if (tb[index].chave == -1) {
            tb[index].chave = ch;
            tb[index].ocorr = 1;
            return;
        }

        // Se a célula contém a chave, incrementamos a contagem
        if (tb[index].chave == ch) {
            tb[index].ocorr += 1;
            return;
        }

        i++; // Incrementa o contador para a próxima posição
    }

    // Se chegamos aqui, a tabela está cheia
    printf("Tabela cheia, não foi possível inserir a chave %d.\n", ch);
}

void calculaDesempenho() {
    int total = 0;
    int distinct_keys = 0;
    int max_count = 0, max_ch = 0;

    for (int i = 0; i < M; i++) {
        if (tb[i].chave != -1) { // Verifica se a célula está ocupada
            total += tb[i].ocorr; // Total de ocorrências
            distinct_keys++; // Contagem de chaves distintas
            if (tb[i].ocorr > max_count) {
                max_count = tb[i].ocorr;
                max_ch = tb[i].chave; // Chave mais frequente
            }
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
    tb = malloc(M * sizeof(celula));
    for (int j = 0; j < M; j++) {
        tb[j].chave = -1; // Inicializa a tabela com -1 (vaga)
        tb[j].ocorr = 0;  // Inicializa as ocorrências como 0
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
    free(tb); // Libera a tabela

    return 0;
}
