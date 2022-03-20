class Solution {
private:
    void DFS(int curr,int prevTime, int &ans,vector<int>adj[],vector<int>&inform)
    {
        int currTime = prevTime + inform[curr];
        ans=max(ans,currTime);
        
        for(int x : adj[curr])            
            DFS(x,currTime,ans,adj,inform);
        
        return;
        
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& inform) {
        
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        
        int ans=0;
        DFS(headID,0,ans,adj,inform);
        return ans;
    }
};