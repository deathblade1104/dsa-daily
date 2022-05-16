class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0]==1)
            return -1;
        
        int n= grid.size();
        array<int,9>dir= {1,0,-1,0,1,1,-1,-1,1};
        queue<array<int,3>>q;
        q.push({1,0,0});
        grid[0][0] = 1;
        
        while(q.size()>0)
        {
            auto p = q.front();
            q.pop();
            
            if(p[1]==n-1 and p[2]==n-1)
                return p[0];
            
            for(int i=1;i<=8;i++)
            {
                int x = p[1] + dir[i-1] , y = p[2] + dir[i];
                
                if(x>=0 and y>=0 and x<n and y<n and grid[x][y]==0)
                {
                    q.push({p[0]+1,x,y});
                    grid[x][y]=1;
                }
            }   
        }
        
        return -1;
    }
};