class Solution {
private:
    void DFS(int curr, int &ans, vector<bool>&vis,vector<pair<int,bool>>adj[])
    {
        
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,bool>>adj[n];
        vector<bool>vis(n,false);
        
        for(int i =0;i<connections.size();i++)
        {
            auto p = connections[i];
            int u=p[0],v=p[1];
            
            adj[u].push_back({v,true});
            adj[v].push_back({u,false});
        }
        
        vis[0]=true;
        int ans=0;
        
        queue<int>q;
        q.push(0);
        
        while(q.size()>0)
        {
            
            auto curr= q.front();
            q.pop();
            
             for(auto neigh : adj[curr])
             {
                if(!vis[neigh.first])
                {
                    if(neigh.second==true)  
                        ans++;

                    vis[neigh.first]=true;
                    q.push(neigh.first);
                }
             }
        }
        
        return ans;
        
    }
};