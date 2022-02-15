// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool dfs(vector<vector<int>>&grid, int r, int c,int &n,int &m)
    {
        if(r<0 or r>=n or c<0 or c>=m or grid[r][c]==0)
        return false;
        
        if(grid[r][c]==2)
        return true;
        
        grid[r][c]=0;
        
        return dfs(grid,r+1,c,n,m) or
               dfs(grid,r-1,c,n,m) or
               dfs(grid,r,c+1,n,m) or
               dfs(grid,r,c-1,n,m);
                
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int sr=-1,sc=-1,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    sr=i;
                    sc=j;
                    break;
                }
            }
            if(sr!=-1 and sc!=-1)
            break;
        }
        
    return dfs(grid,sr,sc,n,m);
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends