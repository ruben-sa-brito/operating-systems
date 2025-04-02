#include <stdio.h>
#include <pthread.h>
#define MAX 1000000000
#define MAX_THREADS 3  // Limite de threads simultâneas

sem_t sem;

pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;
int buffer = 0;

void *producer(void *ptr){
    int i;

    for(i=1; i <= MAXX; i++) {
        pthread_mutex_lock(&the_mutex);
        while (buffer != 0) pthread_cond_wait(&condp, &the_mutex);
        buffer = i;
        pthread_cond_signal(&condc);
        pthread_mutex_unlock(&the_mutex)
    }
    sem_post(&sem);
    pthread_exit(0);
}

void *consumer(void *ptr){
    int i;
    for (i=1; i<= MAX; i++){
        sem_wait(&sem);
        while(buffer == 0) pthread_cond_wait(&cond, &the_mutex);
        buffer = 0;
        pthread_cond_signal(&condp);
        pthread_mutex_unlock(&the_mutex);
    }
    pthread exit(0);
}

int main(argc, char **argv){
    pthread_t pro_1, pro_2, con_1, con_2;

    sem_init(&sem, 0, MAX_THREADS); 

    pthread_mutex_init(&the_mutex, 0);
    pthread_cond_init(&condc, 0);
    pthread_create(&con_1, 0, consumer, 0);
    pthread_create(&con_2, 0, consumer, 0);
    pthread_create(&pro_1, 0, producer, 0);
    pthread_create(&pro_2, 0, producer, 0);
    pthread_join(pro_1, 0);
    pthread_join(pro_2, 0);
    pthread_join(con_1, 0);
    pthread_join(con_2, 0);
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&the_mutex);
}