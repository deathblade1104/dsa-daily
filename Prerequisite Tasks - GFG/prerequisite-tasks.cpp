// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool DFS(int curr, vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&anc)
    {
        if(vis[curr])
        {
            if(anc[curr])
            return true;
            
            return false;
        
        }
        
        vis[curr]=true;
        anc[curr]=true;
        
        for(int x : adj[curr])
        {
            if(DFS(x,adj,vis,anc))
            return true;
        }
        
        anc[curr]=false;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code 
	    vector<vector<int>>adj(N);
	    
	    for(auto i :pre)
	    adj[i.second].push_back(i.first);
	    

	    vector<bool>vis(N,false),anc(N,false);
	    
	    for(int i=0;i<N;i++)
	    {
	        if(!vis[i] and DFS(i,adj,vis,anc))
	            return false;
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends