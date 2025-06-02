# Grafos

## Lista de adjagências

<p>Qualquer operação para percorrer os vértices para proucurar as arestas vamos gastar um tempo proporcional a v^2, por isso vamos utilizar as listas adjacentes, por mais que podemos utilizar aquelas técnica de não preecisar olhar os vertices meenores da matriz, ainda temos um tempo não muito agradável para esse tipo de problema, ainda mais com muitas arestas e vértices. Uma maneira diferente mas que tem sua funcionalidade, ao invés de termos uma matriz teremos como se fosse um grande vetor, e cada "coisa" dentro desse vetor seja uma lista encadeada, e quando tiver uam aresta teremos um nó saíndo dessa posição do vetor e mostrando ao qual ele está ligado, e se não estivermos falando de um grafo dirigido, o outro também terá seu nó apontado para ele.</p>
<p>Vamos fazer nossas operações, são essencialmente as mesmas da matriz de adjacência, somente tomando cuidado sabendo que estamos falando de uma fila e não de uma matriz, adicionaremos então o nó.</p>

<p align="center">Estrutura do nó em lista de adjacências</p>

```C
typedef struct node *link
struct node {int v; link next;};
struct graph{int V; int E; link *adj;};
link NEW(int v; link next){
    link x = malloc(sizeof *x);  // Cria a aresta
    if(x == NULL)
        tela_azul(); // Não encontrou , ou não foi criado nenhuma estrutura
    x->v = v;   // Adiciona na struct o v
    x->next = next; // Coloca o link para a próxima dentro da struct
    return x;
}

graph GRAPHInit(int V){  // Cria o grafo
    int v;
    Graph G = malloc(sizeof *G);    // Aloca a quantidade de espaço para os vértices
    G->v = V;   // Recebe os vértices colocados
    G->E = 0;   // Zera as arestas
    G->adj = malloc(V*sizeof(link)); // Cria nosso vetor de adjacências
    for(v = 0; v < V; v++)
        G->adj[v] = NULL; //  Criamos uma lista de adjacências e indicamos que estão apontando para NULL, já que não temos arestas no momento.
    return G;
}

void GRAPHInsert(Graph G, Edge e){
    int v = e.v, w = e.w;
    G->adj[v] = NEW(w, G->adj[v]); // Inserimos no início da lista simplesmente por ser mais barato.
    G->adj[v] = NEW(v, G->adj[w]);
    G->E++;
}
```