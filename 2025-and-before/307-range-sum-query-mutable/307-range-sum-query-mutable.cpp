class NumArray {
public:
    vector<int>segmentTree;
    int sz;
    NumArray(vector<int>& nums) {
        sz = nums.size();
        segmentTree.resize(sz*4,0);
        int x = makeSegTree(0,sz-1,0,nums);
    }
    
    void update(int index, int val) {
        updateSegTree(0,sz-1,0,index,val);
    }
    
    int sumRange(int left, int right) {
        return getSum(0,sz-1,left,right,0);
    }
    
    int makeSegTree(int start, int end , int idx, vector<int>&nums)
    {
        if(start>end)
            return 0;
        
        if(start == end)
            return segmentTree[idx] = nums[start];
        
        int mid = start + ((end - start)/2);
        
        return segmentTree[idx] = makeSegTree(start,mid,idx*2+1,nums) + makeSegTree(mid+1,end,idx*2+2,nums);
    }
    
    
    int getSum(int start, int end, int left, int right, int idx)
    {
        if(end<left or start>right or start>end)
            return 0;
        
        else if(start>=left and end<=right)
            return segmentTree[idx];
        
        int mid = start + (end - start)/2;
        return getSum(start,mid,left,right,idx*2 + 1) + getSum(mid+1,end,left,right,idx*2+2);
    }
    
    void updateSegTree(int start,int end, int curr_idx, int&idx, int&val)
    {
        if(start>end)
            return;
        
        if(start == end) {
            if(start == idx)
                segmentTree[curr_idx] = val;
            
            return;
        }
        
        int mid = start + (end - start)/2;
        
        if(idx<=mid){
            updateSegTree(start,mid,curr_idx*2+1,idx,val);
        }else {
            updateSegTree(mid+1,end,curr_idx*2+2,idx,val);
        }
        
        segmentTree[curr_idx]= segmentTree[curr_idx*2 + 1] + segmentTree[curr_idx*2 + 2];
        return;
    }
    
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */