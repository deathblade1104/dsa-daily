// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void solve(vector<vector<int>>&edges, int &destination, int curr, vector<bool>&vis, int &count)
    {
        if(curr==destination)
        {
            ++count;
            return;
        }
        
        if(vis[curr]==true)
        return;
        
        vis[curr]=true;
        
        for(auto x : edges[curr])
        {
            if(vis[x]==false)
            solve(edges,destination,x,vis,count);
        }
        
        vis[curr]=false;
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    
	    vector<vector<int>>adj(n);
	    
	    for(int i=0;i<edges.size();i++)
	    adj[edges[i][0]].push_back(edges[i][1]);
	 
	    vector<bool>vis(n,false);
	    int count=0;
	    solve(adj,d,s,vis,count);
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends