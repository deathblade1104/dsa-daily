class Solution {
public:
    
    long long DFS(int curr,int prev,int&seats,long long&ans,vector<int>adj[]){
        
        long long temp = 1LL;
        
        for(int&neigh : adj[curr]){
            
            if(neigh != prev){
                
                temp+=DFS(neigh,curr,seats,ans,adj);
            }
        }
        
        if(curr!=0){
            ans+=(1LL *(temp/seats));
            
            if(temp%seats)
                ans++;
        }
        
        return temp;
    
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n = roads.size();
        
        vector<int>adj[n + 1];
        
        for(auto&f : roads){
            adj[f[0]].push_back(f[1]);
            adj[f[1]].push_back(f[0]);
        }
        
        long long ans = 0LL;
        long long temp = DFS(0,-1,seats,ans,adj);
        
        return ans;
    }
};