class Solution {
public:
  
    vector<vector<int>> updateMatrix(vector<vector<int>>&grid) {
      int n=grid.size(),m=grid[0].size();
      queue<pair<int,int>>q;
      int dim[5]={1,0,-1,0,1};
      vector<vector<int>>ans(n,vector<int>(m,-2));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    for(int k=1;k<=4;k++)
                    {
                        int  x = i + dim[k-1] , y = j + dim[k];
                        if(x>=0 and y>=0 and x<n and y<m and grid[x][y]==1 and ans[x][y]==-2)  
                        {
                            q.push({x,y});
                            ans[x][y]=-1;
                        }
                    }
                    ans[i][j]=0;
                }
            }
        }
        
        int qc=0,steps=1;
        while(q.size()>0)
        {
            int sz=q.size();
            for(int j=0;j<sz;j++)
            {
                auto p = q.front();
                q.pop();
                qc++;

                int row=p.first,col=p.second;

                if(ans[row][col]>=0)
                continue;

                ans[row][col]=steps;          

                for(int i=1;i<=4;i++)
                {
                    int x=row+dim[i-1],y=col+dim[i];

                    if(x<0 or y<0 or x>=n or y>=m or ans[x][y]!=-2 or grid[x][y]==0)
                        continue;

                    else
                        q.push({x,y});
                }
            }
            steps++;
        }
        
        // cout<<qc<<endl;
        
        return ans;
        
    }
};