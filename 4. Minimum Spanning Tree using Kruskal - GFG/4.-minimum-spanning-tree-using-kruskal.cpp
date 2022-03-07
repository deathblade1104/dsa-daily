// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function Template for C++


/**
 *  ith value in adj vector contains information between the node connected to it and weight between them.
 *  Example. for a value 2 3 1, Node 2 and Node 3 has weight 1. adj[2] = {3,1} and adj[3] = {2,1}.
 *  n -> number of nodes
 *  m -> total number of edges
 *  return the mst value
*/

//Function to find the minimum spanning tree value using Kruskal.
struct Node{
    int src,dest;
    long long int wt;
    
    Node(int a, int b, long long int w)
    {
        src=a;
        dest=b;
        wt=w;
    }
};

struct mycomp{
    bool operator()(const Node&a,const Node&b)
    {
        return a.wt<b.wt;
    }
};

vector<Node>make_edges(vector<pair<int, long long int>> adj[],int n)
{
    vector<Node>edges;
    
    for(int i=1;i<=n;i++)
    {
        for(auto x : adj[i])
        {
            Node n1(i,x.first,x.second);
            edges.push_back(n1);
        }
    }
    
    sort(edges.begin(),edges.end(),mycomp());
    return edges;
}

int find_par(int v, vector<int>&par)
{
    if(par[v]==v)
    return v;
    
    
    par[v] = find_par(par[v],par);
    return par[v];
}
void DSU_union(int s,int d, vector<int>&par, vector<int>&rank)
{
    int p1=find_par(s,par);
    int p2=find_par(d,par);
    
    if(p1 == p2)
    return;

    if(rank[p1] < rank[p2])
    par[p1] = p2;
    
    else if (rank[p2] < rank[p1])
    par[p2] = p1;
    
    else
    {
        par[p1] = p2;
        rank[p2]++;
    }
}

long long int kruskalDSU(vector<pair<int, long long int>> adj[], int n, int m) 
{
    vector<Node>edges=make_edges(adj,n);
    vector<int>par(n+1,0),rank(n+1,0);
    
    for(int i=0;i<=n;i++)
    par[i]=i;
    
    int count=0;
    long long ans=0;
    for(auto it : edges)
    {
        int s=it.src,d=it.dest;
        long long w=it.wt;
        
        if(find_par(s,par)==find_par(d,par))
        continue;
        
        else
        {
            ans+=w;
            count++;
            DSU_union(s,d,par,rank);
        }
        if(count>=n)
        break;
    }
    
    return ans;
}

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;

    vector<pair<int, long long int>> adj[100009];

    while(t--) {

        int n,m;
        cin>>n>>m;

        int u,v;
        long long w;
        for(int i=0; i<m; i++) {
            cin>>u>>v>>w;
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }

        cout<<kruskalDSU(adj, n, m)<<endl;

        for(int i=0; i<=n; i++) {
            adj[i].clear();
        }
    }
    return 0;
}
  // } Driver Code Ends