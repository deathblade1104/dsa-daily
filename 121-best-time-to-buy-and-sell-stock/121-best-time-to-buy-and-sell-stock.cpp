class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>dp(prices.size());
        dp[prices.size()-1]=INT_MIN/2;
        
        
        for(int i=prices.size()-2;i>=0;i--)
        dp[i]= max(prices[i+1], dp[i+1]);
        
        
        int ans=0;
        
        for(int i = 0;i<dp.size();i++)
        ans=max(ans, dp[i]-prices[i]);
        
        return ans;
    }
};