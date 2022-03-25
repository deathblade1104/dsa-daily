class Solution {
private :
    bool DFS(int curr, int color, vector<int>&vis, vector<vector<int>>&adj)
    {
        vis[curr]=color;
        
        bool ans=true;
        for(int neigh : adj[curr])
        {
            if(vis[neigh]!=-1 and vis[neigh]==color)
                    return false;
            
            else if(vis[neigh]==-1)
                ans = ans & DFS(neigh, !color, vis,adj);
            
            if(ans==false)
                return false;
        }
        
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n= adj.size();
        vector<int>vis(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                bool temp = DFS(i,1,vis,adj);
                
                if(!temp)
                    return false;
            }
        }
        
        return true;
    }
};