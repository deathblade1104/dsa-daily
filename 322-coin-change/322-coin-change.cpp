class Solution {
public:
    int helper(int curr,int amount, vector<int>&coins,vector<vector<int>>&dp)
    {
        if(amount == 0)
            return 0;
        
        if(curr>=coins.size())
            return INT_MAX/2;
        
        if(dp[curr][amount]!=-1)
            return dp[curr][amount];
        
        int consider = INT_MAX/2;
        
        if(coins[curr]<=amount)
            consider = 1 + helper(curr,amount-coins[curr],coins,dp);
            
        int dont_consider = helper(curr+1,amount,coins,dp);
        
        return dp[curr][amount] = min(consider, dont_consider);
    }
    
    int coinChange(vector<int>& coins, int amount) {
    
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        sort(coins.begin(),coins.end());
        
        int ans =  helper(0,amount,coins,dp);
        
        return ans >= INT_MAX/2 ? -1 : ans;
        
        
    }
};