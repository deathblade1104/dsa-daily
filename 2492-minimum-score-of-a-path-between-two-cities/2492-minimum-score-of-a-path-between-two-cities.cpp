class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
     
        unordered_map<int,unordered_map<int,int>>adj;
        
        for(auto&road : roads){
            adj[road[0]][road[1]] = adj[road[1]][road[0]] = road[2]; 
        }
        
        int res = numeric_limits<int>::max();
        queue<int>q;
        q.push(1);
        unordered_set<int>vis;
        vis.insert(1);
        
        
        while(q.size()){
            
            int node = q.front();
            q.pop();
            
            for(auto& [neigh, score] : adj[node]){
                
                if(!vis.count(neigh)){
                    q.push(neigh);
                    vis.insert(neigh);
                }
                res = min(res,score);
            }
        }
        
        return res;
    }
};