class Solution {
public:
    
    int dp[5001][2];
    int helper(int curr,bool canBuy, vector<int>&prices){
        if(curr>=prices.size())
            return 0;
        
        if(dp[curr][canBuy]!=-1){
            return dp[curr][canBuy];
        }
        
        int doNothing = helper(curr+1,canBuy,prices);
        
        int sold=INT_MIN,buy=INT_MIN;
        
        if(canBuy){
            
            buy = -prices[curr] + helper(curr+1,false,prices);
        }
        
        else{
            sold = prices[curr] + helper(curr+2,true,prices);
        }
        
        
        return dp[curr][canBuy]= max({doNothing,sold,buy});
    }
    int maxProfit(vector<int>& prices) {
        
        memset(dp,-1,sizeof dp);
        return helper(0,1,prices);
        
    }
};