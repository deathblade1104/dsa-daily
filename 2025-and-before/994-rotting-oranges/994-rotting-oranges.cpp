class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        array<int,5>dir = {1,0,-1,0,1};
        
        int n = grid.size() , m = grid[0].size(), fresh=0;
        queue<array<int,2>>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        
        if(fresh==0)
            return 0;            
        
        int required_time = 0;
        
        while(q.size()>0)
        {
            int sz = q.size();
            
            while(sz--)
            {
                array<int,2>curr= q.front();
                q.pop();
                for(int k=1;k<=4;k++)
                {
                    int x = dir[k-1] + curr[0], y = dir[k]+curr[1];

                    if(x>=0 and y>=0 and x<n and y<m and grid[x][y]==1)
                    {
                        q.push({x,y});
                        grid[x][y]=2;
                        fresh--;
                    }  
                }
            }
            
            required_time++;
        }
        

        
        return fresh>0? -1 : required_time-1;
    }
};