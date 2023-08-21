class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        auto p = make_pair(timestamp,value);
        mp[key].push_back(p);
    }
    
    string get(string key, int timestamp) {
        int low  = 0, high = mp[key].size() -1,ans = -1;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(mp[key][mid].first<=timestamp){
                ans = mid;
                low = mid + 1;
            }
            
            else high = mid - 1;
        }
        
        if(ans == -1)
            return "";
        
        return mp[key][ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */