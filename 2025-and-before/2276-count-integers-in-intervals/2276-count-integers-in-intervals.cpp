class CountIntervals {
public:
    unordered_map<int,int>segTree;
    
    CountIntervals() {    
    }
    
    void update(int left, int right, int currIdx=1,int start =0, int end = 1e9){
        
        if(start>right or end<left or segTree[currIdx] == end - start +1)
            return;
        
        if(start>=left and end<=right){
            segTree[currIdx] = end - start +1;
            return;
        }
        
        int mid = start + ((end - start)/2);
        
        update(left,right,currIdx*2,start,mid);
        update(left,right,currIdx*2 +1, mid+1, end);
        
        segTree[currIdx] = segTree[currIdx*2] + segTree[currIdx*2+1];
        
        return;
    }
    
    void add(int left, int right){
        update(left,right);
    }
    
    int count() {
        return segTree[1];
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */