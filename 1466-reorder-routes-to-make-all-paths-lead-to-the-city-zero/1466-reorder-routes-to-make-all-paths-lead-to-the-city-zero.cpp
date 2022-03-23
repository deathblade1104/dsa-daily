class Solution {
private :
    void DFS(int curr, int par, int &ans,vector<bool>&vis, set<pair<int,int>>&edges, vector<int>adj[])
    {
        for(auto neigh : adj[curr])
        {
            if(!vis[neigh])
            {
                pair<int,int>p=make_pair(neigh,curr);
                if(edges.count(p)==0)
                    ans++;
                
                vis[neigh]=true;
                DFS(neigh,curr, ans,vis,edges,adj);
            }
        }
        
        return;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        set<pair<int,int>>edges;       
        vector<bool>vis(n,false);
        
        for(int i =0;i<connections.size();i++)
        {
            auto p = connections[i];
            int u=p[0],v=p[1];
            
            adj[u].push_back(v);
            edges.insert(make_pair(u,v));        
            
            adj[v].push_back(u);
        }
        
        vis[0]=true;
        
        int ans=0;
        DFS(0,-1,ans,vis,edges,adj);
        
        return ans;
        
    }
};