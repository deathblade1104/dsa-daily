class Graph {
public:
    
    int n;
    vector<array<int,2>>adj[101];
    Graph(int N, vector<vector<int>>& edges) {
        n = N;
        for(auto&e : edges)
            adj[e[0]].push_back({e[1],e[2]});
        
    }
    
    void addEdge(vector<int> e) {
        adj[e[0]].push_back({e[1],e[2]});
        
    }
    
    int shortestPath(int S, int node2) {
        priority_queue<array<long long,2>,vector<array<long long,2>>, greater<array<long long,2>>>pq;
        pq.push({0,S});
        vector<long long>vis(n,LLONG_MAX);
        vis[S] = 0;
        
        while(pq.size()>0)
        {
            array<long long,2>p=pq.top();
            pq.pop();
            
            if(p[1] == node2)
                return p[0];
            
            //cout<<p[0]<<" "<<p[1]<<endl;
            
            for(auto&neighbours : adj[p[1]])
            {
                long long nv=neighbours[0],nc=neighbours[1]+p[0];
                if(vis[nv]>nc){
                    pq.push({nc,nv});
                    vis[nv] = nc;
                }

             }
            
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */