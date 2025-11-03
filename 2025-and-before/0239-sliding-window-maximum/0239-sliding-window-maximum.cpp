class Solution {
public:
    
    void helper(deque<array<int,2>>&dq,int num){
        
        while(dq.size() and dq.front()[0]<=num)
            dq.pop_front();
    }
    
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>ans;
        deque<array<int,2>>dq;
        
        for(int i=0;i<k;i++){
            helper(dq,nums[i]);
            dq.push_front({nums[i],i});
        }
        
        ans.push_back(dq.back()[0]);
        
        for(int i=k;i<nums.size();i++){
            
            while(dq.size() and dq.back()[1]<=i-k)
                dq.pop_back();
            
            helper(dq,nums[i]);
            dq.push_front({nums[i],i});
            
            ans.push_back(dq.back()[0]);
        }
        
        return ans;
        
    }
};