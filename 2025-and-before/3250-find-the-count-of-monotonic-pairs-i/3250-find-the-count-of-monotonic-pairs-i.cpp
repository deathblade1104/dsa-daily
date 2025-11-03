class Solution {
public:
    int mod=1e9+7;
    int dp[2001][52][52];
    int solve(int i,int n,vector<int>&v,int prev1,int prev2) {
        if(i==n)
            return 1;
        
        int &ans=dp[i][prev1][prev2];
        
        if(ans!=-1)
            return ans;
        
        ans = 0;
        
        for(int j=prev1;j<=v[i];j++) {
            int x1=j;
            int x2=v[i]-j;
            if(x1>=prev1 && x2<=prev2) {
                ans=(ans+solve(i+1,n,v,x1,x2))%mod;
            } 
        }
        
        return ans;
    }
    int countOfPairs(vector<int>& v) {
        int n=v.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,n,v,0,50);
        return ans;
    }
};