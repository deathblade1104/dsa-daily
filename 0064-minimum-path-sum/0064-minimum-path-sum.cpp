class Solution {
public:
    int dp[201][201];
    int minsum(vector<vector<int>>& grid, int row,int col){ 
         
        if(row >= grid.size() or col >= grid[0].size() ) 
            return 10000001; 
                  
        if(row == grid.size()-1 and col == grid[0].size()-1) 
          return dp[row][col] = grid[row][col]; 
        
        if(dp[row][col]!=-1)
            return dp[row][col];
         
       int hor =  grid[row][col] + minsum (grid,row + 1,col); 
        int vert = grid[row][col] + minsum (grid,row,col+1); 
         
       return dp[row][col] = min(hor,vert); 
    } 
     
    int minPathSum(vector<vector<int>>& grid) { 
         
        memset(dp,-1,sizeof dp);
        return minsum(grid,0,0); 
    } 
};