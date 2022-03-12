class Solution {
private:
    void DFS(int i, int j, int &n, int &m, vector<vector<char>>&grid)
    {
        if(i<0 or j<0 or i>=n or j>=m or  grid[i][j]=='0')
            return;
        
        grid[i][j]='0';
        
        DFS(i+1,j,n,m,grid);
        DFS(i-1,j,n,m,grid);
        DFS(i,j+1,n,m,grid);
        DFS(i,j-1,n,m,grid);
        
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    DFS(i,j,n,m,grid);
                    ans++;                   
                }
                    
            }
        }
        
        return ans;      
        
        
    }
};