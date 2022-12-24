class Solution {
public:
    int dp[1001];
    const int mod = 1e9 + 07;
    int numTilings(int n) {
        
        memset(dp,-1,sizeof dp);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        
        
        for(int i=4;i<=n;i++){
            
            dp[i] = (2 * dp[i-1])%mod + dp[i-3]%mod;
            dp[i]%=mod;
        }
        
        return dp[n];
    }
};