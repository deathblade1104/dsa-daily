class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {        
        vector<int>ans;
        deque<int>dq;
        
        for(int i=0;i<k;i++)
        {
            while(dq.size()>0 and nums[dq.back()]<=nums[i])
                dq.pop_back();
            
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        
        for(int i=k;i<nums.size();i++)
        {
            while(dq.size()>0 and dq.front()<=(i-k))
                dq.pop_front();
            
             while(dq.size()>0 and nums[dq.back()]<=nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            ans.push_back(nums[dq.front()]);        
        }
        
        return ans;
    }
};