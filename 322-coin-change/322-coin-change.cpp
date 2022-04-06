class Solution {
public:
    int dp[10001];
    int get_ans(int curr,vector<int>&coins)
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
               temp = 1 + get_ans(curr-coins[i],coins);
            
            
            ans=min(ans,temp);
            
            if(coins[i]>curr)
                break;
        }
        
        return dp[curr]=ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        memset(dp,-1, sizeof(dp));
        
        int ans = get_ans(amount,coins);
        
        if(ans>=INT_MAX/2)
            return -1;
        
        return ans;
    }
};