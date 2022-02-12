// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    if(X>=V)
	    return -1;

	    vector<bool>vis(V,false);
	    queue<int>q;
	    q.push(0);
	    vis[0]=true;
	    
	    bool found=false;
	    int height=0,ans=-1;
	    while(q.size()>0)
	    {
	        int sz=q.size();
	        for(int i=0;i<sz;i++)
	        {
	            int curr=q.front();
	            q.pop();
	            vis[curr]=true;
	            
	            if(curr==X)
	            {
	                found=true;
	                ans=height;
	                break;
	            }
	            
	            for(auto it : adj[curr])
	            {
	                if(!vis[it])
	                q.push(it);
	            }
	        }
	        
	        if(found)
	        break;
	        
	        else
	        height++;
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends