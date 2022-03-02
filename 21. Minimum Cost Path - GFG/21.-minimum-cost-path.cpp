// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public :
    bool isValid(int i,int j,int n)
	{
	    if(i>=n || i<0 || j<0 || j>=n)
	        return false;
	   return true;
	}
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n=grid.size();
        vector<vector<int>> v(n,vector<int> (n,INT_MAX));
        v[0][0]=grid[0][0];

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        pq.push({v[0][0],{0,0}});
        while(!pq.empty())
        {
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            if(isValid(i,j-1,n))
            {
                if(v[i][j-1] > (v[i][j] + grid[i][j-1])){
                v[i][j-1] = min(v[i][j-1],v[i][j] + grid[i][j-1]);
                pq.push({v[i][j-1],{i,j-1}});
                }
            }
            if(isValid(i,j+1,n))
            {
                if(v[i][j+1] > (v[i][j] + grid[i][j+1]) ){
                v[i][j+1] = min(v[i][j+1],v[i][j] + grid[i][j+1]);
                pq.push({v[i][j+1],{i,j+1}});
                }
            }
            if(isValid(i-1,j,n))
            {
                if(v[i-1][j] > (v[i][j] + grid[i-1][j]) ){
                v[i-1][j] = min(v[i-1][j],v[i][j] + grid[i-1][j]);
                pq.push({v[i-1][j],{i-1,j}});
                }
            }
            if(isValid(i+1,j,n))
            {
                if(v[i+1][j] > (v[i][j] + grid[i+1][j]) ){
                v[i+1][j] = min(v[i+1][j],v[i][j] + grid[i+1][j]);
                pq.push({v[i+1][j],{i+1,j}});
                }
            }
           pq.pop(); 
        }
        return v[n-1][n-1];
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends