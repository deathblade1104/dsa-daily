class Solution {
public:
    
    vector<int>adj[1001];
    int vis[1001];
    bool seen[1001];
    
    void DFS(int curr,int par,int currDepth,int&currAns){
        
        if(vis[curr]!=-1 and seen[curr]){
            currAns = min(currDepth - vis[curr],currAns);
            return;
        }
        
        if(vis[curr]>=0){
            if(currDepth>vis[curr])
                return;
        }
        
        vis[curr] = currDepth;
        seen[curr] = true;
        
        for(int&neigh : adj[curr]){
            
            if(neigh == par)
                continue;
            
            DFS(neigh,curr,currDepth+1,currAns);
        }
        
        seen[curr] = false;
        return;
    }
   
    
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;i++){
            adj[i].clear();
            vis[i] = -1;
            seen[i] = false; 
        }
        
        for(vector<int>&edge : edges){
            int u = edge[0],v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int ans = n+1;
      
        for(int i=0;i<n;i++){
            
            if(vis[i]>=0)
                continue;
           
            int currAns = n+1;
            DFS(i,-1,1,currAns);
            ans = min(ans,currAns);
        }
        

        return ans>n? -1 : ans;
    }
};