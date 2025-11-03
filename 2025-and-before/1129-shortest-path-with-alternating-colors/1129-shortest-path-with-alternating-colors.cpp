class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    
        vector<pair<int,int>>adj[n];
        vector<int>ans(n,INT_MAX);
        vector<vector<bool>>vis(n,vector<bool>(2,false));
        
        for(auto p : redEdges)
            adj[p[0]].push_back({p[1],0});            
        
        for( auto p : blueEdges)
            adj[p[0]].push_back({p[1],1});            
        
        
        queue<pair<int,int>>q;
        q.push({0,0});
        q.push({0,1});
        int steps=0;
        
        while(q.size()>0)
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto p=q.front();
                q.pop();
                
                int v=p.first, c=p.second;
                ans[v]= min(ans[v],steps);
                vis[v][c]=true;
                
                for(auto neigh : adj[v])
                {
                    if(neigh.second!=c and vis[neigh.first][neigh.second]==false)
                        q.push(neigh);
                }                
            }
            steps++;
        }
        
        for(int i=0;i<ans.size();i++)
            if(ans[i]==INT_MAX)
                ans[i]=-1;
        
        return ans;
    }
};