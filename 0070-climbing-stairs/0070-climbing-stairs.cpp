class Solution {
public:
    int dp[46];
    
    int helper(int curr,int&n){
        
         if(curr == n)
            return 1;
        
        if(curr>n)
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        return dp[curr] = helper(curr+1,n) + helper(curr+2,n);
    }
    
    
    int climbStairs(int n) {
        
        memset(dp,-1,sizeof dp);
        return helper(0,n);
    }
};