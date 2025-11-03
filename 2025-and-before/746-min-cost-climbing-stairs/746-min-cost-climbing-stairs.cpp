class Solution {
    private:
    int dp[1001];
    int get_ans(int curr, int &sz, vector<int>&cost)
    {
        if(curr>sz)
            return INT_MAX/2;
        
        if(curr==sz)
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        
        int first = get_ans(curr+1,sz,cost);
        int second = get_ans(curr+2,sz,cost);
            
        return  dp[curr] = cost[curr] + min(first,second);
        
    }
    public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz=cost.size();
        memset(dp,-1 , sizeof(dp));
        
        int ans = get_ans(0,sz,cost);
        
        return min(ans,dp[1]);
        
        
        
    }
};