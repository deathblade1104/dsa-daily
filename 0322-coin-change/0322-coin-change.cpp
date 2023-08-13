class Solution {
public:
    int dp[13][10001];
    int sz;
    
    int helper(int curr, int amt, vector<int>&coins){
        
        if(curr>=sz or amt<0)
            return 100001;
        
        if(amt == 0)
            return 0;
        
        if(dp[curr][amt]!=-1)
            return dp[curr][amt];
        
        return dp[curr][amt] = min(1 + helper(curr,amt-coins[curr],coins) , helper(curr+1,amt,coins));
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof dp);
        sz  = coins.size();
        int ans  = helper(0,amount,coins);
        
        if(ans>=100001)
            return -1;
        
        return ans;
    }
};