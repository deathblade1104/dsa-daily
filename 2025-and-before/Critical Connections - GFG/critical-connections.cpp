// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  private:
  void tarjanDFS(vector<int>adj[], int curr, int par,int &t,vector<int>&disc, vector<int>&low_time,vector<vector<int>>&ans)
  {
      disc[curr]=t;
      low_time[curr]=t;
      t++;
      
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
          
          low_time[curr] = min(low_time[curr],low_time[neigh]);
          
          if(disc[curr]<low_time[neigh])
          {
              if(curr<neigh)
              ans.push_back({curr,neigh});
              
              else
              ans.push_back({neigh,curr});
          }
      }
      return;
  }
  
  vector<vector<int>>critical_edges(int V, vector<int>adj[])
  {
      vector<int>disc(V,-1),low_time(V,-1);
      int t=0;
      vector<vector<int>>ans; 
      tarjanDFS(adj,0,-1,t,disc,low_time,ans);
      return ans;
  }
  
public:
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    // Code here
	    
	    vector<vector<int>>ans=critical_edges(V,adj);
	    sort(ans.begin(),ans.end());
	    
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
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}  // } Driver Code Ends