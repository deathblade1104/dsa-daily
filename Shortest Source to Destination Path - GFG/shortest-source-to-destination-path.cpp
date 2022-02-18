// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0 || A[X][Y]==0)
            return -1;
        
        queue<pair<int,int>>q;
        q.push({0,0});
        
        int ans=0;
        while(q.size()>0)
        {
           int sz=q.size();
           for(int i=0;i<sz;i++)
           {
               pair<int,int>p=q.front();
               q.pop();
               
               int r=p.first, c=p.second;
               
               if(r==X and c==Y)
               return ans;
               
               if(r<0 or r>=N or c<0 or c>=M or A[r][c]==0)
               continue;
               
               A[r][c]=0;
               
               q.push({r+1,c});
               q.push({r-1,c});
               q.push({r,c+1});
               q.push({r,c-1});
           }
           ans++;
        }
        
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends