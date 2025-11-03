class Solution {
public:
    
    bool vis[200001];
    
    bool DFS(int curr,int&destination,vector<vector<int>>&adj){
        
        if(curr == destination)
            return true;
        
        bool ans = false;
        vis[curr] = true;
        
        for(int&neigh : adj[curr]){
            
            if(!vis[neigh]){
                ans = ans | DFS(neigh,destination,adj);
                
                if(ans)
                    return true;
            }
        }
        
        return ans;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>>adj(n);
        memset(vis,0,sizeof vis);
        
        for(auto&e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        return DFS(source,destination,adj);
    }
};