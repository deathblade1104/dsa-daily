// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>dist(n,INT_MAX);
	    dist[0]=0;
	    
	    for(int i=0;i<n-1;i++)
	    {
	        bool flag=false;
	        
	        for(auto x : edges)
	        {
	            int source= x[0], dest= x[1], weight = x[2];
	            
	            if(dist[source] != INT_MAX and dist[dest] > dist[source] + weight)
	            {
	                flag = true;
	                dist[dest] = dist[source] + weight;
	            }
	        }
	        
	        if(flag==false) return 0;
	    }
	    
	    for(auto x : edges)
        {
            int source= x[0], dest= x[1], weight = x[2];
            
            if(dist[source] != INT_MAX and dist[dest] > dist[source] + weight)
            return 1;
        }
        
        return 0;
	}
        
        
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends