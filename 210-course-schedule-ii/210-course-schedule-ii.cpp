class Solution {
public:
    bool DFS(int curr, vector<vector<int>>&adj, vector<bool>&vis, vector<bool>&anc, vector<int>&ans)
    {
        if(vis[curr])
        {
            if(anc[curr])
                return true;
            
            return false;
        }
        
        vis[curr]=true;
        anc[curr]=true;
                
        for(int x : adj[curr])
        {
            if(DFS(x,adj,vis,anc,ans))
                return true;
        }
        
        ans.push_back(curr);
        anc[curr]=false;
        return false;
    }
    vector<int> findOrder(int V, vector<vector<int>>&edges) {
    
        vector<int>ans;
        vector<vector<int>>adj(V);
        
        for(auto i : edges)
            adj[i[1]].push_back(i[0]);
        
        vector<bool>vis(V,false),anc(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i] and DFS(i,adj,vis,anc,ans))
                return {};
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};