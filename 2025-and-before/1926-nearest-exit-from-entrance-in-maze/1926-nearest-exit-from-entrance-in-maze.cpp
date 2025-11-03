class Solution {

    private:
    bool isValid(int r, int c, int &n, int &m, vector<vector<char>>&maze)
    {
        if(r<0 or c<0 or r>=n or c>=m or maze[r][c]=='+' or maze[r][c]=='_')
            return false;
        
        return true;
    }
    
    bool isExit(int r, int c, int &n, int &m, vector<vector<char>>&maze)
    {
        if((r==0 or c==0 or r==n-1 or c==m-1) and (maze[r][c]=='_'))
            return true;
        
        return false;
        
    }
    
    public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int dim[5]={1,0,-1,0,1};
        int n=maze.size(),m=maze[0].size(),steps=0;
        
        if(maze[entrance[0]][entrance[1]]=='+')
            return -1;
        
        int a= entrance[0],b=entrance[1];
        queue<pair<int,int>>q;
        q.push({a,b});        
        maze[a][b]='+';        
        
        
        while(q.size()>0)
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto p = q.front();
                q.pop();
                
                int r=p.first,c=p.second;
                
                if(isExit(r,c,n,m,maze))
                    return steps;
                
                for(int j=1;j<5;j++)
                {
                    int x=r+dim[j-1],y=c+dim[j];
                    
                    if(isValid(x,y,n,m,maze))
                    {
                        q.push({x,y});
                        maze[x][y]='_';
                    }
                }
            }
            steps++;
        }
        
        return -1;      
        
        
        
    }
};