class Solution {
public:
    int dp[10001];
    int get_ans(int curr)
    {
        if(curr<=3)
            return dp[curr]=curr;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        int ans = curr;
        for(int i=2;i*i<=curr;i++)
        {
            int temp = 1 + get_ans(curr-(i*i));
            ans=min(ans,temp);
            
        }
        
        return dp[curr]=ans;
    }
    
    
    int numSquares(int n)
    {
        memset(dp,-1,sizeof(dp));        
        return get_ans(n);
    }
};