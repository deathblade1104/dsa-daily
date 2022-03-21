class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size(),l=0,w=0;
        queue<pair<int,int>>q;
        vector<vector<int>>ans(n,vector<int>(n,-2));
        int dim[5]={1,0,-1,0,1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    l++;
                    ans[i][j]=0;
                    
                    for(int k=1;k<=4;k++)
                    {
                        int x=i+dim[k-1], y=j+dim[k];
                        
                        if(x<0 or y<0 or x>=n or y>=n or grid[x][y]==1 or ans[x][y]!=-2)
                            continue;
                        
                        ans[x][y]=-1;
                        q.push({x,y});
                    }
                }
                
                else 
                    w++;
            }
        }
        
        if(l==0 or w==0)
            return -1;
        
        int steps=1;
        while(q.size()>0)
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto p=q.front(); q.pop();
                
                int r=p.first,c=p.second;
                
                if(ans[r][c]>=0)
                    continue;
                
                ans[r][c]=steps;
                for(int k=1;k<=4;k++)
                {
                    int x=r+dim[k-1], y=c+dim[k];

                    if(x<0 or y<0 or x>=n or y>=n or grid[x][y]==1 or ans[x][y]!=-2)
                        continue;

                    ans[x][y]=-1;
                    q.push({x,y});
                }
                
            }
            steps++;
        }
        
        
        int res=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
             res=max(res,ans[i][j]);
        }
        
        return res;
        
    }
};