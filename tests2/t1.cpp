#include "../Code2/Headers.hpp"
#include "../Code2/Semaphore.hpp"
#include <pthread.h>

#define MAX_THREAD 100
#define MAX_THREAD_EXTRA 1000
#define MAX_CORES 5

int tt = 4;
Semaphore sem = Semaphore(tt);
Semaphore sem1;
int global_tmp = 1;

Semaphore sem0;



void* d1(void* arg)
{
    //wait
    sem0.down();
    cout<< "Entered.." << endl;

    //critical section
    sleep(1);
    cout << "Do something for the " << global_tmp++ << " time" << endl;

    //signal
    cout<< "Just Exiting.." << endl;
    sem0.up();
}

void test1() {
    cout << "***************************** test 1 *****************************" << endl;

    sem0.up();

    int tg_size = 10;
    pthread_t tg0 [tg_size];

    for(int i = 0; i < tg_size; ++i) { // start all threads to begin work
        pthread_create(&tg0[i], nullptr, d1, nullptr);
    }
    for(int i = 0; i < tg_size; ++i) { // wait for all threads to finish
        pthread_join(tg0[i], nullptr);
    }
}


void* d2(void* arg)
{
    sem.down();
    cout << "..." << global_tmp++ << "..." << endl;
    sleep(2);
    sem.up();
}

void test2() {
    cout << "***************************** test 2 *****************************" << endl;

    int tg_size = 20;
    pthread_t tg0 [tg_size];

    for(int i = 0; i < tg_size; ++i) { // start all threads to begin work
        pthread_create(&tg0[i], nullptr, d2, nullptr);
    }
    for(int i = 0; i < tg_size; ++i) { // wait for all threads to finish
        pthread_join(tg0[i], nullptr);
    }
}


int main(){
//    test1();
    test2();

/*

    sleep(2);
    cout << "\n***************************** test 2 *****************************" << endl;
    global_tmp = 0;

    pthread_t thread_group [MAX_THREAD];

    for(int i = 0; i < MAX_THREAD; ++i) { // start all threads to begin work
        pthread_create(&thread_group[i], nullptr, f1, nullptr);
    }

    for(int i = 0; i < MAX_THREAD; ++i) { // wait for all threads to finish
        pthread_join(thread_group[i], nullptr);
    }

    sleep(2);
    cout << "\n***************************** test 3 *****************************" << endl;
    cout << "********************* test multi thread running ******************" << endl;
    global_tmp = 0;

    pthread_t tp2 [MAX_THREAD_EXTRA];

    for(int i = 0; i < MAX_THREAD_EXTRA; ++i) { // start all threads to begin work
        pthread_create(&tp2[i], nullptr, f2, nullptr);
    }

    for(int i = 0; i < MAX_THREAD_EXTRA; ++i) { // wait for all threads to finish
        pthread_join(tp2[i], nullptr);
    }


    sleep(2);

    cout << "\n***************************** test 4 *****************************" << endl;
    cout << "********************* test multi thread running ******************" << endl;
    global_tmp = 1;

    pthread_t tp3 [50];

    for(int i = 0; i < 50; ++i) { // start all threads to begin work
        pthread_create(&tp3[i], nullptr, f3, nullptr);
    }

    for(int i = 0; i < 50; ++i) { // wait for all threads to finish
        pthread_join(tp3[i], nullptr);
    }


    sleep(2);

    cout << "\n***************************** test 5 (d2) *****************************" << endl;
    cout << "********************* test multi thread running ******************" << endl;
    global_tmp = 1;

    pthread_t tp4 [MAX_THREAD_EXTRA];

    for(int i = 0; i < MAX_THREAD_EXTRA; ++i) {
        pthread_create(&tp4[i], nullptr, d2, nullptr);
    }

    for(int i = 0; i < MAX_THREAD_EXTRA; ++i) {
        pthread_join(tp4[i], nullptr);
    }

    return 0;
*/
}

