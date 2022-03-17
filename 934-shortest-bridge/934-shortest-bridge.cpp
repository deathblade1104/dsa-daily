class Solution {
    public:
    int dim[5]={1,0,-1,0,1};
    
    void DFS(int r,int c,int &n,int&m,int&no,vector<vector<int>>&grid)
    {
        if(r<0 or c<0 or r>=n or c>=m or grid[r][c]!=1)
            return;
        
        grid[r][c]=no;
        
        for(int i=1;i<=4;i++)
            DFS(r+dim[i-1],c+dim[i],n,m,no,grid);
        
        return;        
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n=grid.size(),m=grid[0].size();
        int island_no=2;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    DFS(i,j,n,m,island_no,grid);
                    island_no++;
                }
            }
        }
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//                 cout<<grid[i][j]<<" ";
            
//             cout<<endl;
//         }
        
        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        int steps=0;
        
        while(q.size()>0)
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto p=q.front();
                q.pop();
                
                int r=p.first,c=p.second;
                
                // cout<<r<<"_"<<c<<"--->"<<grid[r][c]<<endl;
                
                if(grid[r][c]==1)
                    continue;
                
                else if(grid[r][c]==3)
                    return steps-1;
                
                grid[r][c]=1;
                
                for(int j=1;j<=4;j++)
                {
                    int x=r+dim[j-1],y=c+dim[j];
                    
                    if(x<0 or y<0 or x>=n or y>=n or grid[x][y]==1)
                        continue;
                    
                    else
                        q.push({x,y});
                }
            }
            
            steps++;           
        }
        
        return -1;      
        
    }
};