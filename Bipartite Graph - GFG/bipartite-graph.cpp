// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private :
    bool DFS(int curr, int color, vector<int>&vis, vector<int>adj[])
    {
        vis[curr]= color;
        bool ans = true;
        
        for (int x : adj[curr])
        {
            if(vis[x]==-1)
            ans = ans & DFS(x,!color,vis,adj);
            
            else if(vis[x]==color or ans == false)
            return false;
        }
        return ans;
    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int>vis(V,-1);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==-1 and !DFS(i,1,vis,adj))
	        return false;
	    }
	    
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends