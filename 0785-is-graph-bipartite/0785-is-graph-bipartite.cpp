class Solution {
public:
    bool DFS(int curr,int col, vector<int>&color, vector<vector<int>>&adj)
    {
        color[curr]=col;
        bool ans=true;
        for(int i : adj[curr])
        {
            if(color[i]!=-1 and color[i]==col)
                ans= ans & false;
            
            else if(color[i]==-1)
                ans =  ans &  DFS(i,!col,color,adj);
            
            if(!ans)
                return false;
        }
        
        return  true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1 and DFS(i,0,color,graph)==false)
                return false;
        }
        
        return true;      
        
        
    }
};