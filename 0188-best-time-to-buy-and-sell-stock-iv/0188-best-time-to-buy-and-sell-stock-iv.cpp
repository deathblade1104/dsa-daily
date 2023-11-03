class Solution {
public:
    int dp[100001][2][101];
    int sz;
    int helper(int curr,bool canBuy,int t,vector<int>&arr){
        
        if(curr>=sz || t<=0)
            return 0;
        
        if(dp[curr][canBuy][t]!=-1)
            return dp[curr][canBuy][t];
        
        int idle = helper(curr+1,canBuy,t,arr),buy=INT_MIN/2,sell=INT_MIN/2;
        
        if(canBuy)
            buy = -arr[curr] + helper(curr+1,false,t,arr);
        
        else
            sell = arr[curr] + helper(curr+1,1,t-1,arr);
        
        return dp[curr][canBuy][t] = max({idle,buy,sell});
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        sz=prices.size();
        memset(dp,-1,sizeof dp);
        
       return max(0,helper(0,1,k,prices));
        
    }
};