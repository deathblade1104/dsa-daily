class Solution {
    
    private int n,k,finalState;
    private int[] subsetSum;
    private int[][] dp;
    
    
    private int helper(int workers,int currState, int[] jobs){
        
        if(workers == k && currState == finalState){
            return 0;
        }
        
        if(currState == finalState || workers == k)
            return Integer.MAX_VALUE/2;
        
        if(dp[workers][currState]!=-1)
            return dp[workers][currState];
        
        int ans = Integer.MAX_VALUE/2;
        
        
        for(int i=1;i<=finalState;i++){
            
            if((i & currState)!=0)
                continue;

            int newState = i | currState;
            ans = Math.min(ans,Math.max(subsetSum[i],helper(workers+1,newState,jobs)));
        }
        
        
        return dp[workers][currState] =  ans;
    }
    
     public int distributeCookies(int[] jobs, int k) {
        n = jobs.length;
        this.k = k;
        finalState = (1<<n) - 1;
        subsetSum = new int[finalState + 1];
        
        Arrays.fill(subsetSum,0);
        
        for(int i=1;i<=finalState;i++){
            for(int j=0;j<n;j++){
                if(((1<<j) & i) !=0)
                    subsetSum[i]+=jobs[j];
            }
        }
        
        dp = new int[k+1][finalState+1];
        
        for(int i=0;i<=k;i++)
            Arrays.fill(dp[i],-1);
        
        return helper(0,0,jobs);
    }
}