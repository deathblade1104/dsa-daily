class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>in(n,0);
        
        for(int i=0;i<edges.size();i++)
        {
            auto t = edges[i];
            
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
            
            in[t[0]]++;
            in[t[1]]++;
        }
        
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==1)
                q.push(i);
        }
        
        while(q.size()!=0)
        {
            ans.clear();
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int curr=q.front();
                q.pop();
                ans.push_back(curr);
                in[curr]--;
                
                for(int neigh : adj[curr])
                {
                    in[neigh]--;
                    if(in[neigh]==1)
                        q.push(neigh);
                }                
            }
        }
        
        if(ans.size()==0)
            ans.push_back(0);
        return ans;
        
    }
};