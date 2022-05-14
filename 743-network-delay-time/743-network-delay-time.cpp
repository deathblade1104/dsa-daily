class Solution {
public:
    struct mycomp
    {
        bool operator()(const array<int,2>&a, const array<int,2>&b)
        {
            return a[1]>b[1];
        }
    };
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if(times.size()<n-1) return -1;
        
        array<vector<array<int,2>>,101>adj;
        for(auto &v : times)
            adj[v[0]].push_back({v[1],v[2]});        
               
        array<int,101>vis;
        vis.fill(INT_MAX);
        vis[k]=0;    
        
        priority_queue<array<int,2>, vector<array<int,2>> , mycomp>pq;
        pq.push({k,0});
        
        while(pq.size()>0)
        {
            auto p = pq.top();
            pq.pop();
    
            for(auto&neigh : adj[p[0]])
            {          
                
                if(vis[neigh[0]]>p[1] + neigh[1])
                {
                    vis[neigh[0]] = p[1] + neigh[1];
                    pq.push({neigh[0],vis[neigh[0]]});
                }
            }
            
        }
        
        int ans=0;
        for(int i=1;i<=n;i++)
        {
           if(vis[i]==INT_MAX)
               return -1;
            
            ans=max(ans,vis[i]);
        }
        
        return ans;
    }
};