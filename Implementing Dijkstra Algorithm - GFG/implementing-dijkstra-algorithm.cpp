// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{  
    private:
    struct mycomp
    {
        bool operator()(const pair<int,int>&a, const pair<int,int>&b)
        {
            if(a.second!=b.second)
                return (a.second>b.second);
                
            return (a.first>b.first);
        }
    };
	public: 
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>cost(V,-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>, mycomp>pq;
        pq.push({S,0});

        
        while(pq.size()>0)
        {
            pair<int,int>p=pq.top();
            pq.pop();
            
            if(cost[p.first]==-1)
            {
                cost[p.first]=p.second;
                for(auto neighbours : adj[p.first])
                {
                    int nv=neighbours[0],nc=neighbours[1]+p.second;
                    if(cost[nv]==-1)
                        pq.push({nv,nc});
                    
                }
            }
        }
        
      
        
        return cost;
        
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends