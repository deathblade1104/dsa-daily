class Solution {
public:
    
    int mod;
    int dp[101][101][101];
    int helper(int i,int n,int currProfit,int&minProfit,int&sz, vector<int>& group, vector<int>& profit){
        
        if(i>=sz)
            return currProfit>=minProfit;
        
        if(n<0)
            return 0;
        
        if(dp[i][n][currProfit]!=-1)
            return dp[i][n][currProfit];
        
        int ans = 0;
        int consider = 0;
        if(group[i]<=n)
        consider = helper(i+1,n-group[i],min(minProfit,currProfit+profit[i]),minProfit,sz,group,profit);
        
        consider%=mod;
        
        int dontConsider = helper(i+1,n,currProfit,minProfit,sz,group,profit);
        
        dontConsider%=mod;
        
        
        return dp[i][n][currProfit] = ((consider + dontConsider)%mod);
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int sz = group.size();
        mod = 1e9 + 07;
        memset(dp,-1, sizeof dp);
        return helper(0,n,0,minProfit,sz,group,profit);
    }
};