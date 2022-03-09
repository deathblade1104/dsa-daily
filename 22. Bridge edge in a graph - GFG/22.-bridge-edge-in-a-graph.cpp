// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    private:
    
    void DFS(int curr, int par, vector<bool>&vis , vector<int>adj[] , int &c, int &d)
    {
        if(vis[curr])
        return;
        
        vis[curr]=true;
        
        if(curr==d)
        return;
        
        for(int neigh : adj[curr])
        {
            if(neigh==par or  vis[neigh] or (curr==c and neigh==d))
            continue;
            
            DFS(neigh,curr,vis,adj,c,d);
        }
        
        return;
    }
  
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool>vis(V,false);
        
        DFS(c,-1,vis,adj,c,d);
        
        return (!vis[d]);
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends