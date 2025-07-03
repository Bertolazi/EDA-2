# Grafos

## Resumo de grafos

<p>O importante é definir a relação entre os nós, então temos um conjunto de vértices que têm relação com outro conjunto de vértices, tudo o que implementamos é para fazer perguntas de como essas relações se comportam ou se relacionam, essa conexão se da por meio de arestas. Por mais que a estrutura gráfica dos grafos seja simples com as bolinhas representando os vértices, e as linhas representando as arestas, quando tratamos essa estrutura na análise de dados essa estrutura já não é mais tão simples quanto aparenta ser.</p>
<p>Podemos representar o grafo de duas formas:</p>

- Matriz de adjacência: Número 1 quando tem relação e 0 quando não tem relação;
- Lista de adjacência: Colocamos no índice do vetor um link para os outros vértices com que eles estão ligados pela arestas;

## Componentes conexas

<p>Como podemos identificar as componentes conexas usando busca em profundidade? Bem, para isso vamos pegar como exemplo o grafo abaixo já msotrado na aula passada, veja abaixo:</p>

<div style="text-align: center;">
    <p>Grafo 5: Grafo exemplo</p>
    <img src="../../assets/grafos/grafo_ex_aula_2.png" alt="Grafo 5">
    <p>Fonte - Autoral</p>
</div>

<p>Como podemos ver no grafo acima temos duas componentes conexas: Todo grupo unido com o 0 de um lado, e do outro o 9 junto do 8. Como podemos fazer isso? Bom mas antes de fazer isso vamos fazer uma função genérica para fazer uma busca geral no gráfico, contando quantos vértices eu visitei</p>

<p align="center">Função GRAPHSearch para matriz de adjacências</p>

```C
static int count, pre[maxV];
void GRAPHSearch(Graph G){  // Com esse algoritmo o sistema computa a saída da componente conexa e vai para a próxima
    int v; // Vértices que vou visitar
    int conexos = 0;
    count = 0;
    for(v = 0; G->V; v++)
        pre[v]=-1;
    for(v = 0; G->V; v++){ // Executa todos de 0 a 7, na segunda interação ele faz a interação de 8 e 9
        if(pre[v] == -1){ // Se for != de -1 ele nem entra na DSF
            dsfR(G, EDGE(v, v));
            conexos++;
        }
    }
}
```

<p align="center">Função GRAPHSearch para lista de adjacências</p>

```C
void dfsR(Graph G, Edge e){
    int t, w = e.w;
    link l;
    pre[w] = count++;
    for(l=G->adj[w]; l != NULL; l = l->next){
        t = l->v;
        if(pre[t] == -1)    
            dfsR(G, EDGE(w, t));
    }
}
```

## Execução


