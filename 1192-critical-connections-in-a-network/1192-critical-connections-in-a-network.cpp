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
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int>adj[n];
        for(auto temp : connections)
        {   
            adj[temp[0]].push_back(temp[1]);
            adj[temp[1]].push_back(temp[0]);
        }
        
        return critical_edges(n,adj);
    }
};