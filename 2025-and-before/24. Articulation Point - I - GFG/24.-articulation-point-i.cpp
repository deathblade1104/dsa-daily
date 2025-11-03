// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    
    private :
    void tarjanDFS(vector<int>adj[], int curr, int par,int &t,vector<int>&disc, vector<int>&low_time,vector<bool>&ans)
  {
      disc[curr]=t;
      low_time[curr]=t;
      t++;
      
      int c=0;
      for(int neigh : adj[curr])
      {
          if(neigh==par)
          continue;
          
          if(disc[neigh]!=-1)
          {
            low_time[curr] = min(low_time[curr],disc[neigh]);
            continue;
          }
          
          
          tarjanDFS(adj,neigh,curr,t,disc,low_time,ans);
          c++;
          
          low_time[curr] = min(low_time[curr],low_time[neigh]);
          
          if(par!=-1 and disc[curr]<=low_time[neigh])
            ans[curr]=true;
      }
      
      if(par==-1 and c>1)
      ans[curr]=true;
      
      return;
  }
  
  vector<bool>ap(int V, vector<int>adj[])
  {
      vector<int>disc(V,-1),low_time(V,-1);
      int t=0;
      vector<bool>ans(V,false); 
      tarjanDFS(adj,0,-1,t,disc,low_time,ans);
      return ans;
  }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        
        vector<bool>a=ap(V,adj);
        
        vector<int>ans;
        
        for(int i=0;i<V;i++)
        {
            if(a[i])
            ans.push_back(i);
        }
        
        if(ans.size()==0)
            ans.push_back(-1);
            
        return ans;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends