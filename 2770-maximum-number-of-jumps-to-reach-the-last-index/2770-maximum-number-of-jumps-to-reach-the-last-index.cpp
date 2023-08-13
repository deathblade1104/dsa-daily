class Solution {
public:
    int dp[1001];
    int tar,sz;
    
    int helper(int curr,vector<int>& nums){
        
        if(curr == sz-1)
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        
        int ans = INT_MIN/2;
        for(int i=curr+1;i<sz;i++){
            if(abs(nums[i] - nums[curr])<=tar){
                ans = max(ans,1 + helper(i,nums));
            }
        }
        
        return dp[curr] = ans;
        
    }
    int maximumJumps(vector<int>& nums, int target) {
        memset(dp,-1,sizeof dp);
        
        tar = target;
        sz = nums.size();
        int ans  = helper(0,nums);
        
        if(ans<0)
            return -1;
        
        return ans;
    }
};