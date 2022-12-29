class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<int>inEdges(n,0),dp(n,0);
        vector<vector<int>>adj(n, vector<int>());
        
        for(auto&v : relations){
            inEdges[v[1]-1]++;
            
            adj[v[0] - 1].push_back(v[1] - 1);
        }
        
        queue<int>q;
        
        for(int i=0;i<n;i++)
            if(inEdges[i]==0){
                q.push(i);
                dp[i]=time[i];
            }
        
        int ans = 0;
        
        
        while(q.size()){
            
            int sz = q.size();
            
            while(sz --){
                   
                int curr = q.front();
                q.pop();
                
                for(auto&neigh : adj[curr]){
                    
                    dp[neigh] = max(dp[neigh], time[neigh] + dp[curr]);
                    
                    inEdges[neigh]--;
                    
                    if(inEdges[neigh] == 0)
                        q.push(neigh);
                }
            }
        }
        
        for(int&x: dp)
            ans=max(ans,x);
        
        
        return ans;
        
        
        
        
    }
};