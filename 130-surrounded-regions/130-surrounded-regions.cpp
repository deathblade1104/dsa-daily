class Solution {
public:
    array<int,5>dir={1,0,-1,0,1};
    void DFS(int i,int j ,int&n,int&m, vector<vector<char>>&grid)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]!='O')
            return;
        
        grid[i][j] = '_';
        
        for(int k=1;k<=4;k++)
            DFS(i+dir[k-1],j+dir[k],n,m,grid);
        
        return;
    }
    
    void solve(vector<vector<char>>& grid) {
        
        int n = grid.size(),m=grid[0].size();
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]=='O')
                DFS(0,i,n,m,grid);
            
            if(grid[n-1][i]=='O')
                DFS(n-1,i,n,m,grid);
        }
        
        
        for(int i=1;i<=n-2;i++)
        {
            if(grid[i][0]=='O')
                DFS(i,0,n,m,grid);
            
            if(grid[i][m-1]=='O')
                DFS(i,m-1,n,m,grid);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='O')
                    grid[i][j] = 'X';
                
                else if(grid[i][j]=='_')
                    grid[i][j]='O';
            }
        }
    }
};