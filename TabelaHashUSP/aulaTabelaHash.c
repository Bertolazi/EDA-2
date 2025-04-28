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

    -> Algoritmo 1 - Endereçamento direto:
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

    Exercicío 2: Testes de desempenho.  Escreva e teste um programa que use endereçamento direto para resolver o problema da contagem e imprima um relatório com as seguintes informações: o comprimento N do fluxo de entrada, o número de chaves distintas, a chave mais frequente (ou seja, a que ocorre mais vezes), e o número de ocorrências dessa chave. Use como fluxo de entrada os arquivos randInt1K.txt, randInt10K.txt, randInt100K.txt e randInt1M.txt, que contêm mil, 10 mil, 100 mil e 1 milhão de chaves aleatórias, todas entre 0 e 9999.  Cronometre o seu programa usando a função clock da biblioteca time.  O resultado está de acordo com as previsões teóricas? Feito no arquivo 1_teste_1

    -> Algoritmo 2 - lista encadeada:
Nosso segundo algoritmo armazena a contagem das chaves em uma lista encadeada. As células da lista podem ter a seguinte estrutura: 

typedef struct reg celula

struct reg{
    int chave, ocorr;
    celula *prox;
};

Se p é o endereço de uma célula então p->ocorr será p número de ocorrências de p->chave. Se p e q são endereços de duas células diferentes então p->chave será diferente de q->chave. A lista encadeada será apontada pela variável global tb. 

celula *tb;

O algoritmo de contagem inicializa tb com NULL e repete a seguinte rotina: Lê uma chave ch do fluxo de entrada e invoca a seguinte função para contabilizar a chave: 

void contabiliza (int ch){
    celula *p;
    p = tb;
    if(p!= NULL)
        p->ocorr++;
    else{
        p = malloc(sizeof(celula));
        p->chave = ch;
        p->ocorr = 1;
        p->prox = tb;
        tb = p;
    }
}

. Desempenho: No pior caso a execução da função contabiliza consome tempo proporcional ao número de chaves distindas já lidas. Portando a execução dessa função contabiliza pode ficar cada vez mais lenta a medida que o fluxo na entrada é lido. Se todas as chaves forem distintas , as últimas execuções da função contabiliza pode consumir tempo proporciaonal a N. Mesmo no caso médio, típico de aplicações práticas, a função contabiliza pode consumir tempo proporcional à metade do número de chaves distintas já lidas, o que não é satisfatório. Por outro lado, essa solução do problema de contagem não desperdiça espaço, pois o número de chaves é igual ao número de células, pois o número de célulasé igual ao número de chaves distintas no fluxo de entrada.

    Exercício 3: Lista em ordem crescente.  Reescreva a função contabiliza acima de modo que as chaves sejam armazenadas na lista encadeada em ordem crescente. Estime o desempenho. Vale a pena manter a lista em ordem crescente?
    Testes de desempenho.  Repita os testes sugeridos num dos exercícios acima, desta vez usando uma lista encadeada para armazenar as contagens.
    Vetor de células.  Refaça a discussão da seção anterior usando um vetor de células no lugar de uma lista encadeada. Redimensione o vetor à medida que o número de chaves distintas aumenta. Qual o consumo de tempo dessa versão? Agora mantenha o vetor em ordem crescente de chaves e refaça a análise. 

    -> Tabelas de dispersão e funções de espalhamento:
O próximos algoritmos vão combinar as boas características dos dois algoritmos anteriores. Antes porém, precisamos introduzir o conceito de hashing. Começamos por estabelecer a terminologia e descrever as ideias de maneira abstrata. Implementações concretas serão dadas nas próximas seções. 
Vamos supor que a contagem de chaves de chaves é registrada em um vetor tb[0...M-1]. O parâmetro M é conhecido como módulo. O valor de M e a natureza exata dos elementos do vetor ficarão indefinidas por enquanto, mas você deve imaginar que, de alguma forma, cada elemento de tb registra o número de ocorrências de alguma chave. O vetor tb será chamado de tabela de dispersão (= hash table). O tamanho da tabela M é usualmente muito menor que menor que o tamanho R do universo de chaves. Assim um elemento de tb deverá cuidar de duas ou mais chaves. 

Para encontrar a posição no vetor tb que corresponde a uma chave ch é preciso converter ch em um índice entre 0 e M-1. Qualquer função que faça a conversão, levando o universo 0...R-1 das chaves no conjunto 0...M-1 de índices é chamada de função de espalhamento (=hash function). Aqui chamaremos de:

hash(ch, M)

A invocação de uma função de espalhamento por uma chave ch. O número hash(ch, M) será chamado de código hash(=hash code) da chave ch. Uma função de espalhamento muito  popular leva cada chave ch em ch%M, ou seja, o resto da divisão ch por M. Se M vale 100, por exemplo, então ch%M consiste nos dois últimos dígitos de ch. Se a função de espalhamento tiver duas chaves no mesmo índice, teremos uma colisão. Se M é menor que R e mais ainda se M é menor que o número das chaves distintas as colisões são inevitáveis, como falado no exemplo acima se M=100 todas as chaves com 2 últimos igitos iguais vão colidir em um mesmo índice.

Uma boa função de espalhamento deve espallhar bem as chaves no conjunto 0...M-1 de índices. Uma função que leva toda chave em umíndice par por exemplo é ruim, uma função que só depende de poucos índices para chave também não é boa. Infelizmente não existe uma função de espalhamento que seja boapara todos os conjuntos de chaves extraídos do universo 0...R-1, mas para começar a enfrentar essa dificuldade o M dever ser um número primo, pois isso tende a diminuir o número de colisões. Veja o exemplo abaixo tirado do livro do Sadwick e wayne e considere o resto de cada divisão sendo uma delas 100 (um número não-primo) e 97 (um número primo). 

ch      ch%100   ch%97      
212      12      18
618      18      36
302       2      11
940      40      67
702       2      23
704       4      25
612      12      30
606       6      24
772      72      93
510      10      25
423      23      35
650      50      68
317      17      26
907       7      34
507       7      22
304       4      13
714      14      35
857      57      81
801       1      25
900       0      27
413      13      25
701       1      22
418      18      30
601       1      19

No ch%100 temos os índices: 1 (3 vezes), 2 (2 vezes), 4 (2 vezes), 7 (2 vezes), 12 (2 vezes), 13 (3 vezes),18 (2 vezes) e 25 (3 vezes), ou seja 19 colisões; Já no ch%97 temos os índices: 1 (3 vezes), 18 (2 vezes), 25 (3 vezes) e 35 (2 vezes), ou seja 10 colisões, uma diminuição considerável, quase a metade. Agora que cuidamos de espalhar as chaves pelo intervalo 0...M-1, precisamos inventar um meio de resolver as colisões. As seções eguintes mostram maneiras de fazer isso. 

    Exercício 4.1: Por que módulo primo?  Suponha que ch e M são divisíveis por um inteiro k.  Mostre que ch % M também será divisível por k.  (Este exercício dá uma pequena indicação das vantagens de usar um número primo como valor de M.): 
    Resposta:
Não Divisibilidade: Um número primo não é divisível por nenhum número inteiro além de 1 e ele mesmo, o que evita a situação em que chch e MM compartilham fatores comuns, resultando em colisões mais frequentes.

    -> Algoritmo 3 - hashing com encadeamento:
A técnica de hashing tem dois ingredientes: 

*/