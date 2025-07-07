# Árvore geradora
## 1. Definição de Árvore Geradora

Uma **árvore geradora** (*spanning tree*) de um grafo **não-dirigido e conexo** é um subgrafo que:

- Inclui **todos os vértices** do grafo original.
- É **conexo** e **sem ciclos** (ou seja, uma árvore).
- Possui exatamente **V - 1 arestas**, onde *V* é o número de vértices.

> Todo grafo não-dirigido e conexo possui pelo menos uma árvore geradora.

---

## 2. Como Obter uma Árvore Geradora

- Tanto a **busca em profundidade (DFS)** quanto a **busca em largura (BFS)** podem gerar uma árvore geradora.
- Ambas constroem uma **árvore radicada**, conectando todos os vértices acessíveis a partir de um vértice inicial.
- As arestas exploradas formam uma árvore geradora.

---

## 3. Cortes em Grafos

- Um **corte** é o conjunto de arestas que conecta um subconjunto de vértices \( X \) ao seu complemento \( \overline{X} \).
- O **leque** de \( X \) é esse conjunto de arestas.
- Se o corte é vazio, o grafo é **desconexo**.

### Exemplo:
Para o grafo com arestas = 0-1, 0-2, 2-1, 3-5, 4-5:

O corte entre `{0}` e `{1,2,3,4,5}` é `{0-1, 0-2}`.

---

## 4. Propriedades de Substituição de Arestas

Essas propriedades são fundamentais para os algoritmos de MST (árvore geradora mínima).

### Propriedade dos Circuitos (Insere–Remove)

Seja \( T \) uma árvore geradora e \( e \notin T \). Então:

- O grafo \( T + e \) contém **um único circuito**.
- Remover qualquer aresta \( t \) desse circuito produz outra árvore geradora:  T + e - t → também é uma árvore geradora

> Esse circuito é chamado **circuito fundamental de e** em relação a T.

---

### Propriedade dos Cortes (Remove–Insere)

Seja \( t \in T \). A remoção de \( t \) decompõe \( T \) em duas componentes conexas.

- O **corte fundamental de t** é o conjunto de arestas que conecta essas duas partes.
- Para qualquer \( e \) nesse corte: T - t + e → também é uma árvore geradora


---

## Circuitos vs. Cortes

Existe uma relação direta:

> **t está no circuito fundamental de e**  
> **⟺**  
> **e está no corte fundamental de t**

---

## 5. Exercícios Propostos (do site)

- Encontrar árvores geradoras a partir de conjuntos de arestas.
- Usar DFS e BFS para gerar árvores.
- Calcular cortes e circuitos fundamentais.
- Implementar `CheckMST()` para verificar se um vetor de pais representa uma árvore geradora.

---

## Conceitos Resumidos

| Conceito              | Definição                                                                 |
|-----------------------|--------------------------------------------------------------------------|
| Árvore Geradora       | Subgrafo conexo, sem ciclos, com V-1 arestas                             |
| Leque de X            | Arestas entre X e seu complemento \( \overline{X} \)                     |
| Corte                 | Leque de um subconjunto não-trivial de vértices                          |
| Circuito Fundamental  | Único circuito criado ao adicionar uma aresta a uma árvore geradora      |
| Corte Fundamental     | Conjunto de arestas conectando as partes após remover aresta de T        |

---

## Referência

Fonte: [Paulo Feofiloff - IME USP](https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/spanningtrees.html)







