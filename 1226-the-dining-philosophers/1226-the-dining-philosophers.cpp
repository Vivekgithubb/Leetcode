class DiningPhilosophers {
public:
    mutex fork[5];
    mutex m , l;
    DiningPhilosophers() {

    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        lock_guard<mutex> lock(m);
        
        fork[philosopher].lock();		
        pickLeftFork();
        fork[(philosopher+1) % 5].lock();
        pickRightFork();
        
        eat();
        
        fork[philosopher].unlock();		
        putLeftFork();
        fork[(philosopher+1) % 5].unlock();
        putRightFork();
    }
};