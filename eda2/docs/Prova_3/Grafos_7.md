# Grafos

Nessa aula vamos implementar o algorutmo Dijkstra, então vamos lá:

## Dijkstra (ingênuo)

- Outro algoritmo para encontrar caminhos mínimos, no caso o Dijkstra, geralmente tem um desempenho melhor.
- O grafo só pode ter arestas com pesos positivos. 
- Função com bom desempenho para grafos não tão ingênuos, para grafos muito ingênuos sua complexidade ainda fica próxima a v².
- A ideia do algoritmo é sair de um vértice e ele não sabe qual o seu destino, mas ele te fornece todos os menores caminhos para os outros vértices e você analisa o que você quer. Ao final temos uma árvore geradora criada a partir da raiz.

```C
void GRAPHcptD1(Graph G, int s, int *pa, int *dist){
    bool mature[1000];  // Um vértice maduro é quando eu já explorei todo mundo que esse vértice sai
    for(int v = 0; v < G-> v; v++)
        pa[v] = -1;, mature[v] = false, dist[v] = INT_MAX;
    pa[s] = 1;
    dist[s] = 0;
    while(true){
        int min = INT_MAX;
        int y;
        for(int z = 0; z < G->v; z++){
            if(mature[z]) continue;
            if(dist[z] < min){
                min = dist[z];
                y = z;
            }
        }
        if(min == INT_MAX)
            break;
        for(link a = G>adj[y]; a != NULL; a = a->next){ // Para listas de adjacências
            if(mature[a->v]) 
                continue;
            if(dist[y] + a->c < dist[a->v]){
                dist[a->v] = dist[y] + a->c;
                pa[a->v] = y;
            }
        } 
        mature[y] = true;
    }
}
```

### Execução manual

## Resumo ChatGPT

| Algoritmo    | Aceita Pesos Negativos | Detecta Ciclos Negativos | Complexidade          |
| ------------ | ---------------------- | ------------------------ | --------------------- |
| Bellman-Ford | ✅ Sim                  | ✅ Sim                    | O(V × E)              |
| Dijkstra     | ❌ Não                  | ❌ Não                    | O((V + E) log V)      |


- Para grafos somente com pesos positivos Drijkstra é melhor.
