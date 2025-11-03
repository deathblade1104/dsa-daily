class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        
        unordered_set<int>vis;
        queue<int>q;
        q.push(0);
        vis.insert(0);
        
        while(q.size()){
            
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                
                for(auto&neigh : rooms[curr]){
                    
                    if(vis.count(neigh)==0){
                       q.push(neigh);
                       vis.insert(neigh);
                    }
                }
            }
        }
        
        return vis.size() == rooms.size();
    }
    
};