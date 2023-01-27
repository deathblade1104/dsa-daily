class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<array<int,2>>adj[n];
        
        for(auto&f : flights){
            
            adj[f[0]].push_back({f[1],f[2]});
        }
        
        queue<array<int,2>>q;
        int dist[n];
        
        for(int i=0;i<n;i++){
            dist[i] = INT_MAX;
        }
        dist[src] = 0;
        
        q.push({src,0});
        int steps = 0;
        
        while(steps<=k and q.size()){
            
            int sz = q.size();
            
            while(sz --){
                
                array<int,2>arr= q.front();
                q.pop();
                
                //cout<<arr[0]<<" ";
                for(auto&v : adj[arr[0]]){
                    
                    int neigh = v[0], neighDist = v[1] + arr[1];
                    //cout<<neigh<<" , ";
                    if(dist[neigh]>neighDist){
                        dist[neigh] = neighDist;
                        q.push({neigh,neighDist});
                    }
                }
                //cout<<endl;
            }
            
            steps++;
        }
        
        
        return dist[dst] == INT_MAX? -1 : dist[dst];
    }
};