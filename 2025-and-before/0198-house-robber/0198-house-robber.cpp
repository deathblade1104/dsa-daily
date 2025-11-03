class Solution {
public:
    int dp[101];
    
    int helper(int curr, vector<int>&nums, int&n){
        
        if(curr>=n)
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        return dp[curr] = max(nums[curr] + helper(curr+2,nums,n), helper(curr+1,nums,n));
    }
    
    int rob(vector<int>& nums) {
        
        memset(dp,-1,sizeof dp);
        int n = nums.size();
        
        return helper(0,nums,n);
    }
};