// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int rank1[100001];


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    private:
    int find(int x, int par[])
    {
        if(x==par[x])
        return par[x];
        
        par[x]=find(par[x],par);
        return par[x];
    }
    
    public:
    //Function to merge two nodes a and b.
    void unionNodes( int a, int b, int par[], int rank[], int n) 
    {
        //code here
        int p1=find(a,par),p2=find(b,par);
        
        if(p1==p2)
        return;
        
        if(rank[p1]>rank[p2])
        {
            par[p2]=par[p1];
        }
        
        else if(rank[p1]>rank[p2])
        {
            par[p1]=par[p2];
        }
        
        else
        {
            rank[par[p1]]++;
            par[p2]=par[p1];
        }
    }
    
    //Function to determine number of connected components.
    int findNumberOfConnectedComponents( int n, int par[], int rank[]) 
    {
        //code here
        unordered_set<int>s;
        
        for(int i=1;i<=n;i++)
        s.insert(find(i,arr));
        
        return s.size();
    }
};

// { Driver Code Starts.



int main() {
    int t;
    cin>>t;

    while(t--) {
        
        //taking number of nodes
        int n;
        cin>>n;

        //initializing parent array and
        //rank array
        for(int i=1; i<=n; i++) {
            arr[i] = i;
            rank1[i] = 1;
        }

        //taking number of queries
        int q;
        cin>>q;
        Solution obj;
        while(q--) {
            int a,b;
            cin>>a>>b;
            
            //calling unionNodes() function
            obj.unionNodes(a,b, arr, rank1, n);
        }

        //calling function findNumberofConnectedComponents()
        cout<<obj.findNumberOfConnectedComponents(n, arr, rank1)<<endl;
    }
    return 0;
}  // } Driver Code Ends