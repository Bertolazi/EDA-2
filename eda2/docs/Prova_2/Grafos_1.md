# Grafos

## Tipo abstratdos de dados: Itens 

<p>Para esse primeiro momento dentro do estudo de grafos não nos interessa muito o que tem dentro desses itens e sim como eles se relacionam com outros itens, então por exemplo em uma lista telefônica, temos itens de uma lista telefônica, dentro desses itens temos o nome da pessoa e o número de telefone dessa pessoa, consideramos que o nome da pessoa é a chave que usamos para fazer a busca dentro das relações que estabelecemos, mas esses dados dentro de uma tabela hash não se relacionam diretamente, agora pensando em grafos pensamos realmente nas relações que os itens tem entre eles, mas tudo bem, quais são essas relações?</p> 
<p> Podemos pensar primeiramente em um mapa, imagine que traçou uma rota da sua faculdade até sua casa, ele vai te gerar uma rota, podemos imaginar que cada interceção de ruas é um nó do nosso grafo e a própria rua é o caminho entre esses nós, e tem relação com os outros nóes pelas ruas. O maps então relcionando com os grafos, ele calcula os nós e define o melhor caminho até chegar no nó de desejo. Outro conjunto de relações que podemos relacionar com grafos são as páginas webs, pensando em um site, que tem acesso a outro, cada um desses hiperlinks é um nó do grafo que nos leva a outro site. Outro exemplo muito legal são circuitos elétricos, com os pontos de conexão sendo nós do nosso grafo, e os fios os caminhos que nos levam aos outros nós. Outro caso legal seria o exemplo de rede de computadores, por exemplo, na RNP (Rede nacional de pesquisa), toda vez no esquema que vemos a sigla de um estado em um roteador temos um ponto de rede para se comunicar com outra faculdade de outro estado, cada um dessas siglas representa um nó de rede nos estado, e a linha que os liga é o caminho de nó a nó, o interessante desse exemplo é que por exemplo imagine que caia uma rota DF para SP, o grafo busca outro caminho sem ser o direto entre esses dois estados, fazendo assim, não dependente de uma única rota.</p>  

## O que é um grafo? 

<p> Um conjunto de vértices, e um conjunto de arestas (conectam pares distindos de vértices), os vértices são numerados de 0 a v-1, representamso os grafos com bolinhas ligadas por linhas que conectam os mesmos (Como estamos em um teclado de computador, indicaremos sem as bolinhas). </p> 

<div style="text-align: center;">
    <p>Grafo 1: Exemplo (4 vértices de 0 até 3)</p>
    <img src="../../assets/grafos/grafo_1.png" alt="Grafo 1">
    <p>Fonte - Autoral</p>
</div>

### Algumas regras fundamentais: 

- Não temos uma aresta que sai dela e vai para ela mesma; 
- Se uma aresta sai por exemplo do nó 0 para o nó 2, o caminho é de duas vias, ou seja, do 2 eu consigo ir para o 0; 
- Essa "via de mão dupla" pode ser interrompida em grafos que chamamos de **grafos dirigidos**, com uma seta no final da aresta temos a indicação de um caminho só de ida entre um nó e outro (veja o grafo 2 abaixo); 

<div style="text-align: center;">
    <p>Grafo 2: Grafo dirigido</p>
    <img src="../../assets/grafos/grafo_dirigido.png" alt="Grafo direcionado">
    <p>Fonte - Autoral</p>
</div>

### Tipos de grafos: 

- **Grafo completo:** Todos os vértices se conectam com todos os vértices:

<div style="text-align: center;">
    <p>Grafo 3: Grafo completo</p>
    <img src="../../assets/grafos/grafo_completo.png" alt="Grafo 1">
    <p>Fonte - Autoral</p>
</div>

  
