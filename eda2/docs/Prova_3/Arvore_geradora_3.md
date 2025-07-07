# Algoritmo de Prim — Árvores Geradoras de Custo Mínimo (MST)

## 1. Objetivo

Construir uma **Árvore Geradora de Custo Mínimo (MST)** em um grafo **não-dirigido, conexo e ponderado**, utilizando o **algoritmo de Prim** (também conhecido como algoritmo de Jarnik).

---

## 2. Ideia do Algoritmo

- Começa com um vértice arbitrário \( s \) e constrói a MST incrementalmente.
- Em cada passo, adiciona a **menor aresta que conecta** a árvore construída a um vértice fora dela.

---

## 3. Variáveis Usadas

- `pai[v]`: pai do vértice `v` na MST.
- `dist[v]`: menor peso de uma aresta que conecta `v` à MST.
- `franja`: conjunto de vértices fora da MST mas adjacentes a ela.
- `heap`: fila de prioridade que organiza os vértices da franja por `dist[v]`.

---

## 4. Invariantes do Algoritmo

- Os vértices na MST têm seus `pai[v]` definidos.
- Os vértices na franja têm `dist[v]` correspondendo à menor aresta conectando à MST.
- O heap contém exatamente os vértices da franja.

---

## 5. Etapas do Algoritmo

1. Inicialize todos os vértices com `dist[v] = ∞` e `pai[v] = -1`.
2. Escolha um vértice `s` inicial e defina `dist[s] = 0`.
3. Adicione `s` ao heap.
4. Enquanto o heap não estiver vazio:
   - Remova o vértice `v` com menor `dist[v]` do heap.
   - Para cada vizinho `w` de `v`:
     - Se `w` não está na MST e `peso(v,w) < dist[w]`:
       - Atualize `dist[w]` e `pai[w]`.

---

## 6. Código (pseudo-C)

```c
void primMST(Graph G, int s) {
    for (v = 0; v < G->V; v++) {
        dist[v] = INF;
        pai[v] = -1;
    }
    dist[s] = 0;
    PQinsert(s);

    while (!PQempty()) {
        int v = PQdelmin();
        for (link a = G->adj[v]; a != NULL; a = a->next) {
            int w = a->w;
            if (pai[w] == -1 || a->peso < dist[w]) {
                dist[w] = a->peso;
                pai[w] = v;
                PQdec(w, dist[w]);
            }
        }
    }
}
```

## 7. Complexidade

- Usando heap binário, a complexidade é O((V+E)log⁡V)O((V+E)logV).
- Mais eficiente que algoritmos de força bruta para grafos esparsos.

## 8. Exemplos e Testes

- É possível acompanhar o crescimento da MST através da sequência de vértices removidos do heap.
- A estrutura final de pai[v] forma a MST.