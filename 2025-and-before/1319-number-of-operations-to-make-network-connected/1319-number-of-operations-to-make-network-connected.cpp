class Solution {
private:
    void DFS(int curr,vector<bool>&vis,vector<vector<int>>&adj)
    {
        vis[curr]=true;
        
        for(int x : adj[curr])
        {
            if(!vis[x])
                DFS(x,vis,adj);
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
                DFS(i,vis,adj);
            }            
        }
        
        return count-1;
        
    }
};