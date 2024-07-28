class Solution {
public:
    
    
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<vector<int>>adj(n+1);
     
        for(auto&vec : edges){
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<vector<int>>visitedTimes(n+1);
        
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>pq;
        visitedTimes[1] = {0};
        pq.push({0,1});
        
        
        while(pq.size() >0){
            
            array<int,2>curr = pq.top();
            pq.pop();
            
            int currTime= curr[0], currNode = curr[1],newTime = (((currTime / change) % 2) ? (currTime / change + 1) * change : currTime) + time;
            
            for(int&neigh : adj[currNode]){
                
                int sz = visitedTimes[neigh].size();
                
                if(sz == 2)
                    continue; 
                
                if(sz == 0 || (sz == 1 and visitedTimes[neigh][0]!=newTime)){
                    
                    if(sz == 1 and neigh == n and newTime!=visitedTimes[neigh][0])
                        return newTime;
                    
                    pq.push({newTime,neigh});
                    visitedTimes[neigh].push_back(newTime);
                }
        
            }
            
            
            
        }
        
        
        return -1;
        
        
    }
};