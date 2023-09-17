class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adj) {
        int n=adj.size(),target=(1<<n)-1;
        vector<vector<bool>>vis(n,vector<bool>(target+1,false));
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++)
        {
            q.push({i,(1<<i)});
            vis[i][1<<i]=true;
        }
        
        int steps=0;
        while(q.size()>0)
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto [curr,edge] = q.front();
                q.pop();
                
                if(edge==target)
                    return steps;
                
                for(auto neigh : adj[curr])
                {
                    int new_edge = (1<<neigh)|edge;
                    
                    if(vis[neigh][new_edge]==false)
                    {
                        q.push({neigh,new_edge});
                        vis[neigh][new_edge]=true;
                    }
                }
            }
            steps++;
        }
        return -1;
        
        
    }
};