// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    private:
    int find_par(int x, vector<int>&par)
    {
        if(par[x]==x)
        return par[x];
        
        return par[x]=find_par(par[x],par);
    }
    
    void DSU_Union(int s, int d, vector<int>&par, vector<int>&rank)
    {
        int p1=find_par(s,par), p2=find_par(d,par);
        
        if(p1==p2)
        return;
        
        if(rank[p1]>rank[p2])
        par[p2]=p1;
        
        else if (rank[p1]<rank[p2])
        par[p1]=p2;
        
        else
        {
            rank[p1]++;
            par[p2]=p1;
        }
        return;
    }
    
    public:
    //Function to detect cycle using DSU in an undirected graph.
    
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    
	    vector<int>par(V),rank(V,0);
	    vector<vector<bool>>vis(V,vector<bool>(V,false));
	    
	    for(int i=0;i<V;i++)
	    par[i]=i;
	    
	    for(int i=0;i<V;i++)
	    {
	        for(int j : adj[i])
	        {
	            if(vis[i][j])
	            continue;
	            
	            vis[i][j]=vis[j][i]=true;
	            
	            if(find_par(i,par)==find_par(j,par))
	            return true;
	            
	            else
	            DSU_Union(i,j,par,rank);
	        }
	    }
	    
	    return false;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}  // } Driver Code Ends