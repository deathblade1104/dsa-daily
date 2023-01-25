class Solution {
public:
    
    vector<int>BFShelper(int n, vector<int>adj[],int src){
        
        vector<int>dist(n,INT_MAX);
        
        dist[src] = 0;

        queue<int>q;
        q.push(src);
        
        while(q.size()){
            
            int sz = q.size();
            while(sz --){
                
                int curr = q.front();
                q.pop();
                
                for(int&neigh : adj[curr]){
                    
                    if(dist[neigh]==INT_MAX){
                        dist[neigh] = dist[curr]+1;
                        q.push(neigh);
                    }   
                }
            }
        }
        
        return dist;
    }
    
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>adj[n];
        
        for(int i=0;i<n;i++){
            
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
        
        vector<int>dist1 = BFShelper(n,adj,node1);
        vector<int>dist2 = BFShelper(n,adj,node2);
        
        int ans = -1,res = INT_MAX;
        
        for(int i=0;i<n;i++){
                
            int currRes = max(dist1[i],dist2[i]);

            if(currRes<res){
                res = currRes;
                ans = i;
            
            }
            
            //cout<<i<<" -- "<<dist1[i]<<" -- "<<dist2[i]<<endl;
        }
        
        return ans; 
    }
};