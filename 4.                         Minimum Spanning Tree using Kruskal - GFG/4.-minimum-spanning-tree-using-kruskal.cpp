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
int
findRoot (int a, int parent[])
{
  if (a == parent[a])
    return a;
  parent[a] = findRoot (parent[a], parent);
  return parent[a];
}

void
union_Nodes (int a, int b, int parent[], int rank[])
{
  int x = findRoot (a, parent);
  int y = findRoot (b, parent);
  if (x == y)
    return;
  else if (rank[x] < rank[y])
    parent[x] = y;
  else if (rank[y] < rank[x])
    parent[y] = x;
  else
    {
      parent[x] = y;
      rank[y]++;
    }
}

bool
same (int a, int b, int parent[], int rank[])
{
  return findRoot (a, parent) == findRoot (b, parent);
}

long long int kruskalDSU (vector < pair < int, long long int >>adj[], int n, int m)
{
  pair < long long int, pair < int, int >>edges[2 * m]; //convert into an edge list where the first parameter in the pair is the edge weight to facilitate sorting
  int parent[n + 1], rank[n + 1];
  for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
      rank[i] = 1;
    }
  int index = 0;
  for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j < adj[i].size (); j++)
	{
	  edges[index++] =
	    make_pair (adj[i][j].second, make_pair (i, adj[i][j].first));
	}
    }
  sort (edges, edges + index);
  long long int mst = 0;
  for (int i = 0; i < 2 * m; i++)
    {
      int a = edges[i].second.first;
      int b = edges[i].second.second;
      if (!same (a, b, parent, rank))
	{
	  union_Nodes (a, b, parent, rank);
	  mst += edges[i].first;
	}
    }
  return mst;
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