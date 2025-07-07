# Estrutura Union-Find (Disjoint Set Union - DSU)

## 1. Objetivo

A estrutura **union-find** serve para **representar conjuntos disjuntos** de forma eficiente, com suporte para as operações:

- `find(v)`: identificar a qual conjunto pertence o elemento `v`.
- `union(v, w)`: unir os conjuntos contendo os elementos `v` e `w`.

---

## 2. Representação Interna

### Vetores usados:

- `id[]`: vetor de inteiros, onde `id[v]` aponta para o "pai" de `v`. Se `v` é o representante (raiz) de seu conjunto, então `id[v] == v`.
- `sz[]`: tamanho da árvore representando cada conjunto (usado para balancear).

---

## 3. Operações Básicas

### Inicialização: `UFinit(n)`

```c
void UFinit(int n) {
   for (int i = 0; i < n; i++) {
      id[i] = i;
      sz[i] = 1;
   }
}
```

### Busca: `UFfind(v)`

```c
int UFfind(int v) {
   while (v != id[v])
      v = id[v];
   return v;
}
```

### União: `UFunion(v,w)`

```c
void UFunion(int v, int w) {
   int i = UFfind(v);
   int j = UFfind(w);
   if (i == j) return;

   if (sz[i] < sz[j]) {
      id[i] = j;
      sz[j] += sz[i];
   } else {
      id[j] = i;
      sz[i] += sz[j];
   }
}
```

- Une as árvores representando os conjuntos.
- Sempre liga a menor árvore na maior, evitando crescimento desbalanceado.

## 4. Heurísticas de Otimização
- Balanceamento por Tamanho (sz[])
    - Garante que a altura da árvore seja pequena.
    - Evita piores casos como listas encadeadas.
- Compressão de Caminho (não incluída no código base)
    - Ao fazer find, torna todos os vértices no caminho filhos diretos da raiz.
    - Reduz a profundidade e melhora a eficiência futura.

## 5. Complexidade

- Com heurísticas (balanceamento e compressão de caminho), as operações têm complexidade praticamente constante:
- O(α(n))(func¸a˜o inversa de Ackermann)
- O(α(n))(func¸​a˜o inversa de Ackermann)
- Na prática, α(n) < 5 mesmo para valores muito grandes de n.

## 6. Aplicações Clássicas

- Algoritmo de Kruskal para encontrar a MST.
- Detectar ciclos em grafos.
- Gerenciamento de componentes conexas dinâmicas.
- Clustering, sistemas de tipos, agrupamentos de estados.

