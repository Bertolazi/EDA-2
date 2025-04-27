/*
    -> Introdução
Nesse primeiro momento vamos introduzir a estrutura de dados denominada, estrutura de dispersão ou hash table. Essa estrutura é responsável por acelerar muitos algoritmos que envolvem consultas, inserções e remoções em uma tabela de dados.

    -> Um problema de contagem:
Suponha um dado fluxo de inteiros positivos na entrada padrão stdin. Vamos chamar esses números de chaves. As chaves estão em ordem arbitrária e há muitas chaves repetidas. Considere agora o problema de calcular a ocorrência de cada chave.
Por exemplo, o número de ocorrências de cada chave no fluxo  4998 9886 1933 1435 9886 1435 9886 7233 4998 7233 1435 1435 1004, é dado pela seguuinte tabela (na primeira linha temos as diferentes chaves e na segunda temos o número de occorência de cada chave).

1004 1435 1933 4998 7233 9886
1    4    1    2    2    3

Nosso problema de contagem tem um requisito adicional importante: A contagem deve ser de maneira incremental, ou seja, online. Ou seja, cada chave recebida no fluxo de entrada deve ser imediatamente contabilizada, de modo que tenhamos, a cada passo, as contagens referentes à parte do fluxo vista até o momento.
O desempenho de qualquer algoritmo para o problema será medido pelo tempo consumido para contabilizaruma chave, ou seja, não dependesse do número de chaves já lidas (nem do número de chaves distintas já lidas), mas teremos que nos contentar com algo menos que o ideal.

Dsicutiremos 4 soluções diferentes, onde as duas primeiras serão mais simples e as duas outras mais complexas, mas obviamente mais eficientes na prática. Embora simples os dois primeiros constituem uma importante introdução aos dois outros.

Denotaremos por N o comprimento do fluxo de entrada, ou seja, o número total de chaves no fluxo. O valor de N pode ser muito grande (milhões ou até bilhões), mas o número de chaves distintas é tipicamente bem menor. 
Suporemos que todas as chavessão menores que um número R. No exemplo acima, podemos supor que R vale 10000. O conjunto 0...R-1 será chamado de universo de chaves. Em geral, a maioria das chaves do universo não aprece no fluxo de entrada. 

    Exercício 1: Critique a seguinte proposta de algoritmo par ao problema da contagem: Armazene o fluxo de chaves em um vetor; Ordene o vetor; Depois percorra o vetor ordenado contando o número de ocorrências de cada chave. 

    -> Algoritmo 1: Endereçamento direto
Começamos com um algoritmo conhecido como endereçamento direto. Embora muito simples, esse algoritmo contém a semente da técnica de hashing. 
Suponhamos que as chaves são do tipo int e que  R chaves cabem confortavelmentena memória RAM do computador. Podemos então usar uma tabela tb[0...R-1] para registrar os números de ocorrências das chaves. 

int *tb;
tb = malloc (R*sizeof(int))

O algoritmo de endereçamento direto inicializa o vetor tb com zeros e repete a seguinte rotina: lê uma chave ch do fluxo de entrada e contabiliza a chave executando a seguinte função: 

void contabiliza(int ch){
tb[ch]++
}

Depois de cada execução dessa função, para cada c em 0...R-1, o valor de tb[c] será o número de ocorrências de c na parte do fluxo lida até o momento.

. Desempenho: Cada invocação da função contabiliza consome tempo constante, ou seja, independente do tamanho de Rdo universo ou do número de chaves já lidas (Em particular não depende de N). Esse algoritmo é muito rápido mas só é prático se R for muito pequeno e conhecido explicitamente de antemão. Mesmo nesse caso, o algoritmo pode desperdiçar muito espaço. Por exemplo, se R cale 10 mil e o fluxo só tem mil chaves distintas, 90% do vetor tb ficará ocioso
*/