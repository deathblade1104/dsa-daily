class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0]==1)
            return -1;
        
        int n= grid.size();
        array<int,9>dir= {1,0,-1,0,1,1,-1,-1,1};
        queue<array<int,2>>q;
        q.push({0,0});
        grid[0][0] = 1;
        int steps=1;
        
        while(q.size()>0)
        {
            int sz = q.size();
            while(sz--)
            {
                auto p = q.front();
                q.pop();

                if(p[0]==n-1 and p[1]==n-1)
                return steps;

                for(int i=1;i<=8;i++)
                {
                    int x = p[0] + dir[i-1] , y = p[1] + dir[i];

                    if(x>=0 and y>=0 and x<n and y<n and grid[x][y]==0)
                    {
                        q.push({x,y});
                        grid[x][y]=1;
                    }
                }   
            }
            steps++;
        }
        
        return -1;
    }
};