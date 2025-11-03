class Solution {
public:
    
    int segTree[400005];
    
    int query(int start,int end, int currIdx, int left, int right){
        
        if(start>end or start>right or end<left)
            return 0;
        
        if(start>=left and end<=right)
         return segTree[currIdx];
        
        
        int mid = start + ((end - start)/2);
        
        return max(query(start,mid,currIdx*2 + 1, left,right),
                   query(mid+1,end,currIdx*2 + 2, left, right));
    }
    
    void update(int start, int end, int currIdx, int num, int val){
        
        if(start>end)
            return;
        
        if(start == end)
        {
            if(start == num)
                segTree[currIdx] = max(segTree[currIdx],val);
            
            return;
        }
        
        int mid = start + ((end - start)/2);
        
        if(num<=mid)
            update(start,mid,currIdx*2 + 1,num,val);
        
        else
            update(mid+1,end,currIdx*2 + 2,num,val);
        
        segTree[currIdx] = max(segTree[currIdx*2 +1], segTree[currIdx*2 + 2]);
        
    }

    int lengthOfLIS(vector<int>& nums, int k) {
        
        memset(segTree,0,sizeof segTree);
        
        int ans = -1;
        
        for(int&i : nums){
            int low = max(0, i-k), high = i-1;
            
            int q = query(0,100001,0,low,high) + 1;
            
            ans = max(ans,q);
            
            update(0,100001,0,i,q);
        }
        
        return ans;
    }
};