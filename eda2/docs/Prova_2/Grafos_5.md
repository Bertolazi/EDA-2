# Grafos

## Grafos dirigido

- A ideia dos grafos dirigidos é que agora as arestas dos grafos agora possuem direções, diferente de alguns de nossos grafos mostrados anteriormente onde dentro das matriz de adjacências ou da lista de adjacências sempre que A apontava para B, ou vet[A][B] é verdade, o nosso B apontava apara Ae vet[B][A] também era verdade. No caso do grafo dirigido temos uma via de mão única onde se A aponta para B, B não aponta para A por regra.

<div style="text-align: center;">
    <p>Grafo 5: Grafo dirigido exemplo</p>
    <img src="../../assets/grafos/grafo_dirigido_ex.png" alt="Grafo 6">
    <p>Fonte - Autoral</p>
</div>

- A relação deles na lista de adjacência é igual no outro grafo mas sem a regra de se A->B, B->A também.

- O máximo de arestas é 2*V.

- Grafo dirigido (ou dígrafo): É um conjunto de vértices e um conjunto de arestas dirigidos que conectam um par de vértices (Sem arestas duplicadas). Dizemos que essa aresta vai de um primeiro vértice para o segundo vértice.

- Edge{int v, int w}, v é o primeiroe w é o segundo.

- Caminho dirigido: Em um grafo dirigido a lista de vértices no qual existe uma resta derigida conectando cada vértice da lista a seu sucessor. Dizemos de um vértice t é alcançável de um vértice s se existe um caminho dirigido de s a t.

- Quantidade de arestas em um grafo não dirigido é V^2, já em um grafo dirigido temos 2^(V^2)

<p align="center">Como inverter as arestas de um grafo dirigido?></p>

```C
Graph GRAPHReverse(Graph G){
    int v, int t;
    Graph R = GRAPHInit(G->v);
    for (v=0; v < G->V; v++)
        for(t=g->adj[v]; t != NULL; t++)
}
```