#ifndef __THREAD_H
#define __THREAD_H

#include "Headers.hpp"

class Thread
{
public:
	Thread(uint thread_id) : m_thread_id(thread_id) {};
	virtual ~Thread() {} // Does nothing


	/** Returns true if the thread was successfully started, false if there was an error starting the thread */
	bool start() {
	    cout << "trying to run threat func for thread num " << m_thread_id << endl;
	    pthread_t tmp[1];
	    return pthread_create(tmp, nullptr, entry_func, nullptr) == 0;
	}

	/** Will not return until the internal thread has exited. */
	void join(){
	    pthread_join(m_thread, nullptr);
	}

	/** Returns the thread_id **/
	uint thread_id(){
        return m_thread_id;
	}

protected:
	/** Implement this method in your subclass with the code you want your thread to run. */
	virtual void thread_workload() = 0;
//	virtual void thread_workload();
//	virtual void thread_workload() {
//	    cout << "hi" << endl;
//	};
	uint m_thread_id; // A number from 0 -> Number of threads initialized, providing a simple numbering for you to use


private:
	static void *  entry_func(void * thread) {
		cout << "inside entry_func. trying to accesses thread_workload" << endl;
        ((Thread *)thread)->thread_workload();
        return NULL;
	}
	pthread_t m_thread;
};

#endif
