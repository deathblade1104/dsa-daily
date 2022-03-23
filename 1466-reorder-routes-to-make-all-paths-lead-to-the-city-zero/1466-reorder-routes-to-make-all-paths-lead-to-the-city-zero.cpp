class Solution {
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
            edges.insert({u,v});
            
            
            adj[v].push_back(u);
        }
        
        queue<pair<int,int>>q;
        q.push({0,-1});
        vis[0]=true;
        
        int ans=0;
        
        while(q.size()>0)
        {
            auto [c,p]= q.front();
            q.pop();
                        
            for(auto neigh : adj[c])
            {
                if(!vis[neigh])
                {
                    pair<int,int>p=make_pair(neigh,c);
                    
                    if(edges.count(p)==0)
                        ans++;
                    
                    q.push({neigh,c});
                    vis[neigh]=true;
                }
            }                      
            
        }
        
        return ans;
        
    }
};