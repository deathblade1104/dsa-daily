class Solution {
public:
    struct Node
    {
        int dest,color;
        
        Node(int d, int c)
        {
            dest=d;
            color=c;
        }
    };
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    
        vector<Node>adj[n];
        vector<int>ans(n,INT_MAX);
        vector<vector<bool>>vis(n,vector<bool>(3,false));
        
        for(int i=0;i<redEdges.size();i++)
        {
            auto p=redEdges[i];
            adj[p[0]].push_back(Node(p[1],1));            
        }
        
        for(int i=0;i<blueEdges.size();i++)
        {
            auto p=blueEdges[i];
            adj[p[0]].push_back(Node(p[1],2));            
        }
        
        queue<Node>q;
        q.push(Node(0,0));
        int steps=0;
        
        while(q.size()>0)
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto p=q.front();
                q.pop();
                
                int v=p.dest, c=p.color;
                ans[v]= min(ans[v],steps);
                vis[v][c]=true;
                
                for(auto neigh : adj[v])
                {
                    if(neigh.color!=c and vis[neigh.dest][neigh.color]==false)
                        q.push(neigh);
                }                
            }
            steps++;
        }
        
        for(int i=0;i<ans.size();i++)
            if(ans[i]==INT_MAX)
                ans[i]=-1;
        
        return ans;
    }
};