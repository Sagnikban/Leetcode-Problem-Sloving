class MyHashMap {
public:
    unordered_map<int,int>m;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        m[key]=value;
        else
        m.insert({key,value});
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        return m[key];
        
        return -1;
    }
    
    void remove(int key) {
        
        if(m.find(key)!=m.end())
        {
         auto it =m.find(key);
    
        m.erase(it);}
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */