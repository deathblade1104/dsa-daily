class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>inedges(n,0);
        
        for(auto &v : edges)
        {
            inedges[v[0]]++;
            inedges[v[1]]++;
            
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(inedges[i]==1)
                q.push(i);
        }
        
        while(q.size()>0)
        {
            ans.clear();
            int sz = q.size();
            
            while(sz--)
            {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                
                for(int&neigh : adj[curr])
                {
                    inedges[neigh]--;
                    if(inedges[neigh]==1)
                        q.push(neigh);
                }
            }
        }
        
        if(ans.size()==0)
            ans.push_back(0);
        return ans;
        
    }
};