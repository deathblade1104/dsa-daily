class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>suffix(n,-1);
        suffix[n-1] = nums.back();
    
        for(int i=n-2;i>=0;i--)
        suffix[i] = max(nums[i],suffix[i+1]);
        
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(nums[0]);
        
        for(int i=1;i<n-1;i++){
            
            pq.push(nums[i]);
            
            int op1 = pq.top(), op2=suffix[i];
            
            if(op1<nums[i] and nums[i]<op2)
                return true;
            
        }
        
        return false;
        
    }
};