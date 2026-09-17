class LRUCache {
public:
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> mpp;
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    void makeMostRecent(int key){
        dll.erase(mpp[key].first);
        dll.push_front(key);
        mpp[key].first=dll.begin();
    }
    int get(int key) {
        if(!mpp.count(key))
            return -1;
        makeMostRecent(key);
        return mpp[key].second;
    }
    
    void put(int key, int value) {
        if(mpp.count(key)){
            mpp[key].second=value;
            makeMostRecent(key);
        }
        else{
            dll.push_front(key);
            mpp[key]={dll.begin(),value};
            capacity--;
        }
        while(capacity<0){
            mpp.erase(dll.back());
            dll.pop_back();
            capacity++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */