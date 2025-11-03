class Solution {
public:
    
    unordered_map<int,int>dp[21];
    int sz;
    
    int helper(int curr,int target, vector<int>&nums){
        
        if(curr>=sz){
            return target == 0;
        }
        
        if(dp[curr].count(target))
            return dp[curr][target];
        
        return dp[curr][target] = helper(curr+1,target-nums[curr],nums) +           helper(curr+1,target+nums[curr],nums);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        sz = nums.size();
        
        for(int i=0;i<sz;i++)
            dp[i].clear();
        
        return helper(0,target,nums);
        
    }
};