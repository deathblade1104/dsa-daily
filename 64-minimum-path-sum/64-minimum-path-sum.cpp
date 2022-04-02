class Solution {
public:
    int dp[201][201];    
    int get_ans(int r, int c, int&n ,int&m, vector<vector<int>>&grid)
    {
       
        if(r>=n or c>=m)
           return 100001;
        
        if(r==n-1 and c==m-1)
        return dp[r][c]=grid[r][c];
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        int down,right;        
        down = grid[r][c] + get_ans(r+1,c,n,m,grid);
        right = grid[r][c] + get_ans(r,c+1,n,m,grid);
        
        return dp[r][c] =  min(down,right);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size(),m=grid[0].size();
        memset(dp,-1,201*201*sizeof(int));
        return get_ans(0,0,n,m,grid);
    }
};