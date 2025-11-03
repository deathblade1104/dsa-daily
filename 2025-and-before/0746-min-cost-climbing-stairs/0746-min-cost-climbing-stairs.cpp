class Solution {
public:
    int dp[1001];
    int n;
    
    int helper(int curr,vector<int>&arr){
        
        if(curr>=n)
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        return dp[curr] = arr[curr] + min(helper(curr+1,arr) , helper(curr+2,arr));
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof dp);
        n  = cost.size();
        
        return min(helper(0,cost), helper(1,cost));
    }
};