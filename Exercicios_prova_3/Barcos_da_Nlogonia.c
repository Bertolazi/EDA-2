/*
Como todos sabem, a Nlogônia é um arquipélago que mantém a tradição milenar de não permitir a construção de pontes. Assim, o transporte público entre as ilhas se dá por meio de barcos.

Para cada par de ilhas há no máximo um barco que faz o transporte de ida e volta entre as duas ilhas; ou seja, pode não haver transporte direto entre um determinado par de ilhas. No entanto, é possível ir de qualquer ilha para qualquer outra ilha utilizando apenas os barcos de transporte público (note que pode ser preciso passar por outras ilhas no trajeto).

Os barcos de transporte público da Nlogônia não são todos iguais: cada barco tem um limite máximo de passageiros que ele pode carregar.

Cada ilha tem um time de basquete, com um grupo de fãs. Todos os fãs de um time são moradores da mesma ilha do time para o qual torcem. Nos dias de jogo, o grupo de fãs do time visitante sempre planeja viajar usando apenas barcos de transporte público, todos juntos, para a ilha onde acontecerá o jogo (ou seja, todos os membros do grupo juntos, durante todo o trajeto). Mas os fãs sabem que isso talvez não seja possível devido ao limite de passageiros dos barcos de transporte público. Você poderia ajudá-los?

Dados a lista dos barcos existentes, com os respectivos limites de passageiros, e uma série de consultas, cada uma com a ilha de início do trajeto e a ilha onde ocorrerá o jogo, sua tarefa é determinar, para cada consulta da entrada, qual o maior número de torcedores que o grupo pode ter para poder viajar junto.

## Entrada

A primeira linha contém dois inteiros N e B, indicando, respectivamente, o número de ilhas da Nlogônia e o número de barcos de transporte público que ligam as ilhas. As ilhas nlogonianas são identificadas por números de 1 a N.

Cada uma das B linhas seguintes descreve o trajeto de um barco de transporte público e contém três inteiros I, J e P, onde I e J indicam as duas ilhas ligadas por esse barco e P indica o limite de passageiros do barco. Note que o barco pode fazer o transporte tanto de I para J quanto de J para I.

A linha seguinte contém um inteiro C que indica o número de consultas. Finalmente, cada uma das C linhas seguintes descreve uma consulta e contém dois inteiros X e Y indicando, respectivamente, a ilha de início e a ilha do local do jogo.

## Saída

Para cada consulta, na ordem em que elas foram descritas na entrada, seu programa deve produzir uma linha contendo um único inteiro, o maior número de passageiros que o grupo pode ter para viajar junto do início até o local do jogo.

Restrições

    2≤N≤105
    1≤B≤105
    1≤I≤N, 1≤J≤N e I≠J, cada par I,J aparece no máximo uma vez na entrada.
    1≤P≤105
    1≤C≤5×104
    1≤X≤N, 1≤J≤N e X≠Y
*/
#include "stdio.h"
#include "stdlib.h"

typedef struct graph *Graph;
typedef struct node *link;
typedef struct {int v; int w; link next}Edge;

struct graph{
    int V; // numero de vértices
    int E; // Número de arestas
    int **adj; // inicializa a matriz de adjacência
};

int** MATRIZInit(int linhas, int colunas, int valorInicial){
    int** matriz = (int*)malloc(linhas*sizeof(int));
    for(int i = 0; i < linhas; i++){
        matriz[i] = (int*)malloc(colunas*sizeof(int));
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = valorInicial;
        }
    }
    return matriz;
}

Graph GRAPHInit(int v){
    Graph G = malloc(sizeof(*G));
    G->V = v;
    G->E = 0;
    G->adj = MATRIZInit(v, v, 0);
    return G;
}

void GRAPHInsert(Graph G, int v, int w, int peso){
    if(G->adj[v][w] == 0)
        G->E++;
    G->adj[v][w] == peso;
    G->adj[w][v] == peso;
}

int main(){
    int N, B; // N = número de inhas e B = número de barcos.
    scanf("%d %d", &N, &B);
    Graph G = GRAPHInit(N);
    int I[N], J[N], P[N]; // I e J = Indicam as duas ilhas ligadas pelo barco e P = O limite de passsageiros (dentro de um for de N).
    for(int i = 0; i < N; i++){
        scanf("%d %d %d", &I[i], &J[i], &P[i]);
        GRAPHInsert(G, I[i], J[i], P[i]);
    }
    int C; // Número de consultas feitas.
    scanf("%d", &C);
    int X[C], Y[C]; // X = Ilha de início, Y = Ilha de jogo.  
    for(int j = 0; j < C; j++){
        scanf("%d %d", &X[j], &Y[j]);
    } 
    return 0;
}