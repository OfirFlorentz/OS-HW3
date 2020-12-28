//
// Created by student on 12/27/20.
//

#include "PCQueue.hpp"

template <typename T>
PCQueue<T>::PCQueue() : m_sem(0), m_queue(){
    pthread_mutex_init(&m_lock, nullptr);
};

template <typename T>
T  PCQueue<T>::pop() {
    m_sem.down();
    pthread_mutex_lock(&m_lock);
    T m_obj = m_queue.pop();
    pthread_mutex_unlock(&m_lock);
    return m_obj;
}

template <typename T>
void  PCQueue<T>::push(const T& item) {
    pthread_mutex_lock(&m_lock);
    T m_obj = m_queue.pop();
    pthread_mutex_unlock(&m_lock);
    m_sem.up();
}
