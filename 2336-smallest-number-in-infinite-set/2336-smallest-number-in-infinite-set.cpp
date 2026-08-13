class SmallestInfiniteSet {
public:
    vector<int>dq;
    SmallestInfiniteSet() {
        dq = vector<int>(1001,1);
    }
    
    int popSmallest() {
        for(int i=1;i<=1000 ; i++)
            if(dq[i] == 1){ 
                dq[i] = 0;
                return i;
            }
        return 0;
    }
    
    void addBack(int num) {
        if(dq[num] == 0)
            dq[num] = 1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */