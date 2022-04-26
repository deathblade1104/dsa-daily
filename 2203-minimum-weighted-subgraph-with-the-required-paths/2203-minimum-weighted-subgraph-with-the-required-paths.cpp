class Solution {
public:
    struct mycomp
    {
      
        bool operator()(const pair<int,long long>&a, const pair<int,long long>&b)
        {
            return a.second>b.second;
        }
        
    };
    
    vector<long long> dijkstra(vector<vector<pair<int,long long>>>adj,int&n, int s1)
    {
        vector<long long>dist(n,LLONG_MAX/3);
        
        priority_queue<pair<int,long>,vector<pair<int,long>>,mycomp>pq;
        pq.emplace(s1,0);
                
        while(pq.size()>0)
        {
            auto p = pq.top();
            pq.pop();
            
            if(dist[p.first]!=LLONG_MAX/3)
                continue;
            
            dist[p.first]=p.second;
            for(auto neigh : adj[p.first])
            {
                if(dist[neigh.first]==LLONG_MAX/3)
                    pq.emplace(neigh.first,neigh.second+p.second);
            }
        }
        
        return dist;
        
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int s1, int s2, int dest) {
        vector<vector<pair<int,long long>>>adj(n),rev_adj(n);
        
        for(auto e : edges)
        {
            adj[e[0]].emplace_back(e[1],e[2]);
            rev_adj[e[1]].emplace_back(e[0],e[2]);
        }
        
        vector<long long>a1=dijkstra(adj,n,s1);
        vector<long long>a2=dijkstra(adj,n,s2);
        vector<long long>a3=dijkstra(rev_adj,n,dest);
        
        
        long long ans= LLONG_MAX;
        
        for(int i=0;i<n;i++)
            ans = min(ans,(a1[i]+a2[i]+a3[i]));
        
        if(ans>=LLONG_MAX/3)
            return -1;
        
        return ans;
        
        
    }
};