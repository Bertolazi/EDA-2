# Algoritmo de Kruskal — Árvores Geradoras Mínimas (MST)

## 1. Objetivo

Construir uma **Árvore Geradora de Custo Mínimo (MST)** de um grafo **não-dirigido, conexo e ponderado**, usando o **algoritmo de Kruskal**.

---

## 2. Ideia do Algoritmo

- Ordena todas as arestas do grafo por peso crescente.
- Inicializa a MST como vazia.
- Para cada aresta na ordem:
  - Adiciona a aresta se ela **não forma ciclo** com as arestas já adicionadas.

> A ideia é manter uma **floresta crescente** que se funde progressivamente em uma árvore.

---

## 3. Estrutura de Dados Utilizada

### Union-Find (UF)

Usada para:
- Representar as **componentes conexas** atuais.
- Detectar **ciclos** ao tentar unir dois vértices.

#### Principais funções:
- `UFfind(v)`: encontra o representante da componente de `v`.
- `UFunion(v, w)`: une as componentes dos vértices `v` e `w`.

---

## 🪜 4. Etapas do Algoritmo

1. Inicializar `UFinit(n)` com `n` vértices.
2. Ordenar todas as arestas por peso crescente.
3. Iterar sobre cada aresta `(v, w)`:
   - Se `UFfind(v) != UFfind(w)`:
     - Adiciona a aresta à MST.
     - Faz `UFunion(v, w)`.

4. Parar quando a MST tiver `n - 1` arestas.

---

## 5. Código em C — Union-Find

```c
int
UFfind(int v) {
   while (v != id[v]) v = id[v];
   return v;
}

void
UFunion(int v, int w) {
   int i = UFfind(v), j = UFfind(w);
   if (i == j) return;
   if (sz[i] < sz[j]) {
      id[i] = j; sz[j] += sz[i];
   } else {
      id[j] = i; sz[i] += sz[j];
   }
}
```

## 6. Complexidade

- Ordenar arestas: O(Elog⁡E)O(ElogE)
- Operações UF: quase constantes com heurísticas (custo quase linear).
- Complexidade total: O(Elog⁡E)O(ElogE), onde EE é o número de arestas.

## 7. Observações

- Kruskal é especialmente eficiente para grafos esparsos.
- O algoritmo constrói uma MST de forma incremental e global (escolhe arestas em ordem global, diferente do Prim que cresce localmente).