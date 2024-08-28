#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdbool.h>

#define BROJ_GOSTIJU 10

int gostiKojiJedu = 0;
int gostiKojiCekaju = 0;
bool neophodnoCekanje = false;

sem_t semaforCekanja;
sem_t mutex;

void *gostNit() {

    sleep(2);
    sem_wait(&mutex);

    if(neophodnoCekanje) {
        printf("Ovaj gost mora da saceka. %d stolica je slobodno, %d drugih ljudi takodje ceka.\n", 5 - gostiKojiJedu, gostiKojiCekaju);
        gostiKojiCekaju++;
        sem_post(&mutex);
        sem_wait(&semaforCekanja);
        gostiKojiCekaju--;
    }

    if(gostiKojiJedu == 4) printf("Zauzeto je poslednje mesto.\n");
    else {
        printf("%d stolica je slobodno. Ovaj gost zauzima jedno i pocinje da jede.\n", 5 - gostiKojiJedu);
    }

    gostiKojiJedu++;
    sleep(1);
    
    neophodnoCekanje = (gostiKojiJedu == 5);
    if(gostiKojiCekaju && !neophodnoCekanje) sem_post(&semaforCekanja);
    else sem_post(&mutex);

    sleep(5);
    gostiKojiJedu--;

    printf("Ovaj gost odlazi. %d stolica je slobodno.\n", 5 - gostiKojiJedu);

    if(gostiKojiJedu == 0) neophodnoCekanje = false;

    if(gostiKojiCekaju &&(!neophodnoCekanje)) sem_post(&semaforCekanja);

}

int main(void) {

    pthread_t thread[BROJ_GOSTIJU];

    sem_init(&mutex, 0, 1);
    sem_init(&semaforCekanja, 0, 0);

    for(int i = 0; i < BROJ_GOSTIJU; i++) {
        sleep(rand() % 8);
        pthread_create(&thread[i], NULL, gostNit, NULL);
    }

    for(int i = 0; i < BROJ_GOSTIJU; i++) {
        pthread_join(thread[i], NULL);
    }

    return 0;
    
}