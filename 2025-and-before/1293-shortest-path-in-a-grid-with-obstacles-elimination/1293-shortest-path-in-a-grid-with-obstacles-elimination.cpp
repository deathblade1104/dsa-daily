class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int n = grid.size(), m= grid[0].size();
        
        if(k>=n+m-1)
            return n+m-2;
        
        vector<vector<vector<bool>>>vis(n,vector<vector<bool>>(m,vector<bool>(k+1,false)));
        
        array<int,5>dir = {1,0,-1,0,1};
        
        queue<array<int,3>>q;
        q.push({0,0,k});
        
        int steps=0;
        int ans = INT_MAX;
        
        while(q.size()>0)
        {
            int sz = q.size();            
            while(sz--)
            {
                auto arr = q.front();
                q.pop();

                int r = arr[0] , c = arr[1], block = arr[2];

                if(r==n-1 and c==m-1)
                    return steps;
                
                if(vis[r][c][block])
                    continue;
                
                vis[r][c][block] = true;

                for(int i=1;i<=4;i++)
                {
                    int x = dir[i-1] + r , y = dir[i] + c;

                    if(x<0 or y<0 or x>=n or y>=m)
                        continue;

                    if(grid[x][y]==1)
                    {
                        if((block == 0) or (vis[x][y][block-1]))
                            continue;
                        
                        q.push({x,y,block-1});
                    }
                    
                    else
                    {
                        if(vis[x][y][block])
                            continue;
                        
                        q.push({x,y,block});
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
        
    }
};