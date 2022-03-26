class Solution {
private:
    int dp[46];
    int get_ans(int curr, int n)
    {
        if(curr>n)
            return 0;
        
        if(curr==n)
            return 1;
        
        if(dp[curr]!=-1)
            return dp[curr];        
        
        int first = get_ans(curr+1,n);
            
        int second = get_ans(curr+2,n);
            
        return dp[curr]=first + second;
    }
public:
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        
        return get_ans(0,n);
    }
};