class Solution {
public:
    int dp[101][101];
    int helper(int r,int c,int&m,int&n,vector<vector<int>>& mat){
        
        if(r>=m or c>=n or mat[r][c]==1)
            return 0;
        
        if(r==m-1 and c==n-1)
            return 1;
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        return dp[r][c] = helper(r+1,c,m,n,mat) + helper(r,c+1,m,n,mat);
    }
 
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int m = mat.size(),n =mat[0].size();
        memset(dp,-1,sizeof dp);
        return helper(0,0,m,n,mat);
    }
};