class Solution {
public:
    int dp[59];
    int get_ans(int n)
    {       
        if(n<=1)
            return 1;
        
        if(dp[n]!=-1)
            return dp[n];
        
        int ans=n,temp=1;
        for(int i=1;i<n;i++)
        {
            temp= get_ans(n-i) * get_ans(i);
            ans=max(temp,ans);            
        }
        
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        if(n<=3)
            return n-1;
        return get_ans(n); 
    }
};