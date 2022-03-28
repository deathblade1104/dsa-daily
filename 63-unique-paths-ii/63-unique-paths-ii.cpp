class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        long long dp[101][101]={0};
        int m=grid.size(), n=grid[0].size();
        
        if(grid[m-1][n-1]==1 or grid[0][0]==1)
            return 0;
        
        dp[m-1][n-1]=1;        
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 and j==n-1)
                    continue;
                
                else if(grid[i][j]==1)
                    dp[i][j]=0;
                
                else
                {
                    if(i==m-1)
                        dp[i][j]= dp[i][j+1];

                        
                    if(j==n-1)
                        dp[i][j] = dp[i+1][j];
                        
                    if(i!=m-1 and j!=n-1)
                        dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }        
        return dp[0][0];
    }
};