class TimeMap {
public:
    unordered_map<string,vector<int>>key_time;;
    unordered_map<int,string>time_value;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        key_time[key].push_back(timestamp);
        time_value[timestamp] = value;
        
    }
    
    int helper (vector<int>&arr,int&target)
    {
        int low=0, high= arr.size()-1;
        int ans=0;
        while(low<=high)
        {
            int mid = low + ((high - low)/2);
            
            if(arr[mid]<=target)
            {
                ans = arr[mid];
                low = mid+1;
            }
            
            else 
            high = mid - 1;
        }
        
        return ans;
    }
    string get(string key, int timestamp) {
        
        if(key_time.count(key)==1)
        {
            int curr_time = helper(key_time[key],timestamp);
            return time_value[curr_time];
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */