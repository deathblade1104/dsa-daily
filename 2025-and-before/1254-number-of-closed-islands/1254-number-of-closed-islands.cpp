class Solution {
    vector<int>dim={1,0,-1,0,1};
    void DFS(int r,int c,int&n,int&m,vector<vector<int>>&grid,bool&ans)
    {
        if(r==0 or c==0 or r==n-1 or c==m-1)
            ans=false;
        
        grid[r][c]=1;
        
        
        for(int i=1;i<=4;i++)
        {
            if(r+dim[i-1]<0 or r+dim[i-1]>=n or c+dim[i]<0 or c+dim[i]>=m or grid[r+dim[i-1]][c+dim[i]]==1)
            continue;
            
            else
            DFS(r+dim[i-1],c+dim[i],n,m,grid,ans);
        }
        
        return;
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count =0,n=grid.size(),m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    bool flag=true;
                    DFS(i,j,n,m,grid,flag);
                    
                    if(flag)
                        count++;
                }
            }
        }
        
        return count;
    }
};