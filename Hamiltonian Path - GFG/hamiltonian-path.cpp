//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    bool DFS(int curr,vector<vector<int>>&adj, unordered_set<int>&vis,int&n){
        
        vis.insert(curr);
        
        if(vis.size() == n)
            return true;
        
        for(int&neigh : adj[curr]){
            
            if(vis.count(neigh)==0 and DFS(neigh,adj,vis,n))
                    return true;
        }
        
        
        vis.erase(curr);
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        
        
        vector<vector<int>>adj(N+1);
        
        for(int i=0;i<M;i++){
            int u = Edges[i][0] , v = Edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_set<int>vis;
        for(int i=1;i<=N;i++){
            if(DFS(i,adj,vis,N))
                return true;
        }
        
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends