class Solution {
public:
    
    int dp[5001][2][1001];
    int helper(int curr,bool canBuy,int prev, vector<int>&prices){
        if(curr>=prices.size())
            return 0;
        
        
        if(dp[curr][canBuy][prev]!=-1){
            return dp[curr][canBuy][prev];
        }
        
        int doNothing = helper(curr+1,canBuy,prev,prices);
        
        int sold=INT_MIN,buy=INT_MIN;
        
        
        if(canBuy){
            
            buy = -prices[curr] + helper(curr+1,false,prices[curr],prices);
        }
        
        if(!canBuy and prices[curr]>prev){
            
            sold = prices[curr] + helper(curr+2,true,0,prices);
        }
        
        
        return dp[curr][canBuy][prev] = max({doNothing,sold,buy});
    }
    int maxProfit(vector<int>& prices) {
        
        memset(dp,-1,sizeof dp);
        return helper(0,1,0,prices);
        
    }
};