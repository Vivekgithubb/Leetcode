class ZeroEvenOdd {
private:
    int n;
    int turn;
    int count;
    mutex m;
    condition_variable cv;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->turn = 0;
        this->count = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(count <= n){  
            unique_lock<mutex>lock(m);
            while(turn != 0 && count <= n){
                cv.wait(lock);
            }
            if(count <= n){
                printNumber(0);
                turn = (count % 2 == 0 ? 1 : 2);
            }            

            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(count <= n){  
            unique_lock<mutex>lock(m);
            while(turn != 1 && count <= n){
                cv.wait(lock);
            }
            if(count <= n){
                printNumber(count);
                count++;
                turn = 0;
            }
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(count <= n){  
            unique_lock<mutex>lock(m);
            while(turn != 2 && count <= n){
                cv.wait(lock);
            }
            if(count <= n){
                printNumber(count);
                count++;
                turn = 0;
            }
            cv.notify_all();
        }        
    }
};