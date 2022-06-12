class Solution {
public:
    void helper(int r, int c,int curr_cells,int&n,int&m,int&empty_cells,int&ans,vector<vector<int>>&grid,array<int,5>&dir)
    {
        if(r<0 or c<0 or r>=n or c>=m or grid[r][c]==-1 or grid[r][c]==3)
            return;
        
        if(grid[r][c]==2)
        {
            if(curr_cells == empty_cells)
                ans++;
            
            return;
        }
        
        grid[r][c] = 3;
        for(int k=1;k<5;k++)
            helper(r+dir[k-1],c+dir[k],curr_cells+1,n,m,empty_cells,ans,grid,dir);
        
        grid[r][c] =0;
        return;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(),empty_cells = 1, start_r, start_c,ans=0;
        array<int,5> dir = {1,0,-1,0,1};
        
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    start_r =i;
                    start_c = j;
                }
                
                else if(grid[i][j] == 0)
                    empty_cells++;
            }
        }
                
        helper(start_r,start_c,0,n,m,empty_cells,ans,grid,dir);
        return ans;
    }
};