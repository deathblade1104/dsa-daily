class Solution {
public:
    int dp[101][101];
    int helper(int r,int c,int&m,int&n){
        
        if(r>=m or c>=n)
            return 0;
        
        if(r==m-1 and c==n-1)
            return 1;
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        return dp[r][c] = helper(r+1,c,m,n) + helper(r,c+1,m,n);
    }
    
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof dp);
        return helper(0,0,m,n);
    }
};