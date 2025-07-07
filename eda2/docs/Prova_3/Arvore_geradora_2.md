# Árvore Geradora Barata (MST) 

## 1. O Problema da Árvore Geradora de Custo Mínimo (MST)

Dado um grafo **não-dirigido, conexo** e com arestas ponderadas, a **árvore geradora mínima (MST)** é uma árvore geradora que:

- Contém todos os vértices do grafo;
- É acíclica e conexa;
- Possui o **menor custo total** possível (soma dos pesos das arestas).

> ℹTodas as MSTs têm o mesmo custo, mas **podem não ser únicas**.

---

## 2. Propriedades Fundamentais

### Circuito Fundamental e Otimalidade
- Seja \( T \) uma MST e \( e \notin T \).
- Adicionar \( e \) forma um circuito.
- Se uma aresta \( t \) do circuito tem peso maior que \( e \), então \( T + e - t \) é uma MST **mais barata**, o que contradiz \( T \) ser ótima.

**Conclusão**:  
No circuito fundamental de qualquer \( e \notin T \), todas as arestas \( t \in T \) têm peso menor ou igual ao de \( e \).

### Corte Fundamental e Otimalidade
- Remover uma aresta \( t \in T \) separa \( T \) em dois subconjuntos.
- O corte fundamental é o conjunto de arestas entre esses subconjuntos.
- Nenhuma aresta \( e \notin T \) nesse corte pode ser mais barata que \( t \), senão \( T - t + e \) teria custo menor.

---

## 3. Algoritmos para Computar MST

### Algoritmo de Prim (Jarnik)
- Cresce a MST a partir de um único vértice.
- A cada passo, adiciona a aresta de menor peso que conecta a árvore a um novo vértice.
- Usa estrutura de dados como **fila de prioridade (heap)** para eficiência.

- Invariantes:
    - Arestas em `mst` formam uma árvore.
    - A fila `pq` contém as menores arestas que cruzam a fronteira da MST parcial.

---

### Algoritmo de Kruskal
- Ordena todas as arestas por peso.
- Adiciona as arestas mais baratas que **não formam ciclos**.
- Usa estrutura **Union-Find (UF)** para manter componentes conexas.

- Invariantes:
    - `mst` não contém ciclos.
    - Quando contém \( V - 1 \) arestas, ela é uma MST.

---

## 4. Código em C — Algoritmo de Kruskal

```c
int UFfind(int v) {
   while (v != id[v]) v = id[v];
   return v;
}

void UFunion(int v, int w) {
   int i = UFfind(v), j = UFfind(w);
   if (i == j) return;
   if (sz[i] < sz[j]) {
      id[i] = j; sz[j] += sz[i];
   } else {
      id[j] = i; sz[i] += sz[j];
   }
}
```
