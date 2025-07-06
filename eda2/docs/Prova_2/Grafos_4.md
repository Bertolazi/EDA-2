# Grafos

## Busca em largura (BFS)

<p>O BFS é preferível quando se busca encontrar o caminho mais curto entre dois nós em um grafo não ponderado (onde todas as arestas têm o mesmo peso), enquanto o DFS é mais eficiente quando se busca explorar um grafo em profundidade, ou quando se deseja encontrar soluções que podem estar distantes da fonte.</p>

<p align="center">Algoritmo da BFS</p>

```C
void bfs(Graph G, Edge e){
    int v, w;
    Queueput(e);
    pre[e.w] = count++;
    while(!Queueempty()){
        e = Queueget();
        w = e.w;
        for(l=G->adj[w]; l != NULL; l = l->next){
            t = l->v;
            if(pre[t] == -1){
                Queueput(EDGE(w, t));
                pre[t] = count++;
            }
        }
    }
}
```

### Execução manual