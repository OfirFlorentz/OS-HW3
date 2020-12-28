#include "../Code_Skeleton/Part1/Headers.hpp"
#include "../Code_Skeleton/Part1/Semaphore.hpp"


// Threads & Synchronization
#include <pthread.h>
#include "../Code_Skeleton/Part1/PCQueue.hpp"

#define MAX_THREAD 100
#define MAX_THREAD_EXTRA 5000
#define MAX_CORES 5



void Test1 (){
    PCQueue<int> m_q = PCQueue<int>();
    int x = m_q.pop();
    m_q.push(5);
    assert(x==5);
}

void Test2 (){
    PCQueue<int> m_q = PCQueue<int>();
    int x = m_q.pop();
    int y = m_q.pop();
    m_q.push(5);
    m_q.push(4);
    assert(x==5);
    assert(y==4);
}


int main(){

    cout << "***************************** test 1 *****************************" << endl;
    Test1();
    cout << "***************************** test 2 *****************************" << endl;
    Test2();

}

