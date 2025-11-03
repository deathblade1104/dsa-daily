class Solution {
private:
    void DFS(int curr, vector<bool>&vis, vector<vector<int>>&adj)
    {
        vis[curr]=true;        
        for(int i=0;i<adj[curr].size();i++)
        {
            if(i!=curr and adj[curr][i]==1 and !vis[i])
                DFS(i,vis,adj);
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size(),count=0;
        vector<bool>vis(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                DFS(i,vis,adj);
            }
        }
        return count;
    }
};