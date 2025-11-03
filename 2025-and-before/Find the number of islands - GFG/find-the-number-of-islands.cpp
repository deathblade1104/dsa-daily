// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    // void dfs(vector<vector<char>>&grid, int r, int c, int &n , int &m)
    // {
    //     if(r<0 or r>=n or c<0 or c>=m or grid[r][c]=='0')
    //     return;
        
    //     grid[r][c]='0';
        
    //     dfs(grid,r+1,c,n,m);
    //     dfs(grid,r-1,c,n,m);
    //     dfs(grid,r,c+1,n,m);
    //     dfs(grid,r,c-1,n,m);
    //     dfs(grid,r+1,c+1,n,m);
    //     dfs(grid,r+1,c-1,n,m);
    //     dfs(grid,r-1,c+1,n,m);
    //     dfs(grid,r-1,c-1,n,m);
    //     return;
        
    // }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        // int count=0;
        // int n=grid.size(),m=grid[0].size();
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(grid[i][j]=='1')
        //         {
        //             count++;
        //             dfs(grid,i,j,n,m);
        //         }
        //     }
        // }
        
        // return count;
        
        
        int count=0, n=grid.size(),m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    
                    while(q.size()>0)
                    {
                        pair<int,int>p=q.front();
                        q.pop();
                        
                        int r=p.first,c=p.second;
                        
                        if(r<0 or r>=n or c<0 or c>=m or grid[r][c]=='0')
                        continue;
                        
                        grid[r][c]='0';
                        
                        q.push({r+1,c});
                        q.push({r-1,c});
                        q.push({r,c+1});
                        q.push({r,c-1});
                        q.push({r+1,c+1});
                        q.push({r+1,c-1});
                        q.push({r-1,c+1});
                        q.push({r-1,c-1});
                    }
                }
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends