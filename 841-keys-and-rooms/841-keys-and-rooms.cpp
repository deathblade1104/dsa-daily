class Solution {
    private:
    bool DFS(int curr,int sz,unordered_set<int>&st,vector<vector<int>>&adj)
    {
        st.insert(curr);
        if(st.size()==sz)
            return true;
        
        bool ans=false;
        for(int x : adj[curr])
        {
            if(st.count(x)==0)
            {
                ans= (ans | DFS(x,sz,st,adj));
                if(ans)
                    return true;
            }
        }
        
        return ans;       
    }
    
    public:
    bool canVisitAllRooms(vector<vector<int>>& adj) {
        unordered_set<int>st;
        int curr=0,sz=adj.size();
        
        return DFS(curr,sz,st,adj);
        
    }
};