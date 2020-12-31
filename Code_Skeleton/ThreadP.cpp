
#include "Game.hpp"
#include "utils.hpp"
#include "ThreadP.hpp"
#include "Thread.hpp"


ThreadP::ThreadP(uint thread_id) : Thread(thread_id){}

void ThreadP::thread_workload() {
    cout << "works for number " << m_thread_id << " thread" << endl;
}
