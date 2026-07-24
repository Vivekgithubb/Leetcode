class FooBar {
private:
    int n;
    mutex m;
    int turn;
    condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        turn = 1;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	while(turn == 2)
                cv.wait(lock);
            printFoo();
            turn = 2;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            while(turn == 1)
                cv.wait(lock);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn = 1;
            cv.notify_all();
        }
    }
};