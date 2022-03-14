class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int dim[5]={1,0,-1,0,1};
        int n=grid2.size(),m=grid2[0].size(),count=0;        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j])
                {
                    bool ans=true;
                    
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    
                    while(q.size()>0)
                    {
                        auto p = q.front();q.pop();
                        int r =p.first,c=p.second;
                        
                        if(r<0 or c<0 or r>=n or c>=m or grid2[r][c]==0)
                            continue;
                        
                        if(grid1[r][c]==0 and grid2[r][c]==1)
                            ans=false;
                        
                        grid2[r][c]=0;
                        
                        for(int k=1;k<=4;k++)
                        {
                            int x = r + dim[k-1], y = c + dim[k];
                            
                            if(x>=0 and x<n and y>=0 and y<m and grid2[x][y]==1 )
                                q.push({x,y});
                        }
                    }
                    
                    if(ans)
                        count++;
                }
            }
        }
        return count;
    }
};