class Solution {
public:

    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>adj;
        int n = arr.size();
        bool vis[n];
        memset(vis,0,sizeof vis);
        
        for(int i=0;i<arr.size();i++){
            adj[arr[i]].push_back(i);
        }
        
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        int steps = 0;
        
        
        while(q.size()){
            
            int sz = q.size();
            while(sz --){
                int curr = q.front();
                q.pop();
                
                if(curr == n-1)
                    return steps;
                
                for(int&i : adj[arr[curr]]){
                    
                    if(!vis[i]){
                        
                        if(i == n-1)
                            return steps+1;
                        
                        vis[i] = 1;
                        q.push(i);
                    }
                    
                }
                adj.erase(arr[curr]);
                
                if(!vis[curr+1]){
                    if(curr+1 == n-1)
                            return steps+1;
                    vis[curr+1] = 1;
                    q.push(curr+1);
                }
                
                if(curr-1>=0 and !vis[curr-1]){
                    
                    if(curr-1 == n-1)
                            return steps+1;
                    vis[curr-1] = 1;
                    q.push(curr-1);
                }
            }
            steps++;
        }
        
        return -1;
        
        
    }
};