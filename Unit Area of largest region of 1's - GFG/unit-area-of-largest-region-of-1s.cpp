// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int area=0,n=grid.size(),m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int curr=0;
                    
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    
                    while(q.size()>0)
                    {
                        pair<int,int>p=q.front();
                        q.pop();
                        
                        int r=p.first,c=p.second;
                        
                        if(r<0 or r>=n or c<0 or c>=m or grid[r][c]==0)
                        continue;
                        
                        grid[r][c]=0;
                        curr++;
                        
                        q.push({r+1,c});
                        q.push({r-1,c});
                        q.push({r,c+1});
                        q.push({r,c-1});
                        q.push({r+1,c+1});
                        q.push({r+1,c-1});
                        q.push({r-1,c+1});
                        q.push({r-1,c-1});
                        
                    }
                    
                    area=max(area,curr);
                }
            }
        }
        
        return area;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends