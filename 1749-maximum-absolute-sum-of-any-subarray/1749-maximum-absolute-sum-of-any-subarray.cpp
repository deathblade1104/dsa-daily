class Solution {
public:
    
    int minSubArray(vector<int>& nums) {
        int ans=nums[0], curr=nums[0];
        
        for(int j=1;j<nums.size();j++)
        {
            int i = nums[j];
            curr =  min(i, curr+i);
            ans = min(curr, ans);
        }
        
        return ans;    
    }
    
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0], curr=nums[0];
        
        for(int j=1;j<nums.size();j++)
        {
            int i = nums[j];
            curr =  max(i, curr+i);
            ans = max(curr, ans);
        }
        
        return ans;    
    }
    
    int maxAbsoluteSum(vector<int>& nums) {
        
        return max(maxSubArray(nums), abs(minSubArray(nums)));
    }
};