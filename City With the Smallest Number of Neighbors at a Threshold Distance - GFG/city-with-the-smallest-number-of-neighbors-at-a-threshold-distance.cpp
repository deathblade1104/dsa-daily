//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    struct mycomp{
        
        bool operator()(const array<int,2>&a, const array<int,2>&b){
            
            return a[1]>=b[1];
        }
    };
    
    vector<vector<int>>adj[101];
    int cost[101];
    
    int dijkstra(int&currNode,int&k){
        
        memset(cost,9999999,sizeof cost);
        priority_queue<array<int,2>,vector<array<int,2>>,mycomp>pq;
        pq.push({currNode,0});
        unordered_set<int>vis;
        
        while(pq.size()){
            
            auto curr = pq.top();
            pq.pop();
            
            int cn = curr[0],cc = curr[1];
            
            cost[cn] = cc;
            vis.insert(cn);
            
            for(auto neighbours : adj[cn]){
                int nv = neighbours[0], nc = cc + neighbours[1];
                
                if(nc<=k and cost[nv]>nc){
                    pq.push({nv,nc});
                }
            }
        }
        
        return vis.size()-1;
    }
    
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        
        for(int i=0;i<m;i++){
            int u = edges[i][0], v = edges[i][1] , w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        int res = INT_MAX, ans =-1;
        
        for(int i=0;i<n;i++){
            int curr =dijkstra(i,distanceThreshold);
            
            if(curr<=res){
                res = curr;
                ans=i;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends