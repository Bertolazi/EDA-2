# Grafos

## Peso nas arestas

imagine um grafo onde um vértice é o Plano Piloto e ele está conectado a outro vértice que vamos chamar de Taguatinga, e imagine que a aresta é EPIA e possui 40 km, ou seja, estamos dadno um peso para a aresta que compõe esse grafo. Agora imagine outro vértice que é o Núcleo Bandeirante, do Plano Piloto para o Núcleo Bandeirante temos uma aresta de 30 km e de Taguuatinga para o Núcleo Bandeirante temos uma aresta de 20 km. Olhando o grafo abaixo percebemos de forma intuitiva o seguinte: Se eu quiser ir do Plano Piloto para o Núcleo Bandeirante eu não vou querer ir para Taguatinga antes, vamos ver que gastaríamos 60 km ao invés dos 30 km na conexão direta.

<div style="text-align: center;">
    <p>Grafo 9: Exemplo Grafo Brasília</p>
    <img src="../../assets/grafos/grafo_peso_arestas.png" alt="Grafo 7">
    <p>Fonte - Autoral</p>
</div>

- Como implementar peso nas arestas?
    - Matriz de adjacências: Antes nos grafos, das matrizes de ajjacências, marcávamos com valor binário a conexão dos vértices, ou seja, ao invés de colocar um, dentro da matriz de adjacência já colocamos o peso na matriz.
    - Lista de adjacência: Na nossa struct node {int v; link next;}; Responsável pelas arestas, agora nós adicionamos um inteiro para ser o peso das nossas arestas, ficaria algo como:

<p align="center">Nova struct das arestas para peso nas arestas</p>

```C
struct Edge {int v, int c, link next};
// int c é o peso da aresta
```

- Como eu saio de um vértice qualquer e chego em outro com o menor custo? Temos algoritmos para ele como:
    - Bellmon Ford:
        - Calcula o caminho mais curto de um único vértice
    - Dijkstra:
        - Calcula o caminho mais curto de um único vértice
    - A*:
        - Ao invés de calcular a origem para todos os destinos ele olha somente o ponto inicial e o final
- "Calcule as distâncias para todos os vértices que você alcança"

Vamos implementar nessa aula o Bellmon Ford:

## Bellmon Ford

```C
bool GRAPHcptBF(Graph G, int s, int *pa, int *dist){ // int s = Vértice de origem, int *dist = fala a distância para os vértices que conseguimos alcançar
    bool onqueue[1000]; // Não queremos inserir o mesmo vértice mais d euma vez na fila
    for(int v = 0; v < G->v; v++)
        pa[v] = -1, dist[v] = INT_MAX, onqueue[v] = false;  // aqui igual o pre da dfs onde vemos se já foi visitado temos o pa, e como não sabemos a distância inicializamos com infinito. Inicializamos todos com -1 pois não visitamos nenhum.
    pa[s] = s;     
    dist[s] = 0;
    Queueint(G->E);
    onueue[s] = true;
    while(1){
        int v = Queueget()
        if(){
            for(link a = G->adj[v]; a != NULL; a = a->next)
        }
    }
}
```