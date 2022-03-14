class Solution {
private :
    vector<int>dim={1,0,-1,0,1};
    void DFS(int r, int c, int&n,int&m,vector<vector<int>>&grid,bool&ans,int&sz)
    {
        if(r<0 or c<0 or r>=n or c>=m or grid[r][c]==0)
            return;
        
        if(r==0 or c==0 or r==n-1 or c==m-1)
            ans=false;
        
        grid[r][c]=0;
        sz++;
        
        for(int i=1;i<=4;i++)
            DFS(r+dim[i-1],c+dim[i],n,m,grid,ans,sz);
        
        return;        
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),count=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    bool ans=true;
                    int sz=0;
                    DFS(i,j,n,m,grid,ans,sz);
                    
                    if(ans)
                        count+=sz;
                }
            }
        }
        
        return count;
        
    }
};