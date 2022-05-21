class Solution {
public:
    int helper(int curr,vector<int>&coins,vector<int>&dp)
    {
        if(curr==0)
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        int ans=INT_MAX/2;
        for(int i=0;i<coins.size();i++)
        {
            int temp=INT_MAX/2;
            if(coins[i]<=curr)
               temp = 1 + helper(curr-coins[i],coins,dp);
            
            
            ans=min(ans,temp);
            
            if(coins[i]>curr)
                break;
        }
        
        return dp[curr]=ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
    
        int n = coins.size();
        vector<int>dp(amount+1,-1);
        
        sort(coins.begin(),coins.end());
        
        int ans =  helper(amount,coins,dp);
        
        return ans >= INT_MAX/2 ? -1 : ans;
        
        
    }
};