class Solution {

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        unordered_map<int, unordered_set<int>>edges;    
        vector<bool>vis(n,false);
        
        for(int i =0;i<connections.size();i++)
        {
            auto p = connections[i];
            int u=p[0],v=p[1];
            
            adj[u].push_back(v);
            edges[u].insert(v);      
            
            adj[v].push_back(u);
        }
        
        vis[0]=true;
        
        int ans=0;
        queue<pair<int,int>>q;
        q.push({0,-1});
        
        while(q.size()>0)
        {
            auto [curr, p]= q.front();
            q.pop();
            
            for(auto neigh : adj[curr])
             {
                if(!vis[neigh])
                {
                    if(edges[neigh].count(curr)==0)
                        ans++;

                    vis[neigh]=true;
                    q.push({neigh,curr});
                }
             }
        }
        
        return ans;
        
    }
};