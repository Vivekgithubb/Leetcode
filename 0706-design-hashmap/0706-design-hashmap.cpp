

class MyHashMap {
public:
    vector<int>v;
    MyHashMap() {
    }
    
    void put(int key, int value) {
        if(v.size() <= key)
            v.resize(key + 1, -1);
        v[key] = value;
    }
    
    int get(int key) {
        if(v.size() <= key) return -1;
        return v[key] ;
    }
    
    void remove(int key) {  
        if(v.size() < key) return;
        v[key] = -1 ;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */