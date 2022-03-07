// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to merge two nodes a and b.
    int find(int x , int par[])
    {
        if(par[x]==x)
        return x;
        
        par[x]=find(par[x],par);
        return par[x];
    }
    
    void union_( int a, int b, int par[], int rank[]) 
    {
        //code here
        
        int s1=find(a,par),s2=find(b,par);
        
        if(s1==s2)
        return;
        
        if(rank[s1]>rank[s2])
            par[s2]=par[s1];
            
        else if(rank[s1]<rank[s2])
            par[s1]=par[s2];
            
        else
        {
            rank[par[s1]]++;
            par[s2]=par[s1];
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank[])
    {
        //code here
        int s1=find(x,par),s2=find(y,par);
        return (s1==s2);
        
    }
};

// { Driver Code Starts.

int main() {
    //taking number of testcases
    int t;
    cin>>t;
    while(t--) {
        
        //taking number of elements
        int n;
        cin>>n;
        
        
        int par[n+1];
        int rank1[n+1];

        //initializing the parent and
        //the rank array
        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    //taking number of queries
    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        //if query type is 'U'
        //then calling union_ method
        if(c=='U')
        {
            obj.union_(a,b, par, rank1);
        }
        else//else calling isConnected() method
        cout<<obj.isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}
  // } Driver Code Ends