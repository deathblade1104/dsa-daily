class Solution {
public:
    int dp[201][201];
    
    int helper(int r, int c, vector<vector<int>>&grid){
        
        if(r>=grid.size() or c>=grid[0].size())
            return 10000001;
        
        if(r == grid.size()-1 and c == grid[0].size()-1)
            return dp[r][c] =  grid[r][c];
        
        if(dp[r][c] != -1)
            return dp[r][c];
        
       return dp[r][c] = grid[r][c] +  min(helper(r+1,c,grid),helper(r,c+1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof dp);
        return helper(0,0,grid);
    }
};