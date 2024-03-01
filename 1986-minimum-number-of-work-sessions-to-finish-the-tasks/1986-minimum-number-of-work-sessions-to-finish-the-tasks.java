class Solution {
    private int t,n;
    private int finalState;
    private int[][] dp;
    
    private int helper(int currState, int currTime, int[] tasks){

        if(currState == finalState){
            return 1;
        }

        if(dp[currTime][currState] != -1) return dp[currTime][currState];

        int ans = Integer.MAX_VALUE/2;

        for(int i=0; i<n; i++){

            int currPow = (1 << i);

            if ((currPow & currState) != 0)
                continue;

            int newState = (currState | currPow);

            if(currTime + tasks[i] <= t){
                ans = Math.min(ans, helper(newState, currTime + tasks[i], tasks));
            } else {
                ans = Math.min(ans, 1 + helper(newState, tasks[i], tasks));
            }
        }

        return dp[currTime][currState] = ans;
    }
    public int minSessions(int[] tasks, int sessionTime) {
        this.t = sessionTime;
        this.n = tasks.length;
        finalState = (1<<n) -1;
        
        dp = new int[t+1][finalState + 1];
        
        for(int i=0;i<=t;i++){
            for(int j=0;j<=finalState;j++)
                dp[i][j]=-1;
        }
        
        
        return helper(0,0,tasks);
        
    }
}