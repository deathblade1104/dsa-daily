class Solution {
    private int n;
    private int[]dp;
    
    private int helper(int curr,int[] cost){
        
        if(curr>=n)
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        
        return dp[curr] = cost[curr] + Math.min(helper(curr+1,cost), helper(curr+2,cost));
        
    }
    public int minCostClimbingStairs(int[] cost) {
        
        n = cost.length;
        dp = new int[n+1];
        Arrays.fill(dp,-1);
        helper(0,cost);
        return Math.min(dp[0],dp[1]);
        
        
    }
}