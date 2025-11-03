//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int par[501],rank[501];
    
    int findPar(int v){
        
        if(par[v]==v)
            return v;
            
        return par[v] = findPar(par[v]);
    }
    
    void DSUnion(int i, int j){
        
        int p1 = findPar(i),p2=findPar(j),r1=rank[p1],r2=rank[p2];
        
        if(p1 == p2)
            return;
            
        if(rank[p1]>=rank[p2]){
            par[p2]=p1;
            rank[p1]++;
        }
        
        else{
            par[p1] = p2;
            rank[p2]++;
        }
        
        return;
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        memset(rank,1,sizeof rank);
        iota(par,par+501,0);
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 and i!=j)
                        DSUnion(i,j);
                
            }
        }
        
        unordered_set<int>st;
        for(int i=0;i<V;i++){
            //cout<<i<<"-->"<<findPar(i)<<endl;
            st.insert(findPar(i));
        }
            
        return st.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends