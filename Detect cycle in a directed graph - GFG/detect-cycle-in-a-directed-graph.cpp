// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool DFS(int curr, vector<int>adj[], vector<bool>&vis, vector<bool>&anc)
    {
        if(vis[curr])
        {
            if(anc[curr])
            return true;
            
            return false;
        }
        
        vis[curr]=true;
        anc[curr]=true;
        
        for(auto x:adj[curr])
        {
            if(DFS(x,adj,vis,anc))
            return true;
        }
        
        anc[curr]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>vis(V,false);
        vector<bool>anc(V,false);
        for(int i=0;i<V;i++)
        {
            if((!vis[i]) and (DFS(i,adj,vis,anc)))
                return true;
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends