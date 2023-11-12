class Solution {
public:
    vector<int>adj[1000001];
    bool vis[100001];
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        for(int i=0;i<routes.size();i++){
            for(auto&node : routes[i]){
                adj[node].push_back(i);
            }
        }
        
        memset(vis,0,sizeof vis);
        
        int steps  = 0 ;
        queue<int>q;
        q.push(source);
        
        while(q.size()){
            
            int sz = q.size();
            
            while(sz--){
                    
                int curr = q.front();
                q.pop();
                
                if(curr == target)
                    return steps;
                
                for(int&route : adj[curr]){
                    if(vis[route] == 0){
                        for(auto&neigh : routes[route]){
                            if(neigh == curr)
                                continue;
                            
                            q.push(neigh);
                        }
                        vis[route]=1;
                    }
                }
                
            }
            
            steps++;
        }
        
        
        return -1;
    }
};