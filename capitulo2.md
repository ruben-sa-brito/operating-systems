# Chapter 2 - Processos e Threads

This file contains the solutions to the exercises from Chapter 2 of the book **"Operating Systems"** by Andrew S. Tanenbaum.

---

## Question 1

Na figura 2.2, são mostrados três estados de processos. Na teoria, com três estados, poderia haver seis transições, duas para cada estado. No entando, apenas quatro transições são mostradas. Existe alguma circunstância na qual possa ocorrer uma ou as duas transições que faltam.

**Answer:**
As duas transições que faltam seriam: 
* Um processo que está bloqueado passar para execução antes de estar pronto, este tipo de situação é meio improvavel de acontecer, um processo precisa estar pronto para indicar que pode ser executado.
* Um processo pronto volta a ser bloqueado, talvez por decisões do SO para evitar condiçoes de corrida este tipo de situação ocorra, um processo pode ser impedido de ser executado antes que outro processo termine, e portanto volta a ser bloqueado.

## Question 2

Suponha que você fosse projetar uma arquitetura de computador avançada que realizasse a troca de processos no hardware, em vez de interrupções. De qual informação a CPU precisaria? Descreva como poderia funcionar o processo de troca por hardware.

**Answer:**

Uma forma de fazer isso seria através de um timer que de tempos em tempos trocaria o processo em execução de maneira fixa e automática através do proprio hardware, dessa forma o SO nao precisaria realizar a troca por meio de algoritmos de escalonamento. A CPU precisaria da informações de tempo para realizar a troca, e tambem precisaria realizar todo o processo de troca de contexto que inclui registradores, mapa de memoria para saber que região da memória pertence ao processo, fila de processos, etc.

## Question 3

Em todos os computadores atuais, pelo menos parte dos tratadores de interrupções é escrita em linguagem de montagem (assembly). Por quê?

**Answer:**

Para que uma interrupção ocorra, é preciso realizar algumas tarefas como salvar os registradores do processador e configurar o ponteiro da pilha, essas ações lidão diretamente com o hardware do computador em um nível de manipulação que não é possivel em linguagens de alto nível.

## Question 4

Quando uma interrupção ou uma chamada de sistema transfere controle para o sistema operacional, geralmente é usada uma área da pilha do núcleo separada da pilha do processo interrompido. Por quê?

**Answer:**

O sistema operacional executa em modo privilegiado com sua pilha separada das dos demais processos, por isso é necessário trocar a pilha do processo para a pilha do núcleo, para execução do SO em modo núcleo.

## Question 5

Um sistema de computador tem espaço suficiente para conter quatro programas em sua memória principal. Esses programas estão ociosos esperando por E/S metade do temp. Qual a fração do tempo da CPU é desperdiçada.

**Answer:**

A probabilidade de todos processos estarem esperando E/S desperdiçando CPU é dada por: (1/2)⁴ * 100 = 6.25. Ou seja a CPU estará ociosa em 6.25% do tempo.

## Question 6

Um computador tem 2 GB de RAM, da qual o sistema operacional ocupa 256 MB. Os processos ocupam 128 MB cada (para simplificar) e têm as mesmas características. Se a meta é a utilização de 99% da CPU, qual é a espera de E/S máxima que pode ser tolerada?

**Answer:**

Supondo que toda a memória esteja ocupada teríamos 14 processos na memória.
Seguindo a matemática:
Uso da CPU: 1 - (x)¹⁴ = 0,99
            (x)¹⁴ = 0,01
            x = 0,719685674
Ou seja cada processo pode no máximo esperar por aproximadamente 72% do tempo em operações de E/S a partir disso o tempo de uso da CPU pode ser inferior a 99%.

## Question 7

Múltiplas tarefas podem ser executadas em paralelo e terminar mais rápido do que se forem executadas de modo sequencial. Suponha que duas tarefas, cada uma precisando de 10 minutos de tempo da CPU, iniciassem simultaneamente. Quanto tempo a última levará para completar se elas forem executadas sequencialmente? E se forem executadas em paralelo? Presuma uma espera de E/S de 50%.

**Answer:**

* Executando sequenciamente: A primeira tarefa executa 5 min e inicia E/S então é interrompida, a segunda tarefa começa sua execução é processada por 5 min e também é interrompida, até aí teriamos 10 min de tempo, o primeiro processo volta apenas para receber E/S e encerrar sem consumir tempo de CPU (teoricamente para facilitar), e após isso o outro processo volta e conclui sua operaçao de E/S em mais 5 min dando um total de 15 min, para concluir a última tarefa.

* Executando em paralelo: Como cada processo tería seu próprio núcleo levaria 10 min totais para concluir a última tarefa.

## Question 8

Considere um sistema multiprogramado com grau 5 (i.e., cinco programas na memória ao mesmo tempo). Suponha que cada processo passe 40% do seu tempo esperando pela E/S. Qual será a utilização da CPU?

**Answer:**

Tempo de CPU: 1 - (0,4)^5 => 1-0,01 = 0,99
Ou seja a utilização da CPU é de 99% do tempo

## Question 9

Explique como um navegador web pode utilizar o conceito de threads para melhorar seu desempenho.

**Answer:**

É bem comum que softwares como navegadores web executem multiplas tarefas, por exemplo pode existir uma musica sendo executada em uma das suas abas, um chat em outra, e até mesmo um jogo em outra, o que causaria um atraso significativo pois sem as threads cada terefa só poderia ser executada com o término da outra reduzindo drasticamente o desempenho, com as threads multiplas tarefas podem ser executadas.

## Question 10

Suponha que você esteja tentando baixar um arquivo grande de 2 GB da internet. O arquivo está disponível a partir de um conjunto de servidores espelho, cada um deles capaz de fornecer um subconjunto dos bytes do arquivo; suponha que uma determinada solicitação especifique os bytes de inicio e fim do arquivo. Explique como você poderia usar as threads para melhorar o tempo de download.

**Answer:**

O arquivo poderia ser dividido pela quantidade de threads disponívies e cada thread seria responsavel por fazer a solicitação ao servidor especifico se beneficiando assim das multiplas fontes de download, ao final do processo as partes do arquivo serão reconstruídas no cliente.

## Question 11

No texto, foi afirmado que o modelo da figura 2.10(a) não era adequado a um servidor de arquivos usando um cache de memória. Por que não? Será que cada processo poderia ter sua própria cache?

**Answer:**

Processos separados não possuem o mesmo espaço de endereços, para um servidor que compartilha as mesmas informações (cache por exemplo) e lidam tambem com diferentes usuarios é ideal que as threads estejam no mesmo processo facilitando assim o acesso a informações. O objetivo das threads é compartilhar um conjunto de recursos de maneira que possam trabalhar juntas intimamente para desempenhar alguma tarefa.

## Question 12

Um servidor web multithread é mostrado na figura 2.8. Se a única maneira de ler um arquivo é a chamada de sistema read com bloqueio normal, você acredita que threads de usuário ou threads de núcleo estão sendo usadas para o servidor web? Por quê?

**Answer:**

Provavelmente threads de núcleo, o sistema operacional precisa ter conhecimento das threads, caso contrário uma chamada de sistema bloqueante de uma das threads bloquearia todas as threads do processo, o que não é um cenário muito adequado para um servidor web, e minaria grande parte do benefício de se ter threads.

## Question 13

No texto, descrevemos um servidor web com múltiplas threads, mostrando por que ele é melhor do que um servidor de thread única e um servidor de máquina de estado finito. Existe alguma circunstância na qual um servidor de thread única pode ser melhor? Dê um exemplo.

**Answer:**

Um servidor web que não executa ações bloqueantes como leitura de disco por exemplo, pode ser um cenário onde apenas uma thread seja suficiente, mas acredito que na maior parte dos casos isso não acontece.

## Question 14

Na figura 2.11, o conjunto de registradores é listado como um item por thread em vez de por processo. Por quê? Afinal de contas, a máquina tem apenas um conjunto de registradores.

**Answer:**

Apesar das threads compartilharem os mesmo recursos a nível de processo elas tambem tem suas próprias informações e contexto, registradores são uma delas, quando uma thread é interrompida essas informaçoes precisam ser restauradas quando ela voltar a execução.

## Question 15

Por que uma thread em algum momento abriria mão voluntariamente da CPU chamando thread_yield? Afinal visto que não há uma interrupção periódica de relógio, ela talvez jamais receba a CPU de volta.

**Answer:**

Threads podem ser controladas a nível de usuário, uma das razões seria uma decisão do programador de que esta thread ja executou por tempo suficiente e precisa dar espaço para outra thread.

## Question 16

Neste problema, você deve comparar a leitura de um arquivo usando um servidor de arquivos de uma thread única e um servidor com múltiplas threads. São necessários 15 ms para obter uma requisição de trabalho, despachá-la e realizar o restante do processamento, presumindo que os dados necessários estejam na sua própria cache de blocos. Se uma operação de disco for necessária, como é o caso em um terço das vezes, outros 75 ms são necessários, tempo em que a thread repousa. Com quantas requisições segundo o servidor consegue lidar se ele tiver uma única thread? E se tiver múltiplas threads?

**Answer:**

Thread única:
Em 1/3 das vezes a requisição demorará 90ms(75 + 15) devido a operações de E/S, ou seja em 33 requisiçoes 11 demorariam mais tempo 11*90 = 990 ms, o restante levaria 15ms cada; 22 * 15 = 330 ms, totalizando 1320 ms para atender 33 requisiçoes, 1320ms = 1,320s, 33/1,320 = 25 requisições por segundo.

Múltiplas threads:
Tempo médio 1320 / 33 = 40ms
33*x = 990 => 990/33 = x => x = 30 | 30/40 = 0,75
Isso significa que da uma media de 75% de tempo de operaçoes de E/S para cada requisição
Como em 75% desse tempo a cpu pode ser usada para processar outra requisição a quantidade de requisições por segundo é multiplicada por 4, ou seja 25*4 = 100 requisições por segundo em um cenário multithread.

## Question 17

Por que uma thread em algum momento abriria mão voluntariamente da CPU chamando thread_yield? Afinal visto que não há uma interrupção periódica de relógio, ela talvez jamais receba a CPU de volta.

**Answer:**

Uma vantagem seria o total controle por parte do programador, a maior desvantagem com certeza são as operações bloqueantes pois todas as threads de usuario seriam bloqueadas.

## Question 18

Na figura 2.14, as criações das threads e as mensagens impressas pelas threads são intercaladas ao acaso. Existe alguma maneira de se forçar que a ordem seja estritamente thread 1 criada, thread 1 imprime mensagem, thread 1 sai, thread 2 criada, thread 2 imprime mensagem, thread 2 sai e assim por diante? Se a resposta for afirmativa, como? Se não, por que não?

**Answer:**

Sim isso é possivel mas deve ser controlado através do código, uma forma seria esperar a conclusao das tarefas da thread utilizando os metodos de controle antes de criar a próxima thread.

## Question 19

Suponha que um programa tenha duas threads, cada uma executando a função get_accound, mostrada a seguir. Identifique uma condição de corrida nesse código.

```C
int accounts[LIMIT]; int account_count = 0;

void *get_account(void *tid){
    char *lineptr = NULL;
    size_t len = 0;
    while (account_count < LIMIT){
        // Le entrada do usuario do terminal e a armazena em lineptr
        getline(&lineptr, &len, stdin);

        int entered_account = atoi(lineptr);

        accounts[account_count] = entered_account;
        account_count++;
    }
    // desaloca memoria que foi alocada pela chamada a getline
    free(lineptr);
    return NULL;
}

```
**Answer:**

Nesse código uma thread pode ser interrompida antes de ter a oportunidade de incrementar `account_count` depois de ter adicionado um valor em `accounts[account_count] = entered_account;` outra thread pode entrar em execução com o valor incorreto de `account_count` e assim sobrescrever os dados que foram adicionados pela outra thread, alem disso ela irá incrementar `account_count` e quando a outra thread voltar tambem vai incrementar mais uma vez desnecessariamente, deixando um espaço no array que não foi utilizado.


## Question 20

Na discussão sobre variáveis globais em threads, usamos um procedimento create_global para alocar memória para um ponteiro para a variável, em vez de para a própria variável. Isso é essencial, ou os procedimentos poderiam funcionar somente com os próprios valores?

**Answer:**

Às vezes as threads precisam de variáveis globais que são utilizadas em diversos procedimentos dentro da thread, o problema é que variáveis globais são compartilhadas entre as threads causando condição de corrida, com um ponteiro cada thread pode alocar dinamicamente suas variaveis globais sem interferencia uma das outras, entao a resposta seria sim e não, depende de que tipo de programa estamos falando, se um programa funciona com variáveis globais ele teria que ser reescrito para que as threads funcionem apenas com seus próprios valores.

## Question 21

Considere um sistema no qual threads são implementadas inteiramente no espaço do usuário, com o sistema de tempo de execução sofrendo uma interrupção de relógio a cada segundo. Suponha que uma interrupção de relógio ocorra exatamente quando alguma thread que está executando no sistema de tempo de execução está a ponto de bloquear ou desbloquear uma thread. Qual problema poderia ocorrer? Você poderia sugerir uma maneira de solucioná-lo?

**Answer:**

Como a thread foi interrompida no momento específico que precisava bloquear ou liberar, isso significa que outras threads podem acabar entrando em condições de corrida, ou então uma thread pode ficar mais tempo bloqueada pois o sinal nao foi enviado. Uma maneira de solucinar esse tipo de problema é usando operações que garantem a atomicidade da operação, ou seja, a thread que iniciou o procedimante que precisa bloquear ou liberar outras threads nao pode ser interrompida antes de concluir sua operação.

## Question 22

Suponha que um sistema operacional não tenha nada parecido com a chamada de sistema select para saber antecipadamente se é seguro ler de um arquivo, pipe ou dispositivo, mas ele permite que relógios de alarme (timers) sejam configurados para interromper chamadas de sistema bloqueadas. É possível implementar um pacote de threads no espaço de usuário que não bloqueie todas as threads quando uma thread realiza uma chamada do sistema que pode bloqueá-la? Explique sua resposta.

**Answer:**

Sem select uma alternativa seria configurar um timer para interromper uma thread que bloqueia o processo inteiro, dando espaço para que outras threads possam executar, a thread bloqueante pode tentar outras vezes mais tarde.

## Question 23

A solução de Peterson para o problema da exclusão mútua mostrado na figura 2.24 funciona quando o escalonamento de processos é preemptivo? E quando ele é não preemptivo?

**Answer:**

Essa solução é especialmente util em sistemas preemptivos, ou seja, o sistema operacional pode decidir que um processo ja executou por tempo suficiente e interrompe-lo em um momento crítico causando condições de corrida, para sistemas não preemptivos o sistema operacional permite que as threads e processos executem suas operações sem interrupção.

Ainda assim em um sistema multicore o problema ainda pode ocorrer mesmo em sistemas não preemptivos a solução de Peterson continua funcionando nesses sistemas, embora a necessidade de uma abordagem específica para exclusão mútua seja menor.

## Question 24

O problema da inversão de prioridade discutido na Seção 2.3.4 pode acontecer com threads de usuário? Por que ou por que não?

**Answer:**

Sim, o problema de inversão de prioridade pode ocorrer com threads de usuário, uma thread de baixa prioridade adquire o mutex e é entao interrompida dando vez a uma thread de prioridade média, a thread de prioridade alta nao pode acessar a região crítica pois a thread de prioridade baixa ainda está com o mutex, a thread de prioridade média continua executando como se tivesse prioridade maior do que a thread de prioridade alta.

## Question 25

Na Seção 2.3.4, uma situação com um processo de alta prioridade, A, e um processo de baixa prioridade, B, foi descrita, o que levou A a entrar em um laço infinito. O mesmo problema ocorre se o escalonamento circular for usado em vez do escalonamento por prioridade? Discuta.

**Answer:**

Com o escalonamento ciruclar cada processo recebe um quantum que estabelece quanto tempo cada processo deve executar, provavelmente a situaçao descrita será minimizada, pois o quantum do processo de prioridade media seria ultrapassado passando a cpu para o processo de prioridade baixa e assim ele poderia concluir sua operação e devolver o mutex.

## Question 26

Em um sistema com threads, há uma pilha por thread ou uma pilha por processo quando threads de usuário são usadas? E quando threads de núcleo são usadas? Explique.

**Answer:**

Processos tem pilhas, e threads tambem, threads são como processos em miniatura, tambem tem seu proprio contexto e variáveis, apesar de compartilharem os mesmos recursos das outras threads dentro de um mesmo processo. Tanto threads de usuario como de núcleo possuem vantagens e desvantagens, um dos motivos para se usar threads de usuário seria o de maior controle e algoritmo de escalonamento customizado, threads de núcleo possui visibilidade do sistema operacional isso fornece algumas vantagem como por exemplo; uma thread que executa uma operação bloqueante nao bloqueia todas as threads do processo, em sistemas multinucleo o sistema operacional pode direcinar threads diferentes para núcleos diferentes proporcionando paralelismo real.

## Question 27

O que é uma condição de corrida?

**Answer:**

Uma condição de corrida é quando duas ou mais threads ou processos acessam um recurso compartilhado ao mesmo tempo. O resultado dessa condição geralmente é indesejado.

## Question 28

Quando um computador está sendo desenvolvido, normalmente ele é primeiro simulado por um programa que executa uma instrução de cada vez. Mesmo multiprocessadores são simulados de maneira estritamente sequencial. É possível que uma condição de corrida ocorra quando não há eventos simultâneos? Explique.

**Answer:**

Levando em conta que em uma simulação estritamente sequencial nao há interrupçoes e troca de contexto a condição de corrida torna-se impossível, pois ela só ocorre quando mais de uma thread ou processo acessa uma região crítica.

## Question 29

O problema do produtor-consumidor pode ser ampliado para um sistema com múltiplos produtores e consumidores que escrevem (ou leem) em (ou de) um buffer compartilhado. Suponha que todos os produtores e consumidores executem em sua própria thread. A solução apresentada na figura 2.28, utilizando semáforos, funcionaria para esse sistema?

**Answer:**

Os semáforos foram projetados para acumular sinais para que nenhum seja perdido, entao sim, semáforos funcionam até quando se tem muitos produtores e consumidores.

## Question 30

Considere a solução a seguir para o problema da exclusão mútua envolvendo dois processos P0 e P1. Suponha que a variável turn seja inicializada em 0. O código do processo P0 é apresentado a seguir:

```C
while(turn != 0){} /* Não faz nada e espera */
Critical Section
turn = 0 
```

Para o processo em P1, substitua 0 por 1 no código anterior. Determine se a solução atende as condições exigidas para uma solução de exclusão mútua.

**Answer:**

Os processos não estão modificando a variavel turn para dar oportunidade para que o outro processo entre na região crítica, a condição de espera de P0 é que turn seja diferente de 0, mas como P0 não definie turn para 1 ele nunca ficará em espera e P1 nunca entrará na região crítica.
Para corrigir esse problema, após sair da seção crítica, P0 deve configurar turn = 1, e P1 deve configurar turn = 0. Isso garantirá a alternância entre os processos, evitando que um deles fique preso esperando indefinidamente.

## Question 31

Mostre como semáforos contadores (semáforos que podem armazenar um valor arbitrário) podem ser implementados usando apenas semáforos binários e instruções de máquina comuns.

**Answer:**

Podemos usar duas chamadas down e up (correspondem a sleep e wakeup). A operação down em um semáforo confere para ver se o valor é maior que 0. Se for, ele decrementa o valor (gasta um sinal de despertar armazenado) e apenas continua. Se o valor for 0, o processo é colocado para dormir sem completar down para o momento. Conferir o valor, modificá-lo é realizado como uma única ação atômica indivisivel. 
A operação up incrementa o valor de um determinado semáforo. Se um ou mais processos estiverem dormindo naquele semáforo, incapazes de completar uma operação down anteriro, um deles é escolhido pelo sistema e é autorizado a completar seu down.

## Question 32

Se um sistema tem apenas dois processos, faz sentido usar uma barreira para sincronizá-los? Por que ou por que não?

**Answer:**

Barreiras são mecanismos que impedem que um processo continue antes que outros processos terminem seu trabalho, ou seja, dois processos podem ser dependentes caso precisem sincronizar suas execuções, por exemplo, um processo pode gerar um conjunto de dados que é entregue para outro processo, nesse caso faz sentido que este espere um período até que ambos tenham terminado seus serviços.

## Question 33

É possível que duas threads no mesmo processo sincronizem usando um semáforo do núcleo se as threads são implementadas pelo núcleo? E se elas são implementadas no espaço do usuário? Suponha que nenhuma thread em qualquer outro processo tenha acesso ao semáforo. Discuta suas respostas.

**Answer:**

Threads de núcleo podem usar semáforos de núcleo, ja threads de usuario teriam um problema ao usar semáforos de núcleo, o sistema operacional não tem conhecimento das threads de usuário e portanto ele nao poderia direcionar os sinais, sinais de dormir ou despertar seriam aplicados ao processo inteiro e não a uma thread específica.


## Question 34

Suponha que temos um sistema de transmissão de mensagens usando caixas de correio. Quando envia para uma caixa de correio chei ou tenta receber de uma vazia, um processo não é bloqueado. Em vez disso ele recebe de volta um código de erro. O processo responde ao código de erro apenas tentando de novo, repetidas vezes, até ter sucesso. Esse esquema ocasiona condições de corrida?

**Answer:**

Depende um pouco de como o sistema foi implementado, suponha que ao lotar a caixa de mensagens o processo responsavel por configurar a mensagem de erro tenha sido interrompido antes de ter a oportunidade de realizar sua ação, o processo responsavel por alimentar a caixa de mensagem entra em execução, como o sistema não está logicamente preparado para impedir a ação do produtor ele pode acabar sobrescrevendo uma das mensagem em uma condição de corrida.

Entretanto se os processos responsaveis por produzir e consumir mensagens tambem são responsaveis por controlar a configuração, a situação pode mudar um pouco, como a ação é não bloqueante o processo responsavel por produzir a mensagem verifica se a caixa está lotada e então configura o valor corretamente em uma ação não bloqueante impedindo que outros produtores tenham sobrescrevam a caixa de mensagem.

## Question 35

Os computadores CDC 6600 podiam lidar com até 10 processos de E/S simultaneamente usando uma forma interessante de escalonamento circular chamado de compartilhamento de processador. Uma troca de processo ocorria após cada instrução, de maneira que a isntrução 1 vinha do processo 1, a instrução 2 do processo 2 etc. A troca de processo era realizada por um hardware especial e o overhead era zero, Se um processo precisasse de T segundos para ser completado na ausência de concorrência, de quanto tempo ele precisaria se o compartilhamento de processador fosse usado com n processos?

**Answer:**

O tempo de processador seria dividido entre os n processos, se um processo leva T segundos para concluir sua operação com n processos no sistema ele levaria n*T segundos.

## Question 36

Considere o fragmento de código em C a seguir:

```C
void main(){
    fork();
    fork();
    exit();
}
```
Quantos processos-filho são criados com a execução desse programa?

**Answer:**

Na primeira chamada `fork()` é criado mais um processo, já na segunda chamada, ambos os processos executam o segundo `fork()`, totalizando agora 4 processos em execuçao.

## Question 37

Escalonadores circulares em geral mantêm uma lista de todos os processos executáveis, com cada processo ocorrendo exatamente uma vez na lista. O que aconteceria (por parte do escalonador) se um processo ocorresse duas vezes na lista? Você consegue pensar em qualquer razão para permitir isso?

**Answer:**

Bem, com o mesmo quantum para todos os processos é como se o processo que ocorresse duas vezes na lista tivesse o dobro de tempo de execução, o processo obtem uma prioridade maior que os outros e mais tempo de CPU, é justamente a situação onde pode existir uma razão de permitir isso, prioridade de processos.

## Question 38

É possível determinar se um processo é propenso a se tornar vinculado à CPU ou vinculado à E/S analisando o código fonte? Como isso pode ser determinado em tempo de execução?

**Answer:**

O sistema operacional precisaria avaliar quais ações o processo executa mais com base no código fonte e fazer uma estimativa do que levaria mais tempo se é E/S ou processamento.


## Question 39

Na seção "quando escalonar", foi mencionado que o escalonamento às vezes poderia ser melhorado se um processo importante pudesse desempenhar um papel na escolha do próximo processo a ser executado quando ele for bloqueado. Indique uma situação em que isso poderia ser usado e explique como.

**Answer:**

Um precesso A pode estar esperando a liberação de uma região critica que está sendo utilizada pelo processo B, ao ser interrompido A pode informar que deseja que o processo B termine sua execução e libere a região crítica, assim o processo de alta prioridade A pode concluir sua operação. O problema é que o escalonador geralmente nao tem essa informação para levar em consideração.

## Question 40

Explique como o valor quantum de tempo e o tempo de troca de contexto afetam um ao outro, em um algoritmo de escalonamento circular.

**Answer:**

Parte do tempo do quantum é utilizado para troca de contexto, digamos que cada processo possui 4ms de quantum e 1ms é utilizado para troca de processos, ou seja 20%, isso significa que uma parecela muito relevante desse tempo é desperdiciada apenas para passagem do processo, entao é ideal buscar um equilibrio e estabelecer um valor para um quantum que não desperdice tanto a CPU, mas que também nao atrase respostas a interações interativas curtas.

## Question 41

Medidas de um determinado sistema mostraram que o processo típico é executado por um tempo T antes de ser bloqueado na E/S. Uma troca de processo exige um tempo S, que é efetivamente desperdiçado (overhead). Para o escalonamento circular com quantum Q, dê uma fórmula para a eficiência da CPU para cada uma das situações a seguir.

a) Q = ∞
b) Q > T
c) S < Q < T
d) Q = S
e) Q quase 0

**Answer:**

a) Se Q é infinito significa que a CPU tem o máximo de eficiencia possível.

b) fórmula =  (T/Q+S) *100, exemplo Q = 4ms, T = 3ms, S = 1ms => 3/5 *100 = 60%.

c) como o tempo T é maior que Q significa que todo o tempo restante alem da troca de processo é gasto com processamento: fórmula = ( Q / (Q + S)) * 100, exemplo Q = 4ms, S = 1ms, T = ∞,
4/5 = 80%

d) nesse caso a eficiencia é 0, pois todo o tempo é gasto apenas para troca de processo.

e) Se Q é quase 0 a eficiencia da CPU também tenderá a 0 pois ainda haverá o tempo de troca de processo que será muito maior que o tempo disponível para processamento.

## Question 42

Cinco tarefas em lote, A e E, chegam quase ao mesmo tempo. Elas têm tempos de execução estimados em 10, 6, 2, 4 e 8. Suas prioridades (externamente determinadas) são 3, 5, 2, 1 e 4, respectivamente, sendo 5 a mais alta. Para cada um dos algoritmos de escalonamento a seguir determine o tempo de retorno médio do processo. Ignore o overhead da troca de processo.

a) Circular.
b) Escalonamento por prioridade.
c) Primeiro a chegar, primeiro a ser servido (siga a ordem 10, 6, 2, 4, 8).
d) Tarefa mais curta primeiro.

Para a), suponha que o sistema é multiprogramado e que cada tarefa recebe sua porção justa de tempo da CPU. Para b) até d), suponha que apenas uma tarefa de cada vez é executada, até terminar. Todas as tarefas são completamente vinculadas a CPU.

**Answer:**

a) escalonamento circular precisa de um quantum(tempo maximo de processamento antes de trocar) vamos assumir que o quantum seja 2ms.

A executa por 2ms - B executa por 2ms - C executa por 2ms(última execução) - D executa por 2ms - E executa por 2ms
A executa por 2ms - B executa por 2ms - D executa por 2ms(última execução)  - E executa por 2ms
A executa por 2ms - B executa por 2ms(última execução)  - E executa por 2ms
A executa por 2ms - E executa por 2ms(última execução) 
A executa por 2ms(última execução) 

Então temos A = 30ms, B = 22ms, C = 6ms, D = 16ms, E = 28

(30+22+6+16+28)/5 = 20,4ms de tempo de retorno médio.

b) ordem de execução será: B>E>A>C>D
   (6+14+24+26+30)/5 = 20ms

c) (10+16+18+22+30)/5 = 19,2ms

d) ordem de execução: C>D>B>E>A
   (2+6+12+20+30)/5 = 14ms

## Question 44

Um processo executando no CTSS precisa de 30 quanta para ser concluído. Quantas vezes ele deve ser trocado para execução, incluindo a primeiríssima vez (antes de ter sido executado)?

**Answer:**

Inicalmente ele executa por um quantum e vai duplicando ao subir o nível, entao:
1 => 2 => 4 => 8 >= 16
Ou seja ele precisa ser trocado 5 vezes.

## Question 45

É possível imaginar um modo de evitar que o sistema de prioridade CTSS seja enganado por toques aleatórios da tecla Enter?

**Answer:**

Talvez tirando o controle do usuário e esperando que o proprio processo faça uma chamada de sistema para interatividade, dessa forma evita que o usuário engane o sistema para ganhar mais tempo de CPU.

## Question 46

Considere um sistema de tempo real com duas chamadas de voz de periodicidade de 5ms cada, com um tempo de CPU por chamada de 1ms e um fluxo de vídeo de periodicidade de 33ms com tempo de CPU por chamada de 11ms Esse sistema é escalonavel? Mostre como a sua resposta foi derivada.

**Answer:**

Determinar se um sistema é escalonável é dado por:
∑Ci/Pi <= 1
1/5 + 1/5 + 11/33 = 0,733

Então podemos dizer que esse sistema é escalonável.

## Question 47

Para algoritmo anterior, será que outro fluxo de vídeo pode ser acrescentado e ter o sistema ainda escalonável?

**Answer:**

Sim contanto q Ci/Pi não seja maior que 0,27, ou seja se ele tiver um período de 1 segundo, ele nao poderia ter tempo superior a 270ms

## Question 48

Para algoritmo de envelhecimento com a = 1/2 está sendo usado para prever tempos de execução. As quatro execuções anteriores, da mais antiga à mais recente, são 40, 20, 40 e 15 ms, Qual é a previsão do próximo tempo?

**Answer:**

Usando o algoritmo de envelhecimento ficaria:
15/2 + 40/4 + 20/8 + 40/16
Privisão para proxima tarefa: 22,5ms 

## Question 49

Um sistema de tempo real não crítico tem quatro eventos periódicos com períodos de 50, 100, 200 e 250 ms cada. Suponha que os quatro eventos exijam 35, 20, 10 e x ms de tempo de CPU, respectivamente. Qual é o maior valor de x de tempo de CPU, respectivamente. Qual é o maior valor de x para o qual o sistema é escalonável.

**Answer:**

∑Ci/Pi <= 1
35/50 + 20/100 + 10/200 = 0,95

Ou seja Ci/Pi nao pode ser maior q 0,05, como o periodo é 250, então x não pode ser maior que 12,5.

## Question 50

Explique por que o escalonamento de dois níveis é comumente utilizado. Quais são suas vantagens em relação ao escalonamento em nível único.

**Answer:**

Quando cada processo tem múltiplas threads temos dois niveis de paralelismo: processos e threads. Ou seja o escalonamento depende se existe suporte para threads de usuário ou threads de núcleo(ou ambos). Se são apenas threads de usuário o sistema faz o escalonamento como sempre fez tendo em vista apenas os processos, o escalonamento das threads é responsabilidade do processo e não do SO, Já em threads de núcleo o SO tem o controle e realiza o escalonamento. A troca de contexto acontece quando o SO troca de um processo para o outro e é ordens de grandeza mais lenta do que troca de threads em um mesmo processo, então o SO sabe que trocar uma thread dentro de um processo A para uma thread do processo A para o B é muito mais rapido, ele pode levar isso em consideração no seu algoritmo de escalonamento. Threads de usuário tem a desvantegem de que uma operção bloqueante de E/S bloquearia todo o processo, mas por outro lado o maior controle por parte do programador otimiza o escalonamento das threads o nível de conhecimento sobre o que cada thread faz é algo que o SO muitas vezes não consegue levar em consideração.

## Question 51

Um sistema de tempo real precisa lidar com duas chamadas de voz, cada uma executando a cada 5ms e consumindo 1ms de tempo de CPU por surto, mais um vídeo a 25 quadros/s, com cada quadro exigindo 20ms de tempo de CPU. Esse sistema é escalonável? Por favor, explique por que ele é escalonável ou não, e como você chegou a essa conclusão.

**Answer:**

∑Ci/Pi <= 1

duas chamadas de voz + quadro de vídeo = 2*1/5 + (20*25)/1000 = 0,4 + 0,5 = 0,9

Explicação: cada quadro precisa de 20ms de tempo de processamento, mas são necessários 25 quadros com um ciclo de 1000ms, ou seja o sistema precisa processar 500ms de tempo de para processar o vídeo a cada 1 segundo ou 1000ms, então fica 500 / 1000, como o resultado de todos processos de tempo real ficou menor que 1, esse sistema é escalável.


## Question 52

Considere um sistema no qual se deseja separar política e mecanismo para escalonamento de threads de núcleo. Proponha um meio de atingir essa meta.

**Answer:**

Threads de núcleo são visualizadas pelo SO, mas ele pode escalona-las de acordo com suas regras, o processo tem um conhecimento mais profundo sobre suas threads e portanto pode fornecer informações da melhor maneira de escaloná-las, a solução é o SO emitir uma chamada de sistema para o processo solicitando os parâmetros de escalonamento, o processo informa esses parâmetros, é o que chamamos de separação entre mecanismo e política de escalonamento.

## Question 53

O problema dos leitores e escritores pode ser formulada de várias maneiras em relação a qual categoria de processo pode ser iniciada e quando. Descreva cuidadosamente três variantes do problema, cada uma favorecendo (ou não favorecendo) alguma categoria de processo (p. ex., leitores ou escritores). Para cada variação, especifique o que acontece quando um leitor ou um escritor está pronto para acessar o banco de dados e o que acontece quando um processo foi concluído.

**Answer:**

1. Dando preferencia aos leitores; isso significa que quando um leitor chegar ele é automaticamente aceito para acessar o banco de dados, essa abordagem tem um atrativo que é o fato de que não há problema em existir multiplos leitores acessando um banco de dados, por outro lado temos um problema de espera eterna por parte dos escritores, como o escritor não poderá acessar a região critica para não causar condição de corrida com os leitores, um escritor pode ficar eternamente na fila, uma vez que mais e mais leitores são aceitos e não sao impedidos.

2. Dando preferencia aos leitores; Situação semelhante dessa vez os escritos são aceitos e postos numa fila, os leitores só podem ter acesso ao banco quando os escritores terminarem seu trabalho, o problema é que como leitores são imediatamente aceitos, o tempo de espera dos leitores pode se estender eternamente.

3. Sem preferencia; leitores e escritores são aceitos sem distinção, evita-se o problema de escritores ou leitores esperarem indefinidamente, entretanto pode-se perder o beneficio de multiplos leitores.


## Question 54

Escreva um roteiro (script) shell que produz um arquivo de números sequenciais lendo o último número, somando 1 a ele e então anexando-o ao final do arquivo. Execute uma instância do roteiro no segundo plano e uma no primeiro plano, cada uma acessando o mesmo arquivo. Quanto tempo leva até que a condição de corrida se manifeste? Qual é a região crítica? Modifique o roteiro para evitar a corrida.
(Dica: use
    **In file.lock**
para travar o arquivo de dados.
)

**Answer:**

A condição de corrida aconteceu muito rapidamente ao executar o script em [race.sh](./codes/codes_cpt2/question_54/race.sh), proximo de 1 segundo de tempo de execução ja foi possível identifica-la, na linha 1256 do arquivo numbers.txt temos um exemplo, o que aconteceu aqui é que o primeiro processo leu a ultima linha(valor 1248) e antes de poder realizar a escrita foi interrompido, o segundo processo então obteve acesso a região crítica leu a ultima linha(1248) e armazenou o valor 1249 na ultima linha do arquivo, o primeiro processo voltou a execução com o valor incorreto da ultima linha realizou a soma (1248 + 1) e armazenou novamento na ultima linha o valor 1249.

Já na execução do segundo script [race_lock.sh](./codes/codes_cpt2/question_54/race_lock.sh)com controle atraves de um lock file não foi identificada condição de corrida. 

A região critica representada em  [numbers_lock.txt](./codes/codes_cpt2/question_54/ ) com controle
e [numbers.txt](./codes/codes_cpt2/question_54/numbers.txt) região sem controle, contem os números gerados quando fiz os testes e executei os scripts.

## Question 55

Suponha que você tenha um sistema operacional que fornece semáforos. Implemente um sistema de mensagens. Escreva os procedimentos para enviar e receber mensagens.

**Answer:**




