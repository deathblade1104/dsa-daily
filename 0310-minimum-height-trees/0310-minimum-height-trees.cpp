class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        vector<int>inEdge(n,0);
        
        for(vector<int>&edg : edges){
            
            inEdge[edg[0]]++;
            inEdge[edg[1]]++;
            
            adj[edg[0]].push_back(edg[1]);
            adj[edg[1]].push_back(edg[0]);
        }
        
        
        queue<int>q;
        for(int i=0;i<n;i++){
            
            if(inEdge[i] == 1)
                q.push(i);
        }
        
        vector<int>ans;
        
        while(q.size()){
            
            int sz = q.size();
            ans.clear();
            
            while(sz--){
                
                int curr = q.front();
                q.pop();
                
                ans.push_back(curr);
               
                for(int&neigh : adj[curr]){
                    inEdge[neigh]--;
                    
                    if(inEdge[neigh] == 1){
                        q.push(neigh);
                    }
                }       
            }
        }
        
        if(ans.size() == 0)
            ans.push_back(0);
        
        
        return ans;
        
    }
};