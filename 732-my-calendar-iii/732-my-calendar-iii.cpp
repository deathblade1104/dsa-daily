class MyCalendarThree {
public:
    unordered_map<int,int>mp;
    unordered_map<int,int>lazy;
    
    void add(int left, int right,int start=0 ,int end=1e9+1,  int currIdx=0){
        
        if(start>end or start>right or end<left)
            return;
        
        if(start>=left and end<=right){
            lazy[currIdx]++;
            mp[currIdx]++;
            return;
        }
    
        int mid = start + ((end  - start)/2);
        
        add(left,right,start,mid,currIdx*2 +1);
        add(left, right,mid+1,end,currIdx*2 +2);
        
        mp[currIdx] = lazy[currIdx] +  max(mp[currIdx*2 +1] , mp[currIdx*2 + 2]);
        
        return;
        
    }
    MyCalendarThree() {
        mp[0]=0;
    }
    
    int book(int start, int end) {
         add(start,end-1);
        
        return mp[0];
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */