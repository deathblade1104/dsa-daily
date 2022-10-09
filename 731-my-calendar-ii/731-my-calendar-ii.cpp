class MyCalendarTwo {
public:
    
    map<int,int>mp;
    MyCalendarTwo() {
        mp.clear();
    }
    
    
    bool check(){
        
        int curr=0;
        
        for(auto&it : mp){
            
            curr+=it.second;
            
            if(curr>=3)
                return false;
        }
        
        return true;
    }
    
    bool book(int start, int end) {
        
        mp[start]++;
        mp[end]--;
        
        bool ans = check();
        
        if(!ans){
            mp[start]--;
            mp[end]++;
        }
        
        return ans;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */