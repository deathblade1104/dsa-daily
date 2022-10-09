class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {
        mp.clear();
    }
   bool check(){
        
        int curr=0;
        
        for(auto&it : mp){
            
            curr+=it.second;
            
            if(curr>=2)
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
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */