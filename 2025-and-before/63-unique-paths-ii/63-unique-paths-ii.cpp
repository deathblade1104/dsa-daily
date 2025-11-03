class Solution {
public:
    
    int helper(int i,int j, int&n,int&m, vector<vector<int>>&grid, vector<vector<int>>&dp)
    {
        if(i>=n or j>=m)
            return 0;
        
        if(grid[i][j]==1)
            return dp[i][j]=0;
        
        if(i==n-1 and j==m-1)
            return dp[i][j]=1;
                
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int down = helper(i+1,j,n,m,grid,dp);
            
        int right = helper(i,j+1,n,m,grid,dp);
            
        return dp[i][j]= down + right;        
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        
        
        int n= grid.size(), m= grid[0].size();
        if(grid[0][0]==1 or  grid[n-1][m-1]==1)
            return 0;
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,n,m,grid,dp);
        
        
    }
};