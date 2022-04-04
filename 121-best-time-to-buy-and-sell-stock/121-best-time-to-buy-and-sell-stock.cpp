class Solution {
public:
    int dp[100001][2];
    
    int get_ans(int curr,int can_buy, int tc, int n , vector<int>&prices)
    {
        if(curr>=n or tc <=0)
            return 0;
        
        if(dp[curr][can_buy]!=-1)
            return dp[curr][can_buy];
        
        int idle = get_ans(curr+1,can_buy,tc,n,prices),buy=0,sell=0;
        
        if(can_buy)
            buy =  get_ans(curr+1,0,tc,n,prices) - prices[curr];
        
        else
            sell = prices[curr] + get_ans(curr+1,1,tc-1,n,prices);
        
        return dp[curr][can_buy] = max({idle,buy,sell});
        
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,100001*2*sizeof(int));
        int n=prices.size();
        
        return get_ans(0,1,1,n,prices);
        
        
        
    }
};