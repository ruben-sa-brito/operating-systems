# Chapter 3 - Gerenciamento de Memória

This file contains the solutions to the exercises from Chapter 3 of the book **"Operating Systems"** by Andrew S. Tanenbaum.

---

## Question 1

Na figura 3.3, os registradores-base e os registradores-limite contêm o mesmo valor, 16.384. Isso apenas por acaso, ou eles são sempre os mesmos? Se for apenas por acaso por que eles são iguais nesse exemplo?

**Answer:**

Nem sempre são iguais, na verdade o que acontece é que o registrador-limite é o valor do tamanho da memória que o processo tem, 16.384 do registrador-base representa o endereço base do processo, e 16.384 do registrador-limite representa o tamanho do limite, entao o endereço limite seria 32764.

## Question 2

Neste problema, você deverá comparar o armazenamento necessário para controlar a memória disponível usando um mapa de bits versus uma lista encadeada. A memória de 8 GB é alocada em unidades de n bytes. Para a lista encadeada, suponha que a memória consista em uma sequência alternada de segmentos e lacunas, cada um com 1MB. Suponha também que cada nó na lista encadeada precisa de um campo de endereço de memória com 32 bits, outro de comprimento com 16 bits e um campo de próximo nó com 16 bits. Quantos bytes de armazenamento são necessários para cada método? Qual é o melhor?

**Answer:**

1. Uma memória de 8 GB teria aproximadamente 8.000 bits(1.000 bytes, usando base decimal) de tamanho de mapa de bits se fosse dividida em unidades de 1mb, ja na lista encadeada como precisariamos de 8000 nós para compor toda a memoria, cada nó vai consumir 64 bits para o campo de endereço, comprimento e endereço do próximo nó, totalizando 512.000 bits(64.000 bytes) aqui vemos uma vantagem do mapa de bits, ele consome bem menos espaço. Entretanto percorrer um mapa de bits em procura do espaço adequado para o processo é mais custoso que uma lista encadeada, a lista encadeada trabalha com intervalos(ex: o endereço 3000 ao 4000 está vazio) facilitando o processamento. 
2. A escolha entre mapa de bits e lista encadeada depende do ambiente. Mapa de bits podem ocupar menos espaço mas são lentos para operações de busca e inserção, lista encadeadas são mais rapidas, mas tem problemas de fragmentação pois trabalham com intervalos.

## Question 3

Considere um sistema de troca no qual a memória consiste nos seguintes tamanhos de lacunas na ordem da memória: 10 MB, 4 MB, 20 MB, 18 MB, 7 MB, 9 MB, 12 MB e 15 MB. Qual lacuna é pega para sucessivas solicitações de segmentos de:

a. 12 MB
b. 10 MB
c. 9 MB

para o algoritmo primeiro encaixe? Agora repita a questão para melhor encaixe, pior encaixe e próximo encaixe.

**Answer:**

Primeiro encaixe, esse algorimo funciona escolhendo o primeiro endereço que couber:
a: 20Mb(terceiro espaço), b: 10MB (primeiro espaço), c: 10 MB (sexto espaço)

Melhor encaixe, escolhe a menor espaço que couber:
a: 12MB (sétimo espaço), b: 10mb (primeiro espaço), c:9mb (sexto espaço)

Pior encaixe, escolhe o maior espaço que couber:
a: 20mb (terceiro espaço), b: 18mb (quarto espaço), c: 15mb (oitavo espaço) 

Próximo encaixe, funciona semelhante ao 'primeiro encaixe' mas começando a busca a partir da posição que parou na busca anterior:
a: 20bm (terceiro espaço), b: 18mb (quarto espaço), c: 9mb (sexto espaço)

## Question 4

Os primeiros gerenciadores de sobreposição (overlay) e seções de sobreposição foram escritos manualmente pelos programadores. Em princípio, isso poderia ser feito automaticamente pelo compilador para um sistema com memória limitada? Caso pudesse, como isso seria feito e quais seriam as dificuldades?

**Answer:**

Bom, acredito que na teoria um compilaodr poderia ter essa funcionalidade, mas teriamos uma certa duplicidade(todos compiladores teriam de resolver o mesmo problema), alem da complexidade ser muito maior do que um sistema de memoria virtual, o SO detem o controle do hardware tornando o trabalho mais plausível e unificando a solução para todos os programas e compiladores, a soluçao via memória virtual é mais contundente.


## Question 5

Em que situações, na computação atual, um sistema de memória no estilo de sobreposição poderia ser eficaz, e por quê?

**Answer:**

Em algumas situações o overlay ainda é util, por exemplo em sistemas embarcados, onde se tem acesso ao hardware e recursos limitados o overlay pode aumentar o desempenhor e economizar recursos do so, em jogos onde o custo para carregar todo o programa seria muito alto pode-se utilizar tecnicas semelhantes ao overlay. Sofwares grandes onde é preciso otimizar o tempo de carregamento como editores de video e processamento gráfico, etc.

## Question 6

Qual é a diferença entre um endereço físico e um endereço virtual?

**Answer:**

O endereço virtual é uma abstração criada por sistemas operacionais para lidar com múltiplos processos e com a quantidade limita de memória(assim é possivel lidar com programas que são grandes demais para caber na memória), já a memoria física é o espaço real e físico que o sistema operacional tem acesso.

## Question 7

Para cada um dos endereços virtuais decimais seguintes, cálcule o número da página virtual e o deslocamento para uma página de 4KB e uma de 8KB: 20.000, 32.768, 60.000.

**Answer:**

endereço 20.000: 20000 // 4000 = 5, número de pagina 5
                 20000 % 4000 = 0, deslocamento 0
                 20000 // 8000 = 3, número de pagina 3
                 20000 % 8000 = 4000, deslocamento 4000

endereço 32.768: 32.768 // 4000 = 8, número de pagina 8
                 32.768 % 4000 = 768, deslocamento 768
                 32.768 // 8000 = 4, número de pagina 4
                 32.768 % 8000 = 768, deslocamento 768

endereço 60.000: 60.000 // 4000 = 15, número de pagina 15
                 60.000 % 4000 = 0, deslocamento 0
                 60.000 // 8000 =7, número de pagina 7
                 60.000 % 8000 = 4000, deslocamento 4000

## Question 8

Usando a tabela de página da figura 3.9, dê o endereço físico correspondendo a cada um dos endereços virtuais a seguir:

a) 2.000
b) 8.200
c) 16.536

**Answer:**

a) Esse endereço tem um deslocamento de 2000 e está mapeado para segunda página da memória física ou seja 8192 + 2000 = 10192, endereço físico: 10192

b) Endereço localizado na 2 página, deslocamento 8200 - 8192 = 8, endereço virtual mapeado para 6 pagina física, entao endereço fisico: 24576 + 8 = 24584.

c) Endereço localizado na 4 pagina virtual, deslocamente  16536 - 16384 = 152, endereço virtual mapeado para 4 pagina física, entao o endereço físico é: 16384+152 = 16536.

## Question 9

Que tipo de suporte de hardware é necessário para uma memória virtual paginada funcionar?

**Answer:**

É necessario algum dispositivo para mapear cada pagina de endereço virtual para pagina física correspondente, esse mecanismo é conhecido como MMU(Memory Management Unit) , a mmu pode ser uma parte do chip da CPU o que geralmente acontece, mas tambem pode ser um chip separado(como era no passado).

## Question 10

Considere o programa C a seguir:
int X[N];
int step = M; /* M e uma constante predefinida */
for (int i = 0; i < N; i += step) X[i] = X[i] + 1;

a) Se esse programa for executado em uma máquina com um tamanho de página de 4 KB e um TLB de 64 endereços, quais valores de M e N causarão uma falta de TLB para cada execução do laço interno?
b) Sua resposta no item (a) seria diferente se o laço fosse repetido muitas vezes? Explique.

**Answer:**

a) Para qualquer valor valido de N e M irá causar falta de TLB pois o tlb só é acionado quando o programa solicita o acesso a pagina.

b) Para multiplas execuções do mesmo laço a situação muda pois as ultimas paginas serão salvas no TLB e na segunda execução elas não causaram falta de pagina, mas caso o valor de N seja maior que 65536 que é o limite do TLB dado 4Kb por pagina (e 4 bytes por inteiro) na segunda execução é possivel ocorrer falta de tlb pois somente os ultimos endereços acessados serão salvos não havento espaço suficiente para todos inteiros de X no TLB.

## Question 11

O montante de espaço de disco que deve estar disponível para armazenamento de páginas está relacionado ao número máximo de processos, n, ao número de bytes no espaço de endereçamento virtual, v, e ao número de bytes de RAM, r. Dê uma expressão para o pior caso de exigências de espaço em disco. Esse montante é realista?

**Answer:**

Vamos atribuir valores as variaveis para expressar uma situação hipotética:
n = 10
v = 64KB
r = 32kb

Se todos os processos usarem toda memória virtual as paginas que não estão na memória física precisariam estar no armazenamento não volátil ou seja n*v = 640KB de espaço em disco. Levando em conta as limitações é bem provável que esse valor é alto demais, tambem é bem improvável que todos os processos usem toda memória virtual.

## Question 12

Se uma instrução leva 2ns e uma falta de página leva n ns adicionais, dê uma fórmula para o tempo de instrução efetivo se as faltas de página ocorrerem a cada k instruções.

**Answer:**

Tempo de instrução = 2 + n/k

## Question 13

Suponha que uma máquina tenha endereços virtuais de 48 bits e endereços físicos de 32 bits.

a) Se as páginas têm 4KB, quantas entradas há na tabela de páginas se ela tem apenas um único nível?

b) Suponha que esse mesmo sistema tenha um TLB com 32 entradas. Além disso, suponha que um programa contenha instruções que se encaixam em uma página e leia sequencialmente elementos inteiros longos de um conjunto que compreende milhares de páginas. Quão efetivo será o TLB para esse caso?

**Answer:**

a) Na tabela virtual seria 2⁴⁸ / 4KB ou seja 2⁴⁸ / 2¹² = 2³⁶ entradas na tabela virtual
na tabela fisica seria 2³² / 2¹² = 2²⁰

b) Levando em consideração que o TLB sempre vai atualizar as paginas novas que são requisitadas e o programa em questão está sempre solicitando novo conteudo de memória o tlb nesse caso não será muito util. O TLB ajuda quando as paginas são acessadas frequentemente.

## Question 14

Você recebeu os seguintes dados a respeito de um sistema de memória virtual:

a) O TLB pode conter 1024 entradas e pode ser acessado em 1 ciclo de relógio (1ns).
b) Uma entrada da tabela de página pode ser encontrada em 100 ciclos de relógio ou 100ns.
c) O tempo de substituição de página médio é 6ms

Se as referencias de página são manuseadas pelo TLB 99% das vezes e apenas 0,01% leva a uma falta de página, qual é o tempo de tradução de endereço eficiente?

**Answer:**

Com os dados fornecidos podemos supor que 99% das vezes a pagina esta no TLB, 0,99% é soft miss, e 0,01% hard miss (a pagina não está na memória física).
Ou seja com 100 solicitações de pagina:
99 delas vao estar na tlb levando 1ns cada ou seja 99ns
0,99% é soft miss levando 100ns, ou seja 99ns
0,01% é hard miss levando 6ms(6000000ns), ou seja 6000000*0.01 = 60000ns

somando e fazendo a média teremos: 60198/100 = 601.98ns 

Obs: É interessante notar que mesmo com a probabilidade baixa de uma hard miss o tempo que leva para carregar a pagina é tão alto que aumenta muito a média de tempo, comprometendo o desempenho do sistema.

## Question 15

Alguns sistemas operacionais, particularmente o Linux, têm um único espaço de endereçamento virtual, com algum conjunto de endereços designado para o núcleo e outro conjunto de endereços designado para processos de espaço de usuário. O núcleo do Linux de 64bits tem suporte para, no máximo, 4.194.304 processos na tabela de processos, e o núcleo é alocado em metade do espaço de endereçamento virtual. Se o espaço de endereçamento de memória for dividido igualmente entre todos os processos, quanto espaço de endereçamento virtual seria alocado para cada processo no mínimo, com o número máximo de processos em execução.

**Answer:**

Se metade dos endereços são para o núcleo entao 2⁶⁴/2 = 2⁶³, entao é so dividir essa valor para todos os processos 2⁶³/4.194.304 => 2⁶³/2²² = 2⁴¹ de endereços para cada processo.

## Question 16

O núcleo do Linux de 32 bits suporta no máximo 32.768 processos na tabela de processos, e o núcleo recebe 1.073.741.824 (1 GiB) do espaço de endereçamento virtual. Se o espaço de endereçamento de memória for dividido igualmente entre todos os processos, quanto espaço de endereçamento virtual no mínimo seria alocado para cada processo, com o número máximo de procesos em execução?

**Answer:**
1.073.741.824 = 2³⁰ para o kernel
sobrando 3*2³⁰ para os processos 
com 32.768 processos teriamos: 3*2³⁰/2¹⁵ = 3*2¹⁵ por processo.

## Question 17

A seção 3.3.4 declara que o Pentium Pro ampliou cada entrada na hierarquia da tabela de páginas a 64 bits, mas ainda assim só conseguia endereçar 4 GB de memória. Explique como essa declaração pode ser verdadeira quando as entradas da tabela de páginas têm 64 bits.

**Answer:**

Porque nem todos 64 bits sao usados apenas para endereço de memória, apenas parte dos bits são destinados a isso, eram usado uma tabela de ponteiro de diretório de página que continha 4 entradas, que apontavam pra uma entrada de diretório de pagina, contendo 512 diretórios de páginas cada e 512 em cada tabela de páginas totalizando 1048576 endereços, resultando em 4GB.

## Question 18

Um computador com um endereço de 32 bits usa uma tabela de página de dois níveis. Endereços virtuais são divididos em um campo de tabela de página de nível superior de 9 bits, um campo de tabela de páginas de segundo nível de 11 bits e um deslocamento. Qual é o tamanho das paginas e quantas existem no espaço de endereçamento.

**Answer:**

32 - (9 + 11) = 12 bits de offset ou seja cada pagina tem 4KB

2⁹ * 2¹¹ = 2²⁰ => 1048576 páginas possíveis

## Question 19

Suponha que um endereço virtual de 32 bits seja desmembrado em quatro campos, a, b, c e d. Os três primeiros são usados para um sistema de tabela de páginas de três níveis. O quarto campo, d, é o deslocamento. O número de páginas depende dos tamanhos dos quatro campos? Se não, quais importam e quais não importam.

**Answer:**

Sim a quantidade de paginas depende da distribuição desses bits, por exemplo, a quantidade de bits definido no deslocamento vai definir o tamanho da pagina, o restante dos bits serão distribuidos entre a,b e c, o numero de páginas pode ser representado por 2^(32-d).


## Question 20

Suponha que um endereço virtual de 32 bits e páginas de 4KB. O programa e os dados juntos cabem na página mais baixa(0-4095). A pilha cabe na página mais alta. Quantas entradas são necessárias na tabela de páginas se a paginação tradicional (de um nível) for usada? Quantas entradas da tabela de págins são necessárias para a paginação de dois níveis, com 10 bits em cada parte?

**Answer:**

Com páginas de 4KB temos um offset de 12 bits, restando 20 bits para as páginas, como uma fica no topo e outra na mais baixa teriamos um total de 1048576 páginas. Ja em dois níveis nao precisariamos preencher todas as páginas do segundo nível, mas como a região alocada estão muito distantes precisariamos de duas tabelas cada uma com 1024 entradas, dando um total de 1024 de entradas no primeiro nível + 2 tabelas de 1024 entradas de segundo nível, ou seja 3072 entradas.

## Question 21

A seguir há um traço de execução de um fragmento de um programa para um computador com páginas de 512 bytes. O programa está localizado no endereço 1.020, e seu ponteiro de pilha está em 8192 (a pilha cresce em direção a 0). Dê a sequencia de referências de página geradas por esse programa. Cada instrução ocupa 4 bytes (1 palavra) incluindo constantes imediatas. Tanto as referências de instrução quanto as de dados são contadas na cadeia de referência.

    Carregue palavras 6.144 no registrador 0;
    Empilhe uma rotina em 5.120, empilhando o endereço de retorno;
    Subtraia a constante imediata 16 do ponteiro de pilha; 
    Compare o parâmetro real com a constante imediata 4; 
    Salte se for igual a 5.152.

**Answer:**

Instrução 1 está no endereço 1020 → página 1020//512 = 1
Ler um dado do endereço 6144 → página 6144//512 = 12
Chamar rotina em 5120 → 10
Aqui ele acessará o ponteiro de pilha localizado em 8192, acessando a pagina 16, e entao vai subtrair o valor do endereço 8192 - 16 = 8176
Parametro real: 8176//512 = 15
Se o parametro for igual acessar pagina localizada em 5152, 5152//512 = 10

## Question 22

Um computador cujos processos têm 1024 páginas em seus espaços de endereçamento mantém suas tabelas de páginas na memória. O custo adicional exigido para ler uma palavra da tabela de páginas é 5ns. Para reduzir esse custo, o computador tem um TLB, que contém 32 pares (página virtual, quadro de página física), e pode fazer uma pesquisa em 1ns. Qual a razão de acerto é necessário para reduzir o custo adicional médio para 2ns?

**Answer:**
x = hit na tlb
y = acesso a tabela de paginas

(x + y*6)/(x+y) = 2

vamos supor que sejam feitos 3 acessos a tabela de paginas (a pagina nao está na tlb), então:

x + 3*6/(x + 3) = 2
x + 18 = 2x + 6
x + 12 = 2x
x = 12

entao a razão é 12/3 = 4, ou seja é necessário 4 vezes mais acesso ao TLB para que o tempo médio seja de 2ns

## Question 23

O VAX foi o computador que dominava os departamentos universitários de ciência da computação durante a maior parte da década de 1980. O TLB no VAX não cotinha um bit R. Apesar disso, pessoas supostamente inteligentes continuaram comprando VAXes. Isso foi apenas devido à sua lealdade ao predecessor do VAX, o PDP-11, ou havia algum outro motivo para eles aguentarem isso por anos?

**Answer:**

Apesar da falta do bit R, as pessoas podeiam continuar escolhendo o VAX talvez por outros fatores alem de lealdade, o processador do VAX utilizava arquitetura CISC o que facilitava a escrita de codigo e programaçao, criaçao de compiladores, etc. Podia haver compatibilidade com softwares escritos no seu predecessor PDP-11, sistemas operacionais ja consolidados pra epoca, custo/benefício. etc.

## Question 24

Uma máquina tem endereços virtuais de 48 bits e endereços físicos de 32 bits. As páginas têm 8KB. Quantas entradas são necessárias para uma tabela de páginas linear de um único nível?

**Answer:**

Com 8KB por pagina precisaremos de 13 bits para deslocamento, sobrando 35 bits para endereçamento, ou seja 34359738368 endereços, um numero bastante alto levando em conta que cada processo precisaria alocar essa quantidade de endereços, torna-se justificável o uso de tabelas de multinível.


## Question 25

Um computador com uma página de 8KB, uma memória principal de 256 KB e um espaço de endereçamento virtual de 64GB usa uma tabela de página invertida para implementar sua memória virtual. Qual tamanho deve ter a tabela de espalhamento (hash) para assegurar um comprimento médio da lista encadeada por entrada da tabela menor que 1? Presuma que o tamanho da tabela de espalhamento seja uma potência de dois.

**Answer:**

256/8 = 32 paginas na tabela de paginas invertidas

32/x < 1 ou seja a tabela de espalhamento tem que ter um tamanho maior que 32, o proximo numero potencia de 2 é o 64. 

## Question 26

Um estudante em um curso de projeto de compiladores propõe ao professor escrever um compilador que produzirá uma lista de referências de páginas a serem usadas para implementar o algoritmo ótimo de substituição de página. Isso é possível? Por quê? Existe algo que poderia ser feito para melhorar a eficiência da paginação em tempo de execução?

**Answer:**

O algoritmo ótimo de substituição de página exige saber o futuro exato das referências de memória, mas o compilador não tem como prever isso, porque os acessos reais dependem da entrada do usuário, do fluxo de execução dinâmico, alocação dinâmica, chamadas de biblioteca, threads, entre vários outros fatores que só acontecem em tempo de execução. O compilador não está muito melhor do que o SO ele não possui essas informações e ainda tem a desvantagem de nao conhecer os outros processos que estão em execução, alem de que cada compilador teria que desenvolver a mesma solução, resumindo, melhor deixar essa tarefa para o sistema operacional. 
Talvez o projetista do software tenha mais informações a respeito de quais paginas serão mais utilizadas e quais podem ser descartadas, uma possibilidade de melhoria de eficiencia da paginação seria utilizar informaçoes fornecidas pelo projetista de software para melhorar os algoritmos de substituição.

## Question 27

Suponha que a série de referências de páginas virtuais contenha repetições de longas sequências de referências de página aleatória. Por exemplo, a sequência: 0, 1, ... , 511, 431, 0, 1, ... , 511, 332, 0, 1, ... consiste em repetições da sequência 0, 1, ... 511 seguida por uma referência aleatória às páginas 431 e 332

a) Por que os algoritmos de substituição padrão (LRU, FIFO, relógio) não são eficazes ao lidar com essa carga de trabalho para uma alocação de páginas que é menor do que o comprimento da sequência?
b) Se fossem alocados 500 quadros de páginas para esse programa, descreva uma abordagem de substituição de página que teria um desempenho muito melhor que os algoritmos LRU, FIFO ou de relógio.

**Answer:**

a) LRU → elimina a página que não foi usada a mais tempo, com a sequencia ...0, 1, ... , 511 ao chegar a pagina 431 o SO pode precisar eliminar uma página ele eliminária a pagina 0 pois é a mais antiga que é justamente a proxima pagina a ser utilizada após a 431. Outra situação seria uma substituição apos o 332, ele eliminaria o 431, que seria a proxima referencia aleatoria, tambem nao seria o ideal.

FIFO → Elimina a pagina mais antiga, supondo uma substituição apos a sequencia: 0, 1, ... , 511, 431 ele elimaria a pagina mais antiga que seria o 0, e é justamente a proxima pagina a ser utilizada.

RELÓGIO → O relogio aponta para a pagina mais antiga então teriamos o mesmo problema do LRU, ao guardar a pagina de referencia aleatoria se eliminaria a pagina 0 que é justamente a proxima a ser utilizada.

b) Os melhores algoritmos para esse tipo de caso são os que tem como base o conjunto de trabalho, esses algortimos identificariam um conjunto de trabalho sempre incluindo os elementos 431 e 332, reduzindo as page faults.

## Question 28

Se a substituição de páginas FIFO é usada com quatro quadros de páginas e oito páginas, qunatas faltas de páginas ocorrerão com relação à sequencia 0172327103 se os quatro quadros estiverem inicialmente vazios? Agora repita esse problema pra LRU.

**Answer:**

O algoritmo FIFO remove a primeira pagina adicionada na lista, seguindo a sequencia 0-page fault, 1-page fault, 7-page fault, 2-page fault, 3-page fault(remove a pagina 0), 2-page hit, 7- page hit, 1-page hit, 0-page fault (remove pagina 1), 3-page hit. Total de 6 faltas de paginas com o algoritmo FIFO.

Ja o algoritmo LRU elimina a página que está ha mais tempo sem ser usada, vamos ver como ele se comporta nesse caso:
0-page fault, 1-page fault, 7-page fault, 2-page fault, 3-page fault(remove a pagina 0), 2- page hit, 7-page hit, 1-page hit, 0-page fault (remove a pagina 3, pois está a mais tempo sem ser usada), 3 - page fault (remove a pagina 2). Total de 7 faltas de paginas com o algoritmo LRU.

## Question 29

Considere a sequência de páginas da Figura 3.15(b). Suponha que os bits R para as páginas B até A sejam 11011011, respectivamente. Que página será removida pelo algoritmo da segunda chance?

**Answer:**

O algoritmo segunda chance verifica o bit R, se for 1 significa que a pagina foi usada recentemente então ele modifica o bit pra 0 e o coloca no final da fila, seguindo a sequencia o pagina removida será a terceira pagina, ou seja a página D.

## Question 30

Um pequeno computador em um cartão inteligente tem quatro quadros de páginas. Na primeira interrupção de relógio, os bits R são 0111 (página 0 é 0, o resto é 1). Nas interrupções de relógio subsequentes, os valores são 1011, 1010, 1101, 0010, 1010, 1100 e 0001. Se o algoritmo de envelhecimento for usado com um contador de 8 bits, dê os valores dos quatro contadores após a ultima interrupção.

**Answer:**
pagina 0 - 00000000 → 10000000 → 11000000 → 11100000 → 01110000 → 10111000 → 11011100 → 01101110  
pagina 1 - 10000000 → 01000000 → 00100000 → 100100000 → 01001000 → 00100100 → 10010010 → 01001001
pagina 2 - 10000000 → 11000000 → 11100000 → 01110000 → 10111000 → 11011100 → 01101110 → 00110111
pagina 3 - 10000000 → 11000000 → 01100000 → 10110000 → 01011000 → 10101100 → 11010110 → 11101011

## Question 31

Dê um exemplo simples de uma sequência de referências de páginas onde a primeira página selecionada para a substituição será diferente para os algoritmos de substituição de página LRU e do relógio. Suponha que três quadros sejam alocados a um processo, e a sequencia de referências contenha números de páginas do conjunto 0, 1, 2, 3.

**Answer:**

No algoritmo de relógio as paginas são inseridas no relógio na ordem em que são colocadas na memória, semelhante ao FIFO, o relogio começa apontando para a primeira página inserida (ou seja mais antiga) se o bit for 0 a pagina é substituida se não o bit é limpo e o relogio avança uma posição. Ja no LRU o que importa é quanto tempo a pagina está sem ser usada. Vamos supor a seguinte sequencia de paginas 0 → 1 → 0 → 2 → 1 → 0 → 0 → 0 → 0 →  2 → 0 → 2 → 2 → 2 → 3, o relogio irá apontar para a pagina 0, mas o bit é 0 suponto que está a um tempo sem ser usada e o bit tenha sido limpo, e apesar de ter sido a pagina mais usada levando a sequencia inteira em consideração, ela será removida, enquanto o LRU irá remover a pagina que está a mais tempo sem ser referenciada, ou seja a pagina 1.

## Question 32

Um estudante afirmou que "em suma, os algoritmos básicos de substituição de página (FIFO, LRU, ótimo) são idênticos, exceto pelo atributo usado para selecionar a página a ser substituída".

**Answer:**

a) Qual é esse atributo para o algoritmo FIFO? E para o LRU? E para o algoritmo ótimo?

FIFO - O atributo seria a idade da pagina, vai utilizar a ordem de inserção na fila de paginas, removendo o primeiro elemento da fila, ou seja a página mais antiga.
LRU - utiliza o atributo de referencia de página, armazenando um valor indicando quando foi a ultima vez que aquela pagina foi utilizada, eliminando a pagina que está ha mais tempo sem ser referenciada.
Ótimo - algorítmo ótimo é apenas teórico, haveria um rótulo(este é o atributo) em cada página, indicando por quantas instruções aquela página não vai ser usada(ou seja seria um algorimto capaz de prever o futuro), assim, a página com maior rótulo seria removida.

b) Dê o algoritmo genérico para esses algoritmos de substituição de página.

Uma pagina p é referenciada: 
Situação 1 - p ja esta na memoria, entao atualize o atributo de p, e continue.
Situação 2 - p nao está na memoria física, verifique se há espaço disponivel, coloque p em um quadro livre e inicie seu atributo, continue.
Situação 3 - p não esta na memoria e nao existe espaço livre, ocorre uma page fault, então será necessario remover uma página, com base no atributo escolhido como criterio de seleção substitua a página correspondente por p e inicialize o atributo de p.

## Question 33

Quanto tempo é necessário para carregar um programa de 64KB de um disco cujo tempo médio de procura é 5ms, cujo tempo de rotação é 5ms e cujas trilhas contêm 1MB

a) para um tamanho de página de 2KB?
b) para um tamanho de página de 4KB?

As páginas estão espalhadas aleatoriamente em torno do disco e o número de cilindros é tão grande que a chance de duas páginas estarem no mesmo cilindro é desprezível.

**Answer:**

O disco leva 5ms para encontrar o cilindro (trilha) e mais 2,5ms para encontrar o setor dentro da trilha(vamos supor aqui um tempo médio), ou seja 7,5ms para cada pagina(desprezando o tempo de transferencia). 

a) 64/2 = 32 páginas -> 32 * 7,5 = 240ms
b) 64/4 = 16 páginas -> 16 * 7,5 = 120ms

## Question 34

Considere o algoritmo de substituição de página FIFO e aseguinte sequência de referência:
1 2 3 4 1 2 5 1 2 3 4 5
Quando o número de quadros de página aumenta de três para quatro, o número de faltas de página diminui, permanece o mesmo ou aumenta? Explique sua resposta.

**Answer:**

Para ajudar um pouco a visualizar o comportamento do algoritmo criei um pequeno script escrito em python disponível em [faults_counter.py](./codes/chapter_3/faults_counter.py). 
Inesperadamente, nessa sequência de referências, usar quatro quadros de página resulta em mais page faults do que usar três.
O que percebi é que, com 3 quadros, as páginas 1 e 2 são removidas e logo reinseridas no início da fila, o que as coloca em uma posição favorável, já que elas serão utilizadas novamente logo em seguida.
Já com 4 quadros, essas páginas acabam sendo removidas uma após a outra exatamente no momento em que serão referenciadas novamente, resultando em um número maior de page faults.

## Question 35

Um computador tem quatro quadros de páginas. O tempo de carregamento, o tempo de último acesso e os bits R e M para cada página são como os mostrados a seguir (os tempos estçao em interrupções de relógio):

| Página  | Carregado| Última referência | R | M |
|:--------|:---------|:------------------|:--|:--|
| 0       | 126      | 280               | 1 | 0 |
| 1       | 230      | 265               | 0 | 1 |
| 2       | 140      | 270               | 0 | 0 |
| 3       | 110      | 285               | 1 | 1 |



**Answer:**