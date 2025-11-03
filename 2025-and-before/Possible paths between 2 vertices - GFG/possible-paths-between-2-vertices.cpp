// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    void solve(vector<int>adj[],int &dest, vector<bool>&vis, int curr, int &count)
    {
        if(curr==dest)
        {
           count++;
           return;
        }
        
        vis[curr]=true;

        for(auto x : adj[curr])
        {
            if(!vis[x])
            solve(adj,dest,vis,x,count);
        }
        vis[curr]=false;
        return;
    }
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        vector<bool>vis(V,false);
        int count=0;
        
        solve(adj,destination,vis,source,count);
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends