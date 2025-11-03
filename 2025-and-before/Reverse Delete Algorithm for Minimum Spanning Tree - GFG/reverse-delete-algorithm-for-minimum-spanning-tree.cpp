//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    
    struct myComp{
        
        bool operator()(const array<int,3>&a, const array<int,3>&b){
            return a[2]<b[2];
        }
    };
    
    int findPar(vector<int>&par, int p){
        
        if(par[p] == p)
        return p;
        
        return par[p] = findPar(par,par[p]);
    }
    
    bool DSUnion(int v1,int v2,vector<int>&par, vector<int>&rank){
        
        int p1 = findPar(par,v1),p2 = findPar(par,v2);
        
        if(p1 == p2)
            return true;
        
        if(rank[p1]>=rank[p2]){
            par[p2] = p1;
            rank[p1]++;
        }
        
        else{
            par[p1] = p2;
            rank[p2]++;
        }
        
        return false;
    }
    
    int RevDelMST(int arr[], int V, int E) {
        // code here
        
        vector<array<int,3>>edges;
        
        for(int i=2;i<E*3;i+=3){
            
            int u = arr[i-2], v = arr[i-1], wt = arr[i];
            edges.push_back({u,v,wt});
        }
        
        sort(edges.begin(),edges.end(),myComp());
        vector<int>par(V),rank(V,0);
        
        for(int i=0;i<V;i++){
            par[i] = i;
        }
        
        
        int ans= 0;
        
        for(auto&e :edges){
            
            int u= e[0], v = e[1], wt = e[2];
            
            if(!DSUnion(u,v,par,rank))
                ans+=wt;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,E;
        cin>>V>>E;

        int Arr[3*E];
        for(int i=0; i<3*E; i++)
            cin>>Arr[i];

        Solution ob;
        cout << ob.RevDelMST(Arr,V,E) << endl;
    }
    return 0;
}
// } Driver Code Ends