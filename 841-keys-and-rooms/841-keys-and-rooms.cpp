class Solution {
    private:
    bool DFS(int curr,int sz,int &count,vector<bool>&vis,vector<vector<int>>&adj)
    {
        count++;
        if(count==sz)
            return true;
        
        bool ans=false;
        vis[curr]=true;
        for(int x : adj[curr])
        {
            if(!vis[x])
            {
                ans= (ans | DFS(x,sz,count,vis,adj));
                if(ans)
                    return true;
            }
        }
        
        return ans;       
    }
    
    public:
    bool canVisitAllRooms(vector<vector<int>>& adj) {
        int curr=0,sz=adj.size(),count=0;
        vector<bool>vis(sz,false);
        
        return DFS(curr,sz,count,vis,adj);
        
    }
};