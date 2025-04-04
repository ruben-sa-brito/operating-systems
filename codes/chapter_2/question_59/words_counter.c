#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

// int main(){
//     FILE *arq = fopen("text.txt", "a+");
//     char c;
//     char count_n = 0;
//     while (fread(&c, sizeof(char), 1, arq)) {
//         if (c=='\n') {
//             count_n++;
//         }
//         if (count_n == 24){
//             printf("%ld\n", ftell(arq));

//         }
//     }
//     printf("%ld\n", ftell(arq));
// }


void* collect_primes_thread(void *start_end){
    FILE *arq = fopen("text.txt", "a+");
    int *pos = (int *)start_end; 
    fseek(arq, pos[0], SEEK_SET);
    char c;
    char word_temp[1000];
    int *total_words = malloc(sizeof(int));
    int i = 0;
    while(ftell(arq) < pos[1] && fread(&c, sizeof(char), 1, arq)) {
        
        if (c == ' ' || c == ',' || c == '.' || c == ';' || c == ':') {
            if (strcmp(word_temp, "ipsum") == 0){
                *total_words += 1;
            }
            memset(word_temp, 0, sizeof(word_temp));
            i = 0;
        } else {
            word_temp[i] = c;
            i++;
        }
    }
    return total_words;
}


int main() { 
    int pos_1[] = {0, 1744};
    int pos_2[] = {1744, 3580};
    int *total_1;
    int *total_2;

    pthread_t thread_1;
    pthread_t thread_2;
    pthread_create(&thread_1, NULL, collect_primes_thread, pos_1);
    pthread_create(&thread_2, NULL, collect_primes_thread, pos_2);
    pthread_join(thread_1, (void **) &total_1);
    pthread_join(thread_2, (void **) &total_2);

    
    printf("quantidade de palavras 'ipsum' no texto é: %d\n", *total_1 + *total_2);
}