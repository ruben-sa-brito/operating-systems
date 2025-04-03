#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_MSG 10

sem_t semaforo;

void* producer() {
    while (1) {
        FILE *arq = fopen("mensagens.txt", "a+"); 
        int lines = 0;
        char c;
        while(fread (&c, sizeof(char), 1, arq)) {
            if(c == '\n') {
                lines++;
            }
        }

        if (lines == 0){
            sem_post(&semaforo);
        }

        if (lines < 10){
            
            if (arq == NULL) {
                perror("Erro ao abrir o arq");
                exit(1);
            }

            if (lines > MAX_MSG) {
                printf("Capacidade máxima atingida!\n");
            }
            fprintf(arq, "Mensagem numero: %d!\n", lines+1);
        } else {
            sem_wait(&semaforo);
        }
        rewind(arq);
    }
    return NULL;
}

void* consumer() {
    while (1) {
        FILE *arq = fopen("mensagens.txt", "a+"); 
        
        if (arq == NULL) {
            printf("Erro ao abrir o arq!\n");
            return NULL;
        }
        int count = 0;
        char d;
        while ((d = fgetc(arq)) != EOF) {
            if (d == '\n') {
                count++;
            }
        }
        if (count == 10){
            sem_post(&semaforo);
        }
        
        fseek(arq, 0, SEEK_END); 
        long pos = ftell(arq); 

        if (pos == 0){
            sem_wait(&semaforo);
        }

        char c;
        fseek(arq, --pos, SEEK_SET); 

        while (pos > 0) {
            fseek(arq, --pos, SEEK_SET); 
            fread(&c, sizeof(char), 1, arq);
            if (c == '\n') { 
                break;
            }
        }

        char last_line[1024]; 
        fgets(last_line, sizeof(last_line), arq);
        printf("Consumindo mensagem: %s\n", last_line);
        int fd = fileno(arq);
        ftruncate(fd, pos);
    }
}

int main() { 
    pthread_t prod;
    pthread_t cons;
    
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&prod, NULL, consumer, NULL);
    pthread_join(prod, NULL);

    return 0;
}