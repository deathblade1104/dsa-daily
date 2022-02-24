class Solution {
private :
//     bool DFS(int curr, vector<vector<int>>&adj, vector<bool>&vis, vector<bool>&anc, vector<int>&ans)
//     {
//         if(vis[curr])
//         {
//             if(anc[curr])
//                 return true;
            
//             return false;
//         }
        
//         vis[curr]=true;
//         anc[curr]=true;
                
//         for(int x : adj[curr])
//         {
//             if(DFS(x,adj,vis,anc,ans))
//                 return true;
//         }
        
//         ans.push_back(curr);
//         anc[curr]=false;
//         return false;
//     }
    
//     vector<int>DFS_driver(int V, vector<vector<int>>&edges)
//     {
//          vector<int>ans;
//         vector<vector<int>>adj(V);
        
//         for(auto i : edges)
//             adj[i[1]].push_back(i[0]);
        
//         vector<bool>vis(V,false),anc(V,false);
        
//         for(int i=0;i<V;i++)
//         {
//             if(!vis[i] and DFS(i,adj,vis,anc,ans))
//                 return {};
//         }
        
//         reverse(ans.begin(),ans.end());        
//         return ans;
//     }
    
    
    vector<int> BFS_Kahn(int V, vector<vector<int>>&edges)
    {
        
        vector<int>ans;
        vector<int>indegree(V,0);
        vector<vector<int>>adj(V);
        
        for(auto i : edges)
            adj[i[1]].push_back(i[0]);
        
        
        for(int i=0;i<V;i++)
        {
            for(int x : adj[i])
                indegree[x]++;
        }
        
        queue<int>q;
        for(int i=0;i<V;i++)
            if(indegree[i]==0)
                q.push(i);
        
        
        int cnt=q.size();
        
        while(q.size()>0)
        {
            int curr=q.front();
            q.pop();
            
            
            ans.push_back(curr);
            
            
            for(int x : adj[curr])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                    cnt++;
                }
            }
        }
        
        
        if(cnt == V)
            return ans;
        
        else return {};
    }
public:
    
    vector<int> findOrder(int V, vector<vector<int>>&edges) {        
       return BFS_Kahn(V,edges);
    }
};