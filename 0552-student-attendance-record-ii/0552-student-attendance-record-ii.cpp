class Solution {
public:
    int dp[100001][3][2];
    int mod = 1e9 + 7;
    int helper(int n,int late, int absent){
        
        if(n == 0)
            return 1;
        
        if(dp[n][late][absent]!=-1)
            return dp[n][late][absent];
        
        int ans = 0;
        
        //PRESENT Vaala Scenario
        ans+=helper(n-1,2,absent);
        ans%=mod;

        //absent vaala case
        if(absent>0){
            ans+=helper(n-1,2,absent-1);
            ans%=mod;
        }
        
        //lateCase
        if(late>0){
            ans+=helper(n-1,late-1,absent);
            ans%=mod;
        }
        
        return dp[n][late][absent] = ans%mod;
    
    }
    int checkRecord(int n) {
        
        memset(dp,-1,sizeof dp);
        return helper(n,2,1);
    }
};