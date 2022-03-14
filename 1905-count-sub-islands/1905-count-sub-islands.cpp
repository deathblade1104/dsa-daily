class Solution {
private :
    int dim[5]={1,0,-1,0,1};
    void DFS(int r, int c, int&n ,int&m, vector<vector<int>>&grid1, vector<vector<int>>&grid2, bool&ans)
    {
        if(r<0 or c<0 or r>=n or c>=m or grid2[r][c]==0)
            return;

        if((grid1[r][c] & grid2[r][c] )== 0)
            ans=false;

        grid2[r][c]=0;

        for(int i=1;i<=4;i++)
            DFS(r+dim[i-1],c+dim[i],n,m,grid1,grid2,ans);

    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size(),m=grid2[0].size(),count=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j])
                {
                    bool ans=true;
                    DFS(i,j,n,m,grid1,grid2,ans);
                    
                    if(ans)
                        count++;
                }
            }
        }
        
        return count;
    }
};