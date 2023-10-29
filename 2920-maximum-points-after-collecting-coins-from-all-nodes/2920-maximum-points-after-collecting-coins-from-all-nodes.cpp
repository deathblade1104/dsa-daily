class Solution {
public:
    
    vector<int>adj[100001];
    int dp[100001][32];
    int K;

    int helper(int curr,int par,int flag,vector<int>&coins){
        
        if(flag>=32)
            return 0;
        
        if(dp[curr][flag]!=-1)
            return dp[curr][flag];
        
        int currCoins = coins[curr]>>flag;
        int op1 = currCoins - K;
        int op2 = floor(currCoins/2);
        
        for(int&neigh : adj[curr]){
            if(neigh!=par){
                op2+=helper(neigh,curr,flag+1,coins);
                op1+=helper(neigh,curr,flag,coins);
            }
        }
        
        return dp[curr][flag] =  max(op1,op2);
    }
    
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        memset(dp,-1,sizeof dp);
        for(auto&v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        K = k;
        return helper(0,-1,0,coins);
    }
};