class Solution {
public:
    
    long long ans;
    int DFS(int curr,int&size,int prev,vector<vector<int>>&adj){
        
        long long currPeople = 1;
        
        for(int&neigh : adj[curr]){
            
            if(neigh != prev)
                currPeople+=DFS(neigh,size,curr,adj);
        }
        
        int rem = currPeople%size;
        
        if(curr!=0){
            if(rem)
                ans++;
            
            ans+=(1LL *(currPeople/size));
        }
        return currPeople;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n = roads.size();
        vector<vector<int>>adj(n+1);
        
        for(auto&it : roads){
            int u = it[0],v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        ans = 0LL;
        
        long long curr  = DFS(0,seats,-1,adj);
    
        
        return ans;
        
    }
};