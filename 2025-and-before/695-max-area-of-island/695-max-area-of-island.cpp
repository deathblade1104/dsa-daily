class Solution {
public:
    int DFS(int i, int j, int&n, int &m , array<int,5>&dir, vector<vector<int>>&grid)
    {        
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0)
            return 0;
        
        grid[i][j]=0;
        
        int neigh =0;
        
        for(int k=1;k<=4;k++)
        {
            int x = dir[k-1] + i, y = dir[k] + j;
            
            neigh += DFS(x,y,n,m,dir,grid);
        }
        
        return 1 + neigh;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        array<int,5>dir = {1,0,-1,0,1};
        int n = grid.size(), m = grid[0].size();
        int ans =0;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    ans = max(ans,DFS(i,j,n,m,dir,grid));
            }
        }
        
        return ans;
        
    }
};