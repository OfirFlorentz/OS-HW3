//
// Created by student on 12/27/20.
//
#include "Semaphore.hpp"

Semaphore::Semaphore() : m(), c(), counter(1), min(0), next(0) {};

Semaphore::Semaphore(unsigned val) : m(), c(), counter(val), min(0), next(0) { // TODO val=0 (piazza?)
    if (val == 0) { // TODO
        counter = 1;
    }
};

void Semaphore::up() {
    pthread_mutex_lock(&m);
    ++counter;
    pthread_cond_broadcast(&c);
//    pthread_cond_signal(&c); // TODO
    pthread_mutex_unlock(&m);
}

void Semaphore::down() {
    pthread_mutex_lock(&m);

    unsigned int id = next++;

    while (id >= counter+min || counter == 0) {
        pthread_cond_wait(&c, &m);
    }
    --counter;
    ++min;
    pthread_mutex_unlock(&m);
}
