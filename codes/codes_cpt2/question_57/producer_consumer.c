#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define SLEEP usleep(500000);;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

bool sleep_consumer = false;
bool sleep_producer = false;

void* producer() {
    while (1) {
        FILE *arq = fopen("mensagens.txt", "a+"); 
        int lines = 0;
        char c;
        SLEEP 
        while(fread (&c, sizeof(char), 1, arq)) {
            if(c == '\n') {
                lines++;
            }
        }

        if (lines == 0){
            printf("acordando o consumidor\n");
            sleep_consumer = false;
        }

        if (lines < 10){
            fprintf(arq, "Mensagem numero: %d!\n", lines+1);
        } else {
            sleep_producer = true;
            while (sleep_producer) {
                SLEEP 
                printf("Produtor dormindo!\n");
            }
            
        }
        rewind(arq);
    }
    return NULL;
}

void* consumer() {
    while (1) {
        FILE *arq = fopen("mensagens.txt", "a+"); 
        int count = 0;
        char d;
        SLEEP 
        while ((d = fgetc(arq)) != EOF) {
            if (d == '\n') {
                count++;
            }
        }
        if (count == 10){
            printf("acordando o produtor\n");
            sleep_producer = false;

        }
        
        fseek(arq, 0, SEEK_END); 
        long pos = ftell(arq); 

        

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
        if (pos == 0){
            sleep_consumer = true; 
            while (sleep_consumer) {
                SLEEP 
                printf("Consumidor dormindo!\n");
            }
        }
    }
}

int main() { 
    pthread_t prod;
    pthread_t cons;
    
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    return 0;
}