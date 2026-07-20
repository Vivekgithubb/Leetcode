class DiningPhilosophers {
public:
    mutex fork[5];
    mutex m , l;
    //max value , initial value
    counting_semaphore<4> permit{4};
    DiningPhilosophers() {

    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) { 
        permit.acquire();
            fork[philosopher].lock();		
            fork[(philosopher+1) % 5].lock();
            pickLeftFork();
            pickRightFork();
            
            eat();
            
            putLeftFork();
            putRightFork();
            fork[philosopher].unlock();		
            fork[(philosopher+1) % 5].unlock();
        permit.release();
    }
};