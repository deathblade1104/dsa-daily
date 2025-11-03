// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int get_ans(int r, int c, int M, int N, vector<vector<int>>&grid, vector<vector<int>>&dp)
	{
	    if(r>=M || c>=N )
        return -1000001; 
        
        if(r==M-1 && c==N-1)
        {
            if(grid[r][c]<0) return grid[r][c];
            else return 0;
        }
        
        if(dp[r][c]!=1)
        return dp[r][c];
        
        int op1=grid[r][c],op2=grid[r][c];
        op1+=get_ans(r+1,c,M,N,grid,dp);
        op2+=get_ans(r,c+1,M,N,grid,dp);
        
        if(op1>=0)op1=0;
        if(op2>=0)op2=0;
        
        dp[r][c]=max(op1,op2);
	}
	int minPoints(vector<vector<int>> points, int M, int N) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M, vector<int>(N,1));
	    return abs(get_ans(0,0,M,N,points,dp))+1;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(a, m, n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends