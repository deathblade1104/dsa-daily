class Solution {
public:
    int n, steps;
    int mod = 1e9 + 7;
    int dp[501][251];
    int helper(int currSteps, int idx){
        
        if(currSteps>=steps)
            return idx == 0;
        
        if(dp[currSteps][idx]!=-1)
            return dp[currSteps][idx];
        
        int op1=0,op2=0,op3 = 0;
        
        op1 = helper(currSteps+1,idx);
        
        if(idx+1<n and idx<steps/2)
            op2  = helper(currSteps+1,idx+1);
        
        if(idx>0)
            op3 = helper(currSteps+1,idx-1);
        
        return dp[currSteps][idx] = ((op1 + op2)%mod + op3)%mod;
    }
    
    int numWays(int s, int arrLen) {
        n = arrLen;
        steps  = s;
        memset(dp,-1,sizeof dp);
        
        return helper(0,0);
        
        
    }
};