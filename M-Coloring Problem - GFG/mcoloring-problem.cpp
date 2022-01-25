// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(bool graph[101][101],int V, int curr, vector<int>&color)
{
    for(int i=0;i<V;i++)
    {
        if(i!=curr and graph[i][curr]==true and color[i]==color[curr])
        return false;
    }
    
    return true;
}
bool get_ans(bool graph[101][101], int m , int V , int curr, vector<int>&color)
{
    if(curr>=V)
    return true;
    
    for(int i=1;i<=m;i++)
    {
        color[curr]=i;
        if(isSafe(graph,V,curr,color))
        {
            if(get_ans(graph,m,V,curr+1,color)==true)
            return true;
        }
        color[curr]=-1;
    }
    
    return false;
    
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int>color(V,-1);
    return get_ans(graph,m,V,0,color);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends