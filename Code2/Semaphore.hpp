//#ifndef __SEMAPHORE_H
//#define __SEMAPHORE_H
//
//#include "Headers.hpp"
//
//// Synchronization Warm up
//class Semaphore {
//public:
//    // Constructs a new semaphore with a counter of 0
//    Semaphore();
//
//    ~Semaphore();
//
//    // Constructs a new semaphore with a counter of val
//    explicit Semaphore(unsigned val);
//
//    // Mark: 1 Thread has left the critical section
//    // Equivalent to signal function
//    void up();
//
//    // Block until counter >0, and mark - One thread has entered the critical section.
//    // Equivalent to wait or post function
//    void down();
//
//private:
//    unsigned counter;
//    pthread_mutex_t mutex;
//    pthread_cond_t cond;
//};
//
//#endif



#ifndef __SEMAPHORE_H
#define __SEMAPHORE_H
#include "Headers.hpp"

// Synchronization Warm up
class Semaphore {
public:
    Semaphore(); // Constructs a new semaphore with a counter of 0
    Semaphore(unsigned val); // Constructs a new semaphore with a counter of val


    void up(); // Mark: 1 Thread has left the critical section
    void down(); // Block untill counter >0, and mark - One thread has entered the c.

private:
    pthread_mutex_t m;
    pthread_cond_t c;
    unsigned long counter; // num of max cores available at the moment (set by val arg in c'tor)
    unsigned long min; // min thread-id waiting to enter the critical section
    unsigned long next; // gives every new thread (who asking to enter) a unique id
};

#endif
