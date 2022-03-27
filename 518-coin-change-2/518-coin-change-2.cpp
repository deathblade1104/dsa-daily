class Solution {
public:
    int dp[5001];
    
    int change(int amt, vector<int>& coins) {
        
        int n=coins.size();        
        memset(dp,0,sizeof(dp));
        
        dp[0] = 1;
        for(int i=0; i<n; i++)
            for(int j=coins[i]; j<=amt; j++)
                dp[j] += dp[j-coins[i]];

    return dp[amt];
        
    }
};