class Solution {
public:
    
   int earnedProfit(vector<int>& prices,int &sz,int curr,int can_buy,int transaction,int bal, int dp[100001][2])
    {
        if(curr>=sz || transaction<=0)
        return 0;
            
        if(dp[curr][can_buy]!=-1)
            return dp[curr][can_buy];
       
       int idle= earnedProfit(prices,sz,curr+1,can_buy,transaction,bal,dp);
       int buy=0,sell=0;
            
        if(can_buy)
            buy=-prices[curr] + earnedProfit(prices,sz,curr+1,0,transaction,prices[curr],dp);

        else
        {       
          if(prices[curr]>=bal)  
          sell=prices[curr] + earnedProfit(prices,sz,curr+1,1,transaction-1,0,dp);
        }
        dp[curr][can_buy]=max(idle,max(buy,sell));
       
        return dp[curr][can_buy];
    }

         
    int maxProfit(vector<int>& prices) {
        
        int sz=prices.size();
        
        int dp[100001][2];
        memset(dp,-1,sizeof(dp));
        
        return earnedProfit(prices,sz,0,1,1,0,dp);
    }
};