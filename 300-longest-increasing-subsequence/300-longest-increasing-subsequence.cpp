class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>dp(nums.size(),1);
        int ans =0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    dp[i] = max(dp[j]+1,dp[i]);        
            }   
            
            ans= max(ans,dp[i]);
        }
        
        return ans;
    }
};