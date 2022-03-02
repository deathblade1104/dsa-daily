// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    private:
    struct mycomp{
        bool operator()(const pair<int,int>&a,const pair<int,int>&b)
        {
            return a.second>b.second;
        }
    };
    
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<bool>vis(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomp>pq;
        pq.push({0,0});
        int count=0,ans=0;
        
        while(pq.size()>0 and count<=V)
        {
            auto p=pq.top();
            pq.pop();
            
            if(!vis[p.first])
            {
                vis[p.first]=true;
                count++;
                ans+=p.second;
                
                for(auto x : adj[p.first])
                    if(!vis[x[0]])
                        pq.push({x[0],x[1]});
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends