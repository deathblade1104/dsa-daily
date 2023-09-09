class Solution {
public:
    
    int dp[1001];
    int n;
    
    int helper(int sum, vector<int>&nums){
        
        if(sum == 0)
            return 1;
        
        if(dp[sum]!=-1)
            return dp[sum];
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            
            if(nums[i]>sum)
                break;
            
            ans+=helper(sum-nums[i],nums);
        }
        
        return dp[sum] = ans;
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        n = nums.size();
        
        memset(dp,-1,sizeof dp);
        
        return helper(target,nums);
    }
};