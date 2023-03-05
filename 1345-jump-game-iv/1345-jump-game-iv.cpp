class Solution {
public:

    bool vis[50001];
    
    void insertInQueue(queue<int>&q,int curr,int&n){
        
        if(curr>=0 and curr<n and !vis[curr]){
            vis[curr] = 1;
            q.push(curr);
        }
        return;
    }
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>adj;
        int n = arr.size();
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
                    insertInQueue(q,i,n);
                }
                adj.erase(arr[curr]);
                insertInQueue(q,curr+1,n);
                insertInQueue(q,curr-1,n);
            }
            steps++;
        }
        
        return -1;
        
        
    }
};