#ifndef _QUEUEL_H
#define _QUEUEL_H
#include "Headers.hpp"
#include "Semaphore.hpp"


// Single Producer - Multiple Consumer queue
template <typename T>class PCQueue
{
public:
    PCQueue() : m_sem(), m_queue(), m_lock(), producer_await(0){
        pthread_mutex_init(&m_lock, nullptr);
    }

    // Blocks while queue is empty. When queue holds items, allows for a single
    // thread to enter and remove an item from the front of the queue and return it.
    // Assumes multiple consumers.
    T pop() {
        while (producer_await) { // try to give producer priority
            sched_yield();
        }
        m_sem.down();
        pthread_mutex_lock(&m_lock);
        T m_obj = m_queue.front();
        m_queue.pop();
        pthread_mutex_unlock(&m_lock);
        return m_obj;
    }

    // Allows for producer to enter with *minimal delay* and push items to back of the queue.
    // Hint for *minimal delay* - Allow the consumers to delay the producer as little as possible.
    // Assumes single producer
    void push(const T& item) {
        producer_await = true;  // assume only one producer, so bool should be fine
        pthread_mutex_lock(&m_lock);
        m_queue.push(item);
        producer_await = false;
        pthread_mutex_unlock(&m_lock);
        m_sem.up();
    }

private:
    Semaphore m_sem;
    queue<T> m_queue;
    pthread_mutex_t m_lock;
    bool producer_await;  // try to give producer priority
};
// Recommendation: Use the implementation of the std::queue for this exercise
#endif
