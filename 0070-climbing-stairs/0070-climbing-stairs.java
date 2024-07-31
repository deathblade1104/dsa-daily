class Solution {
    private int[] dp;
    
    private int helper(int curr,int n){
        
        if(curr>n)
            return 0;
        
        if(curr == n)
            return 1;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        return dp[curr] = helper(curr+1,n) + helper(curr+2,n);
        
    }
    
    public int climbStairs(int n) {
        dp = new int[n+1];    
        for(int i=0;i<n;i++){
            dp[i] = -1;
        }    
        return helper(0,n);
    }
}