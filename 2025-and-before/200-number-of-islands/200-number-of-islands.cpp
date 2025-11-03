class Solution {
public:
    void DFS(int i, int j, int&n, int &m , array<int,5>&dir, vector<vector<char>>&grid)
    {        
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]=='0')
            return;
        
        grid[i][j]='0';
        
        for(int k=1;k<=4;k++)
        {
            int x = dir[k-1] + i, y = dir[k] + j;
            
            DFS(x,y,n,m,dir,grid);
        }
        
        return;
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size(),ans=0;
        array<int,5>dir={1,0,-1,0,1};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    DFS(i,j,n,m,dir,grid);
                }
            }
        }
        
        return ans;
        
    }
};