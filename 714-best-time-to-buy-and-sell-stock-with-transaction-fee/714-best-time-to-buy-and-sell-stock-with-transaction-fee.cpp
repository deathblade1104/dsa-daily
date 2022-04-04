class Solution {
public:
    int dp[50001][2];
    int f=-1;
    int get_ans(int curr,int can_buy, int n , vector<int>&prices)
    {
        if(curr>=n) return 0;
        
        if(dp[curr][can_buy]!=-1)
            return dp[curr][can_buy];
        
        int idle = get_ans(curr+1,can_buy,n,prices),buy=0,sell=0;
        
        if(can_buy)
            buy =  get_ans(curr+1,0,n,prices) - prices[curr];
        
        else
            sell = prices[curr] - f + get_ans(curr+1,1,n,prices);
        
        return dp[curr][can_buy] = max({idle,buy,sell});
        
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        f=fee;
        memset(dp,-1,50001*2*sizeof(int));
        int n=prices.size();        
        return get_ans(0,1,n,prices);
        
    }
};