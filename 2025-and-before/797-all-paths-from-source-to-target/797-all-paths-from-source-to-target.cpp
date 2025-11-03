class Solution {
private:
    void DFS(int curr,int des,vector<vector<int>>&adj,vector<int>&temp,vector<bool>&vis,vector<vector<int>>&ans)
    {
        if(curr==des)
        {
            temp.push_back(curr);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        temp.push_back(curr);
        vis[curr]=true;
        
        for(int x : adj[curr])
        {
            if(!vis[x])
                DFS(x,des,adj,temp,vis,ans);
        }
        vis[curr]=false;
        temp.pop_back();
        return;
        
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>vis(adj.size(),false);
        int src=0,dest=adj.size()-1;
        
        DFS(src,dest,adj,temp,vis,ans);        
        return ans;
        
    }
};