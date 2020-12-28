

// Threads & Synchronization
#include <pthread.h>
#include "../Code_Skeleton/Part1/PCQueue.cpp"

#define MAX_THREAD 100
#define MAX_THREAD_EXTRA 5000
#define MAX_CORES 5

PCQueue<int> m_q = PCQueue<int>();

void Test1 (){
    PCQueue<int> m_q = PCQueue<int>();
    m_q.push(5);
    int x = m_q.pop();
    assert(x==5);
}


void Test2 (){

    int x = m_q.pop();
    m_q.push(5);
    assert(x==5);
}

void Test3 (){
    PCQueue<int> m_q = PCQueue<int>();
    int x = m_q.pop();
    int y = m_q.pop();
    m_q.push(5);
    m_q.push(4);
    assert(x==5);
    assert(y==4);
}

void* push(void* arg){
    int* x = static_cast<int*>(arg);
    m_q.push(*x);
}

void* pop(void* arg) {
    int* x = static_cast<int*>(arg);
    *x = m_q.pop();
}

int main(){

    cout << "***************************** test 1 *****************************" << endl;
    pthread_t tg0, tg1;
    int x;
    int y = 1;
    pthread_create(&tg0, nullptr, pop, &x);
    pthread_create(&tg1, nullptr, push, &y);
    sleep(2);
    cout << x << endl;
    assert(x == 1);

}

