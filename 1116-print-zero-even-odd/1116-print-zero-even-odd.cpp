class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cv;
    int count;
    int turn;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->count = 1;
        this->turn = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(count<= n){
            unique_lock<mutex> lock(m);
            while(count <= n && turn != 0)
                cv.wait(lock);
            
            if(count <= n){
                printNumber(0);
                turn = (count %2 == 0 ? 1 : 2);
            }
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(count <=n){
            unique_lock<mutex> lock(m);
            while(count <= n && turn != 1)
                cv.wait(lock);
            if(count <=n){
                printNumber(count);
                count++;
                turn = 0;
            }
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(count <= n){
            unique_lock<mutex> lock(m);
            while(count <= n && turn != 2 )
                cv.wait(lock);
            if(count <=n){
                printNumber(count);
                count++;
                turn = 0;
            }
            cv.notify_all();         
        }
    }
};