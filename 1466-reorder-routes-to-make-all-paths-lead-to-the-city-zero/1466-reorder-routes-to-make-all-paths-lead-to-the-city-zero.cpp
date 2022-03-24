class Solution {

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,bool>>adj[n];
        vector<bool>vis(n,false);
        
        for(int i =0;i<connections.size();i++)
        {
            auto p = connections[i];
            int u=p[0],v=p[1];
            
            adj[u].push_back({v,true});
            adj[v].push_back({u,false});
        }
        
        vis[0]=true;
        
        int ans=0;
        queue<pair<int,int>>q;
        q.push({0,-1});
        
        while(q.size()>0)
        {
            
            auto [curr, p]= q.front();
            q.pop();
            
            // cout<<curr<<" : ";
             for(auto neigh : adj[curr])
             {
                if(!vis[neigh.first])
                {
                    if(neigh.second==true)  
                    {
                        ans++;
                        // cout<<"Counting  --> "<<neigh.first<<endl;
                    }

                    vis[neigh.first]=true;
                    q.push({neigh.first,curr});
                }
             }
            // cout<<endl;
        }
        
        return ans;
        
    }
};