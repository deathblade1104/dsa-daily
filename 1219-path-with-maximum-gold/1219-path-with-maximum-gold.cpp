class Solution {
public:
    
    int DFS_helper(int i, int j, vector<vector<int>>&grid, vector<vector<bool>>&vis, array<int,5>&dir)
    {
        if(i>=grid.size() or j>=grid[0].size() or vis[i][j])
            return 0;
        
        if(grid[i][j] == 0)
        {
            vis[i][j] = true;
            return 0;
        }
        
        vis[i][j] = true;
        int curr = INT_MIN;
        
        for(int k=1;k<=4;k++)
        curr = max(curr,DFS_helper(i+dir[k-1],j+dir[k],grid,vis,dir));
        
        
        vis[i][j]= false;
        return grid[i][j] + curr;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int ans=0, n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        array<int,5>dir = {1,0,-1,0,1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                    vis[i][j] = true;
                
                else
                ans = max(ans,DFS_helper(i,j,grid,vis,dir));
            }
        }
        
        return ans;
    }
};