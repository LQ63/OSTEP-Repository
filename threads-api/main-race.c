#include <stdio.h>
#include <pthread.h>
#include "common_threads.h"

pthread_mutex_t lock;
int balance = 0;

void pTTthread_mutex_lock(pthread_mutex_t *lock) {
    int rc = pthread_mutex_lock(lock);
    assert(rc == 0); // terminiert das programm wenn rc == 0 nicht erfüllt ist
}
void pTTthread_mutex_init(pthread_mutex_t *lock) {
    int rc = pthread_mutex_init(lock, NULL);
    assert(rc == 0);
}
void pTTthread_mutex_unlock(pthread_mutex_t *lock) {
    int rc = pthread_mutex_unlock(lock);
    assert(rc == 0);
}
void pTTthread_mutex_destroy(pthread_mutex_t *lock) {
    int rc = pthread_mutex_destroy(lock);
    assert(rc == 0);
}


void* worker(void* arg) {
    pTTthread_mutex_lock(&lock);
    balance++; // unprotected access
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(int argc, char *argv[]) {
    pTTthread_mutex_init(&lock);
    pthread_t p;
    Pthread_create(&p, NULL, worker, NULL);
    pTTthread_mutex_lock(&lock);
    balance++; // unprotected access
    pTTthread_mutex_unlock(&lock);
    Pthread_join(p, NULL);
    pTTthread_mutex_destroy(&lock);
    //printf("Balance: %d\n",balance);
    return 0;
}
