//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        if(grid[source.first][source.second]==0 or grid[destination.first][destination.second]==0)
            return -1;
            
        int dir[5] = {1,0,-1,0,1};
        
        queue<array<int,2>>q;
        q.push({source.first,source.second});
        
        int n = grid.size(), m = grid[0].size(),steps=0;
        
        
        while(q.size()){
            
            int sz = q.size();
            while(sz --){
                
                 auto curr = q.front();
                q.pop();
                
                int r = curr[0], c =curr[1];
                
                if(r==destination.first and c==destination.second)
                    return steps;
                    
                for(int i=1;i<=4;i++){
                    
                    int nr = r + dir[i-1], nc = c + dir[i];
                    
                    if(nr<0 or nc<0 or nr>=n or nc>=m or grid[nr][nc]!=1)
                        continue;
                        
                    grid[nr][nc]=0;
                    q.push({nr,nc});
                }
            }
            steps++;
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends