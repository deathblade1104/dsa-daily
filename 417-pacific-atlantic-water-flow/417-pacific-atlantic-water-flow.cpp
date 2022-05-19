class Solution {
public:
    array<int,5>dir={1,0,-1,0,1};
    void DFS(int i, int j, int&n, int&m , vector<vector<bool>>&vis, vector<vector<int>>&heights)
    {
        vis[i][j]=true;
        
        for(int k=1;k<=4;k++)
        {
            int x = i + dir[k-1] , y = j + dir[k];
            
            if(x<0 or y<0 or x>=n or y>=m or vis[x][y] or heights[x][y]<heights[i][j])
                continue;
            
            DFS(x,y,n,m,vis,heights);
        }
        
        return;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n  = heights.size(), m = heights[0].size();
        
        vector<vector<bool>>pacific(n,vector<bool>(m,false)),atlantic(n,vector<bool>(m,false));
         
        vector<vector<int>>ans;
        if(n==0 or m==0)
            return ans;
        
        
        for(int i=0;i<m;i++)
        {
            DFS(0,i,n,m,pacific,heights);
            DFS(n-1,i,n,m,atlantic,heights);
        }
        
        for(int i=0;i<n;i++)
        {
            DFS(i,0,n,m,pacific,heights);
            DFS(i,m-1,n,m,atlantic,heights);
        }
        
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] and atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};