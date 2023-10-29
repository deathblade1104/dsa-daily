class Solution {
public:
    
    vector<vector<int>>adj;
    vector<vector<int>>dp;
    int K;

    int helper(int curr,int par,int halfTimes,vector<int>&coins){
        
        if(halfTimes>=32)
            return 0;
        
        if(dp[curr][halfTimes]!=-1)
            return dp[curr][halfTimes];
        
        int currCoins = coins[curr]>>halfTimes;
        int op1 = currCoins - K;
        int op2 = floor(currCoins/2);
        
        for(int&neigh : adj[curr]){
            if(neigh!=par){
                op2+=helper(neigh,curr,halfTimes+1,coins);
                op1+=helper(neigh,curr,halfTimes,coins);
            }
        }
        
        return dp[curr][halfTimes] =  max(op1,op2);
    }
    
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = edges.size() +1 ;
        adj.assign(n+1,vector<int>());
        dp.assign(n+1,vector<int>(32,-1));
    
        for(auto&v : edges){
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }
        K = k;
        return helper(0,-1,0,coins);
    }
};