class Solution {
private :
    bool isValid(int r,int c, int &n,int&m,vector<vector<int>>&grid)
    {
        if(r<0 or c<0 or r>=n or c>=m or grid[r][c]==1)
            return false;
        
        return true;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dim[9]={1,0,-1,0,1,-1,-1,1,1};
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==1 or grid[n-1][m-1]==1)
            return -1;
        
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        
        int steps=1;
        
        while(q.size()>0)
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto p=q.front();
                q.pop();
                
                int r=p.first,c=p.second;
                
                if(r==n-1 and c==m-1)
                 return steps;
                
                
                for(int i=1;i<9;i++)
                {
                    if(isValid(r+dim[i-1],c+dim[i],n,m,grid))
                    {
                        q.push({r+dim[i-1],c+dim[i]});
                        grid[r+dim[i-1]][c+dim[i]]=1;
                    }
                }
            }
            steps++;
        }
        
        return -1;
        
    }
};