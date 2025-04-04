#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int is_prime(long int num) {
    if (num < 2) return 0;
    if (num == 2 || num == 3) return 1;
    if (num % 2 == 0) return 0;
    
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void* collect_primes_thread(void *start_end){

    FILE *arq = fopen("numbers.txt", "a+");
    long int *pos = (long int *)start_end; 
    fseek(arq, pos[0], SEEK_SET);
    char c;
    char number_temp[10];
    long  i = 0;
    while(ftell(arq) < pos[1] && fread(&c, sizeof(char), 1, arq)) {
        number_temp[i] = c;
        i++;
        if (c == '\n'){
            is_prime(atoi(number_temp));
            memset(number_temp, 0, sizeof(number_temp));
            i = 0;
        }
        
    }
}

int main() { 
    int pos_1[] = {0, 2338896};
    int pos_2[] = {2338896, 3388890};
    int pos_full[] = {0, 3388890};
    clock_t init;
    double time;

    pthread_t thread_1;
    pthread_t thread_2;
    init = clock();
    pthread_create(&thread_1, NULL, collect_primes_thread, pos_1);
    pthread_create(&thread_2, NULL, collect_primes_thread, pos_2);

    pthread_join(thread_1, NULL);
    pthread_join(thread_1, NULL);
    time = ((double)(clock() - init)) / (CLOCKS_PER_SEC);
    printf("Processamento de multiplas threads concluido, tempo: %lf\n", time);

    // init = clock();
    // pthread_t thread_full;
    // pthread_create(&thread_full, NULL, collect_primes_thread, pos_full);
    
    // pthread_join(thread_full, NULL);
    // time = ((double)(clock() - init)) / (CLOCKS_PER_SEC);
    // printf("Processamento de thread unica, tempo: %lf\n", time);

}
