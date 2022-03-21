class Solution {
public:
    struct Node{
        int r,c,dist;
        Node(int x, int y, int z)
        {
            r=x;
            c=y;
            dist=z;
        }
    };
    
    vector<vector<int>> updateMatrix(vector<vector<int>>&grid) {
      int n=grid.size(),m=grid[0].size(),cells=0;
      queue<Node>q;
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
                            q.push(Node(x,y,1));
                            ans[x][y]=-1;
                        }
                    }
                    ans[i][j]=0;
                }
            }
        }
        
        
        while(q.size()>0)
        {
            auto p = q.front();
            q.pop();
            
            int row=p.r,col=p.c,d=p.dist;
            
            if(ans[row][col]>=0)
                continue;
            
            ans[row][col]=d;          
            
            for(int i=1;i<=4;i++)
            {
                int x=row+dim[i-1],y=col+dim[i];
                
                if(x<0 or y<0 or x>=n or y>=m or ans[x][y]>=0)
                    continue;
                
                else
                    q.push(Node(x,y,d+1));
            }
        }
        
        return ans;
        
    }
};