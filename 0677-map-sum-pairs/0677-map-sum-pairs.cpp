class MapSum {
public:
    unordered_map<string,int>mp1,mp2;
    MapSum() {
        mp1.clear();
        mp2.clear();
    }
    
    void insert(string key, int val) {
        
        int prev = mp2[key];
        
        string curr = "";
        
        for(char&ch : key){
            curr+=ch;
            mp1[curr]+=(val-prev);
        }
        
        mp2[curr] = val;
    }
    
    int sum(string prefix) {
        
        return mp1[prefix];
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */