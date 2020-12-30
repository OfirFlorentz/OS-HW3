typedef struct mutex {
    singlephore h;
} mutex;
void mutex_init(mutex* m) {
    singlephore_init(&(m->h));
}
void mutex_lock(mutex* m) {
    H(&(m->h), 0, -1);
}
void mutex_unlock(mutex* m) {
    H(&(m->h), -1, 1);
}



typedef struct condvar {
    mutex m;
    singlephore h;
    int num_waiting; // we will hold a counter of the number of tasks waiting
} condvar;
// Initilize the condition variable
void cond_init(condvar* c) {
    singlephore_init(&(c->h));
    mutex_init(&(c->m));
    num_waiting = 0;
}
// Signal the condition variable
void cond_signal(condvar* c) {
    // we need to signal only if there is waiting task
    mutex_lock(&(c->m));
    if (c->num_waiting != 0) {י
                H(&c->h, INT_MIN, 1);
        c->num_waiting--;
    }
    mutex_unlock(&(c->m));
}
// Block until the condition variable is signaled. The mutex m must be locked by the
// current thread. It is unlocked before the wait begins and re-locked after the wait
// ends. There are no sleep-wakeup race conditions: if thread 1 has m locked and
// executes cond_wait(c,m), no other thread is waiting on c, and thread 2 executes
// mutex_lock(m); cond_signal(c); mutex_unlock(m), then thread 1 will always recieve the
// signal (i.e., wake up).
void cond_wait(condvar* c, mutex* m) {
    //c->num_waiting++ is critical section, we need to prevent two thread to use it in the same time
    mutex_lock(&(c->m));
    c->num_waiting++;
    mutex_unlock(&(c->m));

    // the mutex from func came locked. we need to unlock it so other tasks could use it
    mutex_unlock(m);
    H(&c->h, 0.5, -1);
    mutex_lock(m);
}


typedef struct singlephore_waiter {
    int bound;
    cond_t cv;
} singlephore_waiter;

typedef struct singlephore {
    mutex m;
    int value;
    std::vector<singlephore_waiter*> waiters;
    // YOUR CODE HERE (if necessary)
} singlephore;

void singlephore_init(singlephore *h) {
    h->value = 0;
    mutex_init(&h->m);
    h->waiters = std::vector<singlephore_waiter*>();
}

void H(singlephore *h, int bound, int delta) {
    mutex_lock(&h->m);
    if (h->value < bound) {
        singlephore_waiter hw;
        hw.bound = bound;
        cond_init(&h->cv);
        h->waiters.pushback(*hw);
        while(h->value < bound)
            cond_wait(&(hw->cv), &(h->m))
    }

    h->value += delta;


    if (delta > 0) {
        for(auto& it : waiters)
            if(h->value >= it->bound) {
                cond_signal(&(it->cv));
            }
    }

    mutex_unlock(&h->m);
}


