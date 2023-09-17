class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adj) {
    
        int n = adj.size(), tot = (1<<n)-1; ;
        
        bool vis[n][tot+1];
        memset(vis,0,sizeof vis);
        
        //cout<<tot<<endl;
        
        queue<array<int,2>>q;
        
        for(int i=0;i<n;i++){
            
             q.push({i,1<<i});
            
            //cout<<(1<<i)<<endl;
             vis[i][1<<i] = true;
        }
        
        int steps = 0;
        while(q.size()){
            
            int sz = q.size();
            while(sz --){
                
                array<int,2>arr = q.front();
                q.pop();
                
                int curr =  arr[0], state = arr[1];
                
                if(state == tot)
                    return steps;
                
                for(int&neigh : adj[curr]){
                    
                    int newState = state | (1<<neigh);
                    if(!vis[neigh][newState]){
                        q.push({neigh,newState});
                        vis[neigh][newState] = 1;
                    }
                }
                
            }
            
            steps++;
        }
        
        
        return -1;
        
    }
};