# Chapter 2 - Processos e Threads

This file contains the solutions to the exercises from Chapter 1 of the book **"Operating Systems"** by Andrew S. Tanenbaum.

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

Levando em conta que uma simulação estritamente sequencial nao há interrupçoes e troca de contexto a condição de corrida torna-se impossível, pois ela só ocorre quando mais de uma thread ou processo acessa uma região crítica.

