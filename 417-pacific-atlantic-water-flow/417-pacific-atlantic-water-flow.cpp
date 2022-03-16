class Solution {
private:
    int dim[5]={1,0,-1,0,1};
    void DFS(int r,int c,int&n,int&m,int prev,vector<vector<int>>&heights,vector<vector<bool>>&vis)
    {
        if(r<0 or c<0 or r>=n or c>=m or vis[r][c] or heights[r][c]<prev)
            return;
        
        vis[r][c]=true;
        
        for(int i=1;i<5;i++)
            DFS(r+dim[i-1],c+dim[i],n,m,heights[r][c],heights,vis);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        int n=heights.size(),m=heights[0].size();
        if(n==0 or m==0)
            return ans;
        
        vector<vector<bool>>pac(n,vector<bool>(m,false));
        vector<vector<bool>>atl(n,vector<bool>(m,false));
        
        
        for(int i=0;i<m;i++)
        {
            DFS(0,i,n,m,INT_MIN,heights,pac);
            DFS(n-1,i,n,m,INT_MIN,heights,atl);
        }
        
        for(int i=0;i<n;i++)
        {
            DFS(i,0,n,m,INT_MIN,heights,pac);
            DFS(i,m-1,n,m,INT_MIN,heights,atl);
        }
        
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(pac[i][j] and atl[i][j])
                    ans.push_back({i,j});
        return ans;
    }
};