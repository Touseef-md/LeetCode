class MyHashSet {
public:
    unordered_map<int,int> mp;
    MyHashSet() {
        
    }
    
    void add(int key) {
        mp[key]++;
    }
    
    void remove(int key) {
        mp.erase(key);
    }
    
    bool contains(int key) {
        auto it=mp.find(key);
        if(it!=mp.end())
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */