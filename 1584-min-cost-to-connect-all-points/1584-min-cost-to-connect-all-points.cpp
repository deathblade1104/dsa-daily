class Solution {
public:
    struct mycomp
    {
        bool operator()(const array<int,2>&a, const array<int,2>&b)
        {
            return a[1]>b[1];
        }
    };
    
    int minCostConnectPoints(vector<vector<int>>& points) {
       
        int n = points.size();
        vector<vector<array<int,2>>>adj(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[j][1] - points[i][1]);
                adj[j].push_back({i,dist});
                adj[i].push_back({j,dist});
            }
        }
        
        priority_queue<array<int,2>, vector<array<int,2>> , mycomp>pq;
        pq.push({0,0});
        
        vector<bool>vis(n,false);
        int count =0, cost=0;
                
        while(pq.size()>0 and count<n)
        {
            auto p = pq.top();
            pq.pop();
            
            if(vis[p[0]])
                continue;
            
            vis[p[0]]=true;
            count++;            
            cost+=p[1];
            
            for(auto &neigh : adj[p[0]])
            {
                if(!vis[neigh[0]])
                    pq.push(neigh);
            }
        }
        
        return cost;
    }
};