# Chapter 1 - Introduction

This file contains the solutions to the exercises from Chapter 1 of the book **"Operating Systems"** by Andrew S. Tanenbaum.

---

## Exercise 1

**Question**
Quais são as duas principais funções de um sistema operacional?

**Answer:**
Um sistema operacional está relacionado principalmente a duas funções: 
1. Abstração: Fornecer a programadores de aplicativos um conjunto de recursos abstratos limpo em vez de recursos confusos de hardware. Pode-se dizer que o hardware é um ambiente complicado e dificil de manipular, caso os programadores precisassem tambem lidar com as complexidades de hardware explicitamente é provavel que os produtos de software fossem muito mais escassos do que são hoje em dia.
2. Gerenciar recursos: sistemas operacionais modernos permitem que vários programas estejam na memoria e sejam executados ao mesmo tempo. É trabalho do sistema operacional controlar o acessos a estes recursos pelos diversos programas e processos.

## Exercise 2

**Question**
O que é multiprogramação?

**Answer:**
Quando uma tarefa faz uma pausa para esperar por outra operação de E/S, a CPU tambem fica ociosa até o termino. Para algumas tarefas esse tempo nao era muito relevante, mas para outras isso poderia representar cerca de 80 a 90% do tempo total. A multiprogramação surgiu para resolver esse problema, ela consiste basicamente em utilizar esse tempo ocioso da CPU para executar outros processos.

## Exercise 3

**Question**
Na Seção 1.4, são descritos nove tipos diferentes de sistemas operacionais. Liste as possíveis aplicações para cada um desses sistemas.

**Answer:**
1. Sistemas operacionais de computadores de grande porte:  Esses são sistemas desenvolvidos para mainframes, eles diferem de computadores pessoas
em termos de processamento, atualmente esses computadores estão retornando como servidores sofisticados da web, como sites de comercio eletrônico
em larga escala e para operações bancarias, reservas em companhias aéreas e servidores para transações entre empresas.
2. Sistemas operacionais servidores: um nível abaixo dos mainframes, eles servem computadores pessoais por meio de uma rede, permitem que os usuários
compartilhem recursos de hardware software. Servidores podem fornecer serviços de impressão, de arquivo, de banco de dados ou de web.
3. Sistemas operacionais de computadores pessoais: São utilizados pelos usuários comuns, seu trabalho é propiciar um bom ambiente para um único usuário
são amplamente utilizados para processamento de textos, planilhas e acesso a internet, sistemas operacionais comuns nessa categoria: Windows 11, macOS, Linux e FreeBSD.
4. Sistemas operacionais de smartphones e computadores portáteis: Sistema operacionais destinados a dispositivos que podem ser operados
segurando na mão como smartphones e tablets, esse mercado é dominado por sistemas como o Android da google e o IOS da apple.
5. Sistemas operacionais embarcados: Sistemas relacionados a internet das coisas que compreende bilhões de dispositivos fisicos com sensores
exemplos: refrigeradores, termostatos, sensores de movimento de câmera, e tambem dispositivos que nao precisam se conectar a uma rede como fornos micro-ondas e máquinas de lavar.
6. Sistemas operacionais de tempo real: São sistemas que tem o fator tempo como determinante, exemplos: um robo soldador de uma linha de montagem de veiculos que precisa executar sua ação 
no tempo correto ou o veiculo nao será montado adequadamente, muitos desses sistemas são encontrados no controle de processos industriais como na aviônica, industria militar e semelhantes.
existe tambem os sistema de tempo real nao crítico são sistemas que ainda dependentes do tempo em um cenário ideal, mas que são mais tolerantes a falhas do mesmo, exemplos: multimídia ou audio digital pertencem a essa categoria.
7. Sistemas operacionais de cartões inteligentes: São dispositivosdo tamanho de um cartao de credico que contem uma CPU. Muitos deles tem funções bem especificas
e limitadas como pagamentos eletrônicos, mas outros podem realizar múltiplas funções.

## Exercise 4

**Question**
Para usar a memória cache, a memória principal é dividida em linhas de cache, em geral com 32 a 64 bytes de comprimento.
Uma linha inteira armazenada em cache de uma só vez. 
Qual a vantagem de armazenar uma linha inteira em vez de um único byte ou palavra de cada vez?

**Answer:**
Com linhas de cache reduz o número de consultas pois não é necessario fazer requisições para cada palavra ou byte, e geralmente
programas utilizam endereços que estão mais proximos entao a probabilidade de dados contíguos nas memorias serem necessarios é maior, aumentando a eficencia do sistema.


## Exercise 5

**Question**
O que é spooling? Você acredita que os computadores pessoais avançados terão o spooling como recurso padrão no futuro?

**Answer:**
Spooling é uma tecnica usada por sistemas operacionais para otimizar a execução de terefas em dispositivos perifericos, as tarefas
podem ser armazenadas em um local temporário e assim o processador pode continuar seu trabalho em outras tarefas sem precisar esperar que a
terefa seja concluida. É bem provavel que o spooling continue sendo uma funçao necessaria em sistemas operacionais pois os dispositivos trabalham
em velocidades diferentes, uma impressora por exemplo é bem mais lenta para concluir seu trabalho, assim o uso do spooling é necessario para otimizar o sistema.

## Exercise 6

**Question**
Nos primeiros computadores, cada byte de dados lido ou escrito era 
gerenciado pela CPU (i.e., não havia DMA). Quais as implicações isso tem para a multiprogramação.

**Answer:**
O problema desse tipo de abordagem era que a CPU ficava ociosa de 80-90% de tempo pois os processos de E/S 
são muito lentos, a CPU precisava esperar pela conclusão deles para iniciar uma nova tarefa, com a multiprogramação
o uso da CPU se tornou mais eficiente pois o sistema era capaz de executar outra tarefa ao mesmo tempo do processo de E/S.

## Exercise 7

**Question**
Por que o conceito de tempo compartilhado não foi tão disseminado nos computadores de segunda geração?

**Answer:**
A segunda geração era composta por computadores de grande porte(mainframes), que ficavam isolados em grandes salas regrigeradas
com equipes de operadores profissionais para operá-las. Apenas grandes corporações ou importantes agencias do governos ou universidades conseguiam pagar por seu alto valor.
Esses computadores eram basicamente utilizados para cálculos científicos e de engenharia, para solucionar equações diferenciais que geralmente ocorrem
na física e na engenharia, ou seja a prioridade era o tempo de processamento e não a E/S, reduzindo a preocução com o tempo compartilhado da CPU naquele contexto.

## Exercise 8

**Question**
Instruções relacionadas ao acesso a dispositivos de E/S são tipicamente instruções privilegiadas, 
isto é, podem ser executadas em modo núcleo
, mas não em modo usuário. Dê uma razão por que essas instruções são privilegiadas. 

**Answer:**
O que sei até o momento, e com base nas informações disponibilizadas no livro, é que drivers para modo usuário
não é algo trivial e a maioria dos sistemas operacionais executam os drivers no modo núcleo (windows e linux), 
atualmente o sistema operacional que opera todos os drivers no modo usuário com maestria é o MINIX 3.

## Exercise 9

**Question**
Uma razão para a adoção inicialmente lenta das GUIs era o custo do hardware necessário para dar suporte a elas. Qaunta RAM 
de vídeo é necessária para dar suporte a uma tela de texto monocromática de 25 linhas X 80 colunas de caracteres? E para um bitmap colorido de 24 bits de 1.024 X 768 pixels?
Qual era o custo dessa RAM em valores de 1980(US$ 5/KB)? Quanto isso custa agora?

**Answer:**
Vamos considerar que cada caractere ocupa, em média 2 bytes. 
Uma tela de texto monocromática com 80 colunas por 25 
linhas contém 2.000 caracteres, o que resulta em 4.000 bytes (ou 3,9 KB, ao dividir por 1.024).
Por outro lado, uma interface gráfica com resolução de 1.024 x 768 pixels 
contém 786.432 pixels. Cada pixel ocupa 24 bits (3 bytes), 
totalizando 18.874.368 bits ou 2.359.296 bytes (aproximadamente 2.303 KB).
Se compararmos os custos em 1980, uma tela de texto custaria 19,5 dólares, 
enquanto a tela gráfica chegaria a incríveis 10.170 dólares — uma diferença substancial, 
o que justifica a preferência pelas telas de texto naquela época.
Hoje, porém, uma memória RAM de 16 GB custa, em média, 40 dólares, 
o que equivale a aproximadamente 2,6*10^-6 (ou 0,0000026 dólares por KB). Assim, o custo de uma tela gráfica moderna 
seria de apenas 0,004 dólares, tornando-o completamente irrelevante nos dias atuais. 
Esse avanço no custo-benefício explica a popularização das interfaces gráficas no presente.

## Exercise 10

**Question**
Há diversos objetos de projeto na construção de um sistema operacional, por exemplo, utilização de recursos, precisão temporal
robustez e assim por diante. Dê um exemplo de dois objetivos de projetos que podem contradizer um ao outro.

**Answer:**
Quando se trata de projetos de software(sistemas operacionais incluidos) é bem comum que alguns requisitos se tornem conflitantes
e o projetista deve decidir qual vai ser a prioridade, por exemplo: Desempenho vs Segurança, Simplicidade vs Funcionalidade, Flexibilidade vs Controle.

## Exercise 11

**Question**
Qual a diferença entre modo núcleo e modo usuário? Explique como ter dois modos ajuda no projeto de sistemas operacionais.

**Answer:**
O modo núcleo é o modo como o sistema operacional opera, nesse modo ele tem acesso completo ao hardware e pode 
realizar qualquer instrução que a máquina for capaz de executar.
 O restante do software é executado no modo usuário, nesse modo apenas um conjunto restrito de instruções está disponível.
O SO possui o controle total da maquina, permitir que outros processos tambem possuam pode comprometer a estabilidade do sistema, programas com bugs ou mal escritos
poderiam sobrescrever ou alterar endereços de memorias associadas a outros processos, alem disso programas maliciosos poderiam se aproveitar dos privilegios para intencinalmente
prejudicar o sistema ou obter algum tipo de vantagem.

## Exercise 12

**Question**
Um disco de 255 GB tem 65.536 cilindros com 255 setores por faixa e 512 bytes por setor. 
Quantos pratos e cabeças esse disco tem? Presumiindo
um tempo de busca de cilindro médio de 11ms, 
atraso rotacional médio de 7 ms e taxade leitura de 100 MB/s, calcule o tempo médio que será necessário
para ler 100 KB de um setor.

**Answer:**
Primeiros vamos calcular quanto cada lado do prato pode armazenar: 65.536 * 255 * 512 = 8.556.380.160 bytes
Agora calculamos a capacidade desse disco em bytes: 255*1024*1024*1024 = 273.804.165.120 bytes
Dividindo a capacidade do disco pelo armazenamento em cada lado e dividindo resultado por dois obtemos o número de pratos: 273.804.165.120 / 8.556.380.160 = 32, 32/2 = 16 pratos
Cada prato possui 2 cabeças entao o numero de cabeças é 32.
Respostas: 16 pratos e 32 cabeças.
Considerando que esses 100KB estejam distribuidos em diversos setores e não somente em um, teriamos 200 setores para acomodar os 100kb,
considerando tambem que ele precisará encontrar o cilindro correspondente de cada setor temos: 200*11 = 2200ms
para cada setor tambem teremos o tempo de atraso rotacional de 7ms: 200*7 = 1400
com uma velocidade de 100mb/s isso significa que para ler 512 bytes de cada setor ele leva aproximadamente 0,005ms: 200 setores * 0,005ms = 1ms
resultado: 2200ms + 1400ms + 1ms: 3601ms
Obs: essa questão está um pouco confusa, ele fala no enunciado que o setor tem 512 bytes, mas no final diz "100KB de um setor"
eu considerei que esses 100KB estão distribuidos em diversos setores de 512 bytes.

## Exercise 13

**Question**
Considere um sistema que tem duas CPUs, cada uma tendo duas threads (hyperthreading). 
Suponha que três programas, P0, P1, P2, sejam iniciados
com tempos de execução de 5, 10 e 20ms, respectivamente. 
Quanto tempo levará para completar a execução desses programas?
Suponha que todos os três programas sejam 100% dependentes da CPU, 
não bloqueiem durante a execução e não mudem de CPU uma vez escolhidos.

**Answer:**
Dois programas serão executados em uma CPU P0 e P1, com tempo total de 15ms, o outro processo P2 será executado na outra CPU
com tempo total de 20ms, totalizando 20ms de tempo de processamento.

## Exercise 14

**Question**
Liste algumas diferenças entre os sistemas operacionais de computador pessoal e sistemas operacionais de mainframe.
**Answer:**
O sistema operacional para computadores de grande porte são orientado a multiprocessamento, a maioria delas exigindo quantidades
prodigiosas de E/S. Ja sistemas operacionais de computador pessoal tem como objetivo proporcionar um bom apoio para um único usuário e não precisam
suportar quantidades exorbitantes de E/S.

## Exercise 15

**Question**
Um computador tem um pipeline com quatro estágios. Cada estágio leva um tempo para fazer seu trabalho, isto é, 1ns.
Quantas instruções por segundo essa máquina consegue executar?
**Answer:**
Se o pipeline tem quatro estágios isso significa que a instrução pode ser dividada em 4 partes, 
e entao 4 instruções podem ser executadas ao mesmo tempo, cada uma em um estágio diferente
1 segundo tem 10^9 ns multiplicando por 4, temos aproximadamente 4 * 10^9 instruçoes por segundo.

## Exercise 16

**Question**
Considere um sistema de computador que tem uma memória cache, memória principal (RAM) e disco,
 e um sistema operacional que usa memória
virtual. São necessários 2 ns para acessar uma palavra da cache. 
10 ns para acessar uma palavra da RAM e 10 ms para acessar uma palavra do disco
. Se o índice de acerto da cache é 95% e o índice de acerto da memória principal
 (após um erro de cache) é 99%, qual é o tempo médio para acessar uma palavra.
**Answer:**
Primeiros convertemos 10 ms em ns para trabalharmos com as mesmas unidades de tempo, 10ms = 1000000ns
95% terão tempo de 2ns = 95, mulitplicando pelo tempo correspondente: 95 * 2ns = 190ns
dos 5%, 99% vao para memória principal = 4,95, multiplicando pelo tempo correspondente: 4,95 * 10ns = 49,5ns
e 1% desses 5% vao para o disco = 0,05,  multiplicando pelo tempo correspondente: 0,05 * 1000000ns = 50000
agora somamos todos os tempos e dividimos por 100 para obter a média: (190+49,5+50.000)/100 = 502,395ns
reposta: tempo médio para acessar uma palavra é de 502,395ns

## Exercise 17

**Question**
Quando um programa de usuário faz uma chamada de sistema para ler ou escrever um arquivo de disco, 
ele fornece uma indicação de qual arquivo ele quer, um ponteiro para o buffer de dados e o contador.
O controle é então transferido para o sistema operacional, que chama o driver apropriado.
Suponha que o driver inicie o disco e termine quando ocorre uma interrupção.
No caso da leitura do disco, obviamente
quem chamou terá de ser bloqueado (pois não há dados para ele).
E quanto a escrever para o disco? Quem chamou precisa ser bloqueado, esperando o término
da transferencia de disco?

**Answer:**
É possivel que um processo que faz apenas a escrita de dados não necessite que esta tarefa seja concluida para continuar sua execução,
mas isso vai depender do processo em si.

## Exercise 18

**Question**
Qual a principal diferença entre uma captura(trap) e uma interrupção?

**Answer:**
Na instrução de captura(trap) um processo precisa de um serviço de sistema então ele precisa passar o controle para 
o sistema operacional que executa em modo núcleo. Já na interrupção um dispositivo periferico realiza a 
chamada ao sistema operacional informando que algo precisa de atenção, como por exemplo o 
término do processo de leitura de dados, para que assim esses dados possam ser entregues 
ao processo que o chamou. Interrupções são muito importantes pois não bloqueiam o sistema 
enquanto este espera por alguma tarefa realizada pelo hardware, o dispositivo informa ao sistema
o momento de término assim não é necessário verificações repetidas.

## Exercise 19

**Question**
Existe alguma razão para que voce quisesse montar um sistema de arquivos em um diretório vazio? Se a resposta for sim, por quê?

**Answer:**
Sim, isso pode ser util para montar sistema de arquivos de dispositivos removiveis, isso facilita as operações neste dispositivo uma vez 
que seu sistema de arquivos estara integrada ao sistema, podendo assim usar as mesmas chamadas de sistema.

## Exercise 20

**Question**
Qual a finalidade de uma chamada de sistema em um sistema operacional?

**Answer:**
Chamadas de sistema abstraem a complexidade do hardware para programas de usuário, 
trata-se de uma interface fornecida pelo sistema operacional,
que facilita a manipulação do hardware. Além de proporcionar mais segurança entre diversos
processos que estão sendo executados no mesmo hardware atraves da camada de gerenciamento do sistema operacional.


## Exercise 21

**Question**
Dê uma razão pela qual montar sistemas de arquivos é uma opção de projeto melhor do que prefixar
nomes de caminho com um nome ou número de unidade.
 Explique por que os sistemas de arquivos são quase sempre montados em diretórios vazios.

**Answer:**
Um disco montado ao sistema de arquivos-raiz pode ser acessado usando o seu caminho do diretório-raiz, sem levar em consideração
em qual unidade de disco ele está. Eles são montados em diretórios vazios para evitar conflitos e problemas com outros arquivos que possam estar naquele local.

## Exercise 22

**Question**
Para cada uma das chamadas de sistema a seguir, dê uma condição que a faça falhar: open, close e lseek.

**Answer:**
open() - tentativa de abrir um arquivo que nao existe no diretorio, outro erro seria tentar abrir um arquivo que o usuario nao possui permissão.
close() - tentativa de fechar um arquivo que nao foi aberto
lseek() - mover o ponteiro para um local que nao existe no arquivo

## Exercise 23

**Question**
Qual tipo de multiplexação (tempo, espaço ou ambos) pode ser usado para compartilhar os seguintes recursos:
CPU, memória, disco/SSD, placa de rede, impressora, teclado e monitor?

**Answer:**
CPU - multiplexação de espaço e tempo
Memória - Multiplexação de espaço e tempo
Disco/SSD - Multiplexação de espaço e tempo
Impressora - Multiplexação de tempo
Teclado - Multiplexação de tempo
Monitor - Ambos

## Exercise 24

**Question**
A chamada count=write(fd, buffer, nbytes);
pode retornar qualquer valor em count além de nbytes? Se a resposta for sim, por quê?

**Answer:**
Sim, o primeiro caso seria o de um erro como por exemplo um erro de permissão, nesse caso write retorna -1
ele tambem pode retornar um valor diferente em um caso onde ele nao consiga escrever todos os dados por alguma razão, como limite de tamanho de arquivo por exemplo.

## Exercise 25

**Question**
Um arquivo cujo descritor é fd contém a sequência de bytes: 2, 7, 1, 8, 2, 8, 1, 8, 2, 8, 4.
 São feitas as seguintes chamadas de sistema:
lseek(fd, 3, SEEK_SET);
read(fd, &buffer, 4);
em que a chamada lseek faz uma busca para o byte 3 do arquivo. O que o buffer contém após a leitura ter sido feita.

**Answer:**
A chamada read vai ler 4 bytes a partir da quarta posiçao pois o ponteiro da posição do arquivo foi modificado pelo
lseek o retorno de read será: 8,2,8,1 

## Exercise 26

**Question**
Suponha que um arquivo de 10MB esteja armazenado em um disco na mesma trilha (trilha 50) em setores consecutivos. 
O braço do disco está atualmente situado sobre trilha número 100. 
Quanto tempo ele levará para ler esse arquivo do disco? Suponha que ele leve em torno de 1ms
para mover o braço de um cilindro para o próximo e em torno de 5 ms 
até que o setor onde o início do arquivo está armazenado
passe sob o cabeça. Suponha também que leitura ocorra a uma taxa de 100MB/s.

**Answer:**
- Para mover o braço para o cilindro correto levara 100-50 = 50ms
- Para posicionar no setor correto: 5ms
- Como o tamanho do arquivo é 10mb a uma taxa de 100MB/s levara 0,1s, precisamos converter para milisegundos: 1000 * 0,1 = 100ms
Tempo total: 50ms + 5ms + 100ms = 155ms

## Exercise 27

**Question**
Qual a diferença essencial entre um arquivo especial de bloco e um arquivo especial de caractere.

**Answer:**
Arquivos essenciais de bloco sao usados para endereçar dispositivos construidos essencialmente em blocos como HDs e SSDs, já arquivos essenciais
de caracteres sao utilizados para modelar dispositivos que utilizam um fluxo de dados para realizar suas funçoes como um impressora, mouse ou teclado.

## Exercise 28

**Question**
No exemplo 1.17, o procedimento de biblioteca é chamado de read e a chamada de sistema em si é chamada read e a 
chamada de sistema em si é chamada read. É fundamental 
que ambos tenham o mesmo nome? Se não, qual é o mais importante?

**Answer:**
Não fundamental, o windows por exemplo desacoplou o procedimento da chamada em si, com isso eles podem alterar as chamadas internamente
sem precisar que os programas clientes sejam modificados uma das vantagens, por outro lado chamadas muito desacopladas podem obscurecer o que de fato está acontecendo.
Então essa questão é subjetiva ao design do sistema operacional.

## Exercise 29

**Question**
O modelo cliente-servidor é popular nos sistemas distribuídos. Ele também pode ser usado em um sistema de computador único?

**Answer:**
Sim, essencialmente o modelo cliente-servidor trata-se de um processo-cliente que constrói uma mensagem 
dizendo o que ele quer e a envia ao processo-servidor, 
o serviço então realiza o trabalho e envia de volta a resposta, 
nada impede que o cliente e o servidor estajam na mesma máquina,
conceitualmente ainda estamos no modelo cliente-servidor.

## Exercise 30

**Question**
Para um programador, uma chamada de sistema parece com qualquer outra
chamada para um procedimento de biblioteca. É importante
que um programador saiba quais procedimentos de biblioteca
resultam em chamadas de sistema? Em quais circunstâncias e por quê?

**Answer:**
Sim é importante pois chamadas que resultam em chamadas de sistemas compromentem o desempenho, se um procedimento
pode ser realizado sem fazer uma chamada de sistema ele será feito no espaço do usuário que por padrão tem um desempenho maior.

## Exercise 31

**Question**
A figura 1.23 mostra que uma série de chamadas de sistema UNIX não possuem equivalentes na API Win32. 
Para cada uma das chamadas listadas como não tendo um equivalente Win32, quais são as consequências para um programador
de converter um programa UNIX para ser executado sob o Windows?
**Answer:**
Fica claro que as chamadas de sistema devem ser convertidas para a do sistema em questão, até mesmo as que tem chamadas semelhantes
ainda possuem parâmetros diferentes forçando o programador modificar o sistema para se adequar. Para aquelas que não possuem correspondente direto
pode ser necessário repensar a lógica do sistema.

## Exercise 32

**Question**
Um sistema operacional portátil é um sistema que pode ser levado de um arquitetura de sistema para outra
sem nenhuma modificação. Explique por que é impraticável construir um sistema operacional que seja completamente portátil;
Descreva duas camadas de alto nível que você terá ao projetar um sistema operacional que seja altamente portátil.

**Answer:**

As camadas mais problematicas são as mais baixas, do processador e memória, cada processador 
pode ter conjuntos de instruçoes, chaveamento, endereçamento de memória diferentes etc, o sistema 
operacional precisa lidar com todas essas variantes, há importante citar tambem que um sistema operacional pensado
exclusivamente para um tipo de hardware pode ganhar em eficiencia.
Outras camadas como a de entrada/saida podem ser trabalhadas para incorporar uma grande variedade de dipositivos, sistemas oparacionais modernos
lidam com uma infidade de dispositvos perifericos para garantir a portabilidade.

## Exercise 33

**Question**
Explique como a separação de política e mecanismo ajuda na construção de sistemas operacionais baseados em micronúcleos.

**Answer:**
A ideia do micronúcleo é separar as responsabilidades do núcleo, mecanismo e políticas fazem exatamente isso, os mecanismos
são ações realizadas em baixo nível no modo núcleo, enquanto as políticas definem como essas ações devem ser realizadas
, dessa maneira elas podem ser desacopladas diminuindo o tamanho do nícleo.

## Exercise 34

**Question**
Máquinas virtuais tornaram-se muito populares por diversos motivos. Não obstante, elas tem alguns problemas, cite um.

**Answer:**
O primeiro problema é o desempenho, diferente de um container a máquina virtual executa seu próprio kernel com todas propriedades como gerenciamento de memória
, processamento, disco, etc. Isso a torna mais lenta.

## Exercise 35

**Question**
Veja a seguir algumas questões para praticar conversões:
(a) Quantos segundos há em um microano?
(b) Micrômetros são muitas vezes chamados de mícrons. Qual é o comprimento de um gigamícrons?
(c) Quantos bytes existem em uma memória de 1 TB?
(d) A massa da Terra é de 6.000 yottagramas. Quanto é isso em gramas?

**Answer:**
(a) 1 ano tem: 60x60x24x365 = 31.536.000
    1 microano: 31.536.000 x 10^-6 = 31.536s
(b) 1 micrometro = 10^-6m e 1 giga = 10^9 então gigamícron = 10^-6 x 10^9 = 10^3
(c) 1*10^3*10^3*10^3*10^3 = 10^12 bytes se usarmos base decimal
(d) 1 yota*1000*1000*1000 = (10^3)^8 = 10^24 gramas









