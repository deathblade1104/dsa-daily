class Solution {
private :
    void DFS(int r,int c,int&n, int&m,vector<vector<int>>&grid, int&count)
    {
        if(r<0 or c<0 or r>=n or c>=m or grid[r][c]==0)
            return;

        grid[r][c]=0;
        count++;
        
        DFS(r+1,c,n,m,grid,count);
        DFS(r-1,c,n,m,grid,count);
        DFS(r,c+1,n,m,grid,count);
        DFS(r,c-1,n,m,grid,count);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0,n=grid.size(),m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int count =0;
                    DFS(i,j,n,m,grid,count);
                    ans=max(ans,count);
                }
            }
        }
        
        return ans;
    }
};