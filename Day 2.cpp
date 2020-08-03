class MyHashSet {
    
    vector<vector<int>> buckets;
    int bucketSize;
    
    int hash(int key) {
        return key%bucketSize;
    }
    
    
public:
    /** Initialize your data structure here. */
    
    
    
    MyHashSet() {
        bucketSize = 15000;
        buckets.resize(bucketSize, vector<int>());
    }
    
    void add(int key) {
        
        int i = hash(key);
        
        if(find(buckets[i].begin(),buckets[i].end(), key) == buckets[i].end())
            buckets[i].push_back(key);
        
        
    }
    
    void remove(int key) {
        
        int i = hash(key);
        
        auto it  = find(buckets[i].begin(),buckets[i].end(),key);
        
        if(it != buckets[i].end()) {
            buckets[i].erase(it);
        }
        
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        
        int i = hash(key);
        
        if(find(buckets[i].begin(),buckets[i].end(), key) == buckets[i].end())
            return false;
        
        return true;
        
    }
};
