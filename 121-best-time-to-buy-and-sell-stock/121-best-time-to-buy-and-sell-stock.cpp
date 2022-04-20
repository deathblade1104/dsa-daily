class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=INT_MIN/2,ans=0;
        for(int i = prices.size()-2;i>=0;i--)
        {
            m = max(prices[i+1],m);
            ans= max(ans, m - prices[i]);
        }
        
        return ans;
    }
};