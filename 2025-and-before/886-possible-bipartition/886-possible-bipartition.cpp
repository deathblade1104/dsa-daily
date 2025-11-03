class Solution {
private :
    bool DFS(int curr, int color, vector<int>&vis, vector<int>adj[])
    {
        vis[curr]=color;
        
        bool ans= true;
        
        for(int neigh : adj[curr])
        {
            if(vis[neigh]!=-1 and vis[neigh]==color)
                return false;
            
            else if(vis[neigh]==-1)
                ans = ans & DFS(neigh,!color,vis,adj);
            
           if(ans==false)
               return false;
                
        }
        
        return true;
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>vis(n+1,-1);
        vector<int>adj[1+n];
        
        for(auto edge : dislikes)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
            
        for(int i=1;i<=n;i++)
            if((vis[i]==-1) and (DFS(i,1,vis,adj)==false))   
                    return false;
        
        return true;
    }
};