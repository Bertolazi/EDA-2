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
A técnica de hashing tem dois ingredientes: uma função de espalhamento e um mecanismo de resolução de colisões. A seção anterior discutiu o primeiro ingrediente, nessa seção vamos falar do segundo. As colisões na tabela de dispersão podem ser resolvidas por meio de listas encadeadas: Todas as chaves que têm um mesmo código hash são armazenados em uma lista encadeada. As células da lista encadeada é igual a do algoritmo 2.

typedef struct reg celula;
struct reg{
    int chave, ocorr;
    celula *prox;
};

Podemos supor então que os elementos da tabela de dispersão tb[0...M-1] são ponteiros para listas encadeadas: 

celula **tb;
tb - malloc(M*sizeof(celula *));

Para cada índice h, a lista encadeada tb[h] conterá todas as chaves que têm código hash h. O algoritmo de contagem resultante é conhecido como hashing com encadeamento e pode ser visto como uma combinação dos algoritmos 1 e 2 discutidos acima. O algoritmo inicializa todos os elementos do vetor tb com NULL e repete a seguinte rotina: lê uma chave ch do fluxo de entrada e executa a seguinte função:  

void contabiliza (int ch){
    int h = hash (ch, M);
    celula *p = tb[h];
    while(p != NULL && p->chave != ch)
        p = p->prox;
    if(p != NULL){
        p->ocorr += 1;
    }else{
        p = malloc (sizeof(celula));
        p->chave = ch;
        p->ocorr = 1;
        p->prox = tb[h];
        tb[h] = p;
    }
}

. Desempenho: No pior caso, a função de espalhamento da hash leva todas as chaves na mesma posição da tabela de dispersão e portanto todas as chaves ficam na lista encaadeada. Nesse caso, o desempenho não é o melhor que o do algoritmo 2: Cada execução de contabiliza consome tempo proporcional ao número de chaves já lidas no fluxo de entrada. 
No caso médio, típico de aplicações práticas, o desempenho de contabiliza é muito melhor. Se a função hash espalhar bem as chaves pelo conjunto 0...M-1, todas as listas encadeadas terão aproximadamente o mesmo comrprimento e então podemos esperar que o consumo de tempo do contabiliza seja limitado por algo proporcional a: n/M, onde n é o número de chaves lidas até o momento. Se M for 997, por exemplo, podemos esperar que a dunção seja cerca de 1000 vezes mais rápida que aquela do algoritmo 2. É claro q devemos proucurar escolher um valor de M que seja grande o suficiente para que as M listas sejam curtas (digamos que dezenas de elementos) mas não tão grandes que muitas das listas fiquem vazias. 
    
    Exercícios 5: . Resolva o problema da contagem para o fluxo de chaves  17 21 19 4 26 30 37  usando hashing com encadeamento. A tabela de dispersão deve ter tamanho 13 e a função de espalhamento deve ser o resto da divisão da chave por 13.  Faça uma figura do estado final da tabela de dispersão.
    . Suponha que o comprimento N do fluxo de entrada é aproximadamente 50000.  Escolha um bom valor para o tamanho M da tabela de dispersão.
    . Testes de desempenho.  Repita os testes sugeridos num dos exercícios acima, desta vez usando uma tabela de dispersão com colisões resolvidas por encadeamento.  Experimente diferentes valores (primos e não-primos) para o tamanho M da tabela de dispersão.  Determine a média e o desvio padrão dos comprimentos das listas encadeadas. 
    -> Algoritmo 4: hashing com sondagem linear
Esta seção mostra como resolver colisões na tabela de dispersão: Todas as chaves que colidem são armazenadas na própria tabela. Os elementos da tabela de dispersão tb[0...M-1] são células que têm apenas os campos chaves e ocorr.

typedef struct reg celula;
struct reg{
    int chave, ocorr;
};

celula *tb;
tb = malloc(M*sizeof(celula));

Durante a contagem, algumas das células da tabela tb estarão vagas enquanto outras estarão ocupadas. As células vagas terão chave igual a -1. Nas células ocupadas, as chaves estarão em 0...R-1 e ocorr será o correspondente de número de ocorrências. SSe uma célula tb[h] está vaga podemos garantir que nenhuma chave na parte já lida do fluxo de entrada tem código hash igual a h. Mas se tb[h] está ocupada, não podemos concluir que o código hash de tb[h].chave é igual a h. 

Cada chave ch do fluxo de entrada será contabilizada da seguinte maneira. Seja h o código hash de ch, se a célula tb[h] estiver vaga ou tiver chave igual a ch, o conteúdo da célula é atualizado. Senão o algoritmo proucura a próxima célula de tb que esteja vaga ou que tenha chave igual a ch. A implementação dessas ideias leva o algoritmo de hashing com sondagem linear. O algoritmo começa começa por inicializar todas as células da tabela tb fazendo chave = -1 e ocorr = 0. Depois repete a seguinte rotina: lê uma chave ch e executa a seguinte função: 

void contabiliza(int ch){
    int c, sonda, h;
    h = hash(ch, M);
    for(sonda = 0; sonda < M; sonda++){
        c = tb[h].chave;
        if(c == -1 || c == ch) break; // *
        h = (h+1)%M;
    }
    if(sonda>=M) 
        exit(EXIT_FAILURE);
    if(c == -1)
        tb[h].chave = ch;
    tb[h].ocorr++;
}

Essa função faz M tentativas que chamamos de sondagem de encontrar uma célula boa (na linha * do código). A busca fracassa somente se a tabela tb estiver cheia. Nesse caso, a execução da função é abortada. (Teria sido melhor redimensionar a tabela tb e continuar trabalhando). Suponha que por exemplo o tamanho M de disperção é 10 ( um número não primo para ficar mais simples). Suponha também que hash(ch, M) é definido como ch%M. Imaginando o seguinte fluxo de entrada: 333 336 1333 333 7777 446 556 999, então o estado final da tabela de dispersão tb[0...9] será o seguinte: 

chave   ocorr
  999       1
   -1       0
   -1       0
  333       2
 1333       1
   -1       0
  336       1
 7777       1
  446       1
  556       1

. Desempenho: No pior caso, a função de espalhamento hash leva todas as chaves na mesma posição da tabela de dispersão e portanto as chaves ocupam células consecutivas da tabela.  Nesse caso, o desempenho não é melhor que o do algoritmo 2:  cada execução de contabiliza consome tempo proporcional ao número de chaves já lidas do fluxo de entrada. 

 No caso médio, típico de aplicações práticas, o desempenho de contabiliza é muito melhor. Se mais da metade das células da tabela de dispersão estiver vaga (como acontece se usarmos redimensionamento) e a função hash espalhar bem as chaves pelo conjunto 0...M-1, uma execução da função contabiliza não precisará fazer mais que algumas poucas sondagens para encontrar uma célula "boa". Assim, o consumo de tempo de uma execução de contabiliza será praticamente independente do número de chaves já lidas. 


*/