class Solution {
public:
    int dp[1001][2][101];
    int earnedProfit(vector<int>& prices,int &sz,int curr,int can_buy,int transaction)
    {
        if(curr>=sz || transaction<=0)
        return 0;
            
        if(dp[curr][can_buy][transaction]!=-1)
            return dp[curr][can_buy][transaction];
       
       int buy=0,sell=0;
            
        if(can_buy)
        buy = max(-prices[curr] + earnedProfit(prices,sz,curr+1,0,transaction),
                    earnedProfit(prices,sz,curr+1,1,transaction));

        else
        sell = max(prices[curr] + earnedProfit(prices,sz,curr+1,1,transaction-1),
                   earnedProfit(prices,sz,curr+1,0,transaction));

        
        return dp[curr][can_buy][transaction]=max(buy,sell);
    }

    int maxProfit(int k, vector<int>& prices) {
        int sz=prices.size();
        
        memset(dp,-1,sizeof dp);
        
        return earnedProfit(prices,sz,0,1,k);
        
    }
};