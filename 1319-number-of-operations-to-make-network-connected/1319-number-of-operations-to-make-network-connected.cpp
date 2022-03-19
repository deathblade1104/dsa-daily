class Solution {
private:
    void DFS(int curr,int par,vector<bool>&vis,vector<vector<int>>&adj)
    {
        vis[curr]=true;
        
        for(int x : adj[curr])
        {
            if(!vis[x] and x!=par)
                DFS(x,par,vis,adj);
        }
        return;
    }
    
    vector<vector<int>>make_graph(int n,vector<vector<int>>&edges)
    {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        return adj;
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        
        if(edges.size()<n-1)
            return -1;
        
        vector<vector<int>>adj=make_graph(n,edges);
        vector<bool>vis(n,false);
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                DFS(i,-1,vis,adj);
            }            
        }
        
        return count-1;
        
    }
};