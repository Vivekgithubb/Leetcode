class FizzBuzz {
private:
    int n;
    int turn;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->turn = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(turn <= n){
            unique_lock<mutex> lock(m);
            while(turn <= n && (turn%3 == 0 && turn%5 !=0) == 0 ){
                cv.wait(lock);
            }
            if(turn <=n){
                printFizz();
                ++turn;
            }
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(turn <= n){
            unique_lock<mutex> lock(m);
            while(turn <= n && (turn%3 != 0 && turn%5 ==  0) == 0){
                cv.wait(lock);
            }
            if(turn <=n){
                printBuzz();
                ++turn;
            }
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(turn <= n){
            unique_lock<mutex> lock(m);
            while(turn <= n && (turn%3 == 0 && turn%5 ==0) == 0 ){
                cv.wait(lock);
            }
            if(turn <=n){
                printFizzBuzz();
                ++turn;
            }
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(turn <= n){
            unique_lock<mutex> lock(m);
            while(turn <= n && (turn%3 != 0 && turn%5 !=0) == 0 ){
                cv.wait(lock);
            }
            if(turn <=n){
                printNumber(turn++);
            }
            cv.notify_all();
        }
    }
};