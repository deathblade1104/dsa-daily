// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>&mat) 
    {
        // Code here
    priority_queue<array<int,3>,vector<array<int,3>>, greater<array<int,3>>>pq;
	pq.push({mat[0][0],0,0});
	
	int n = mat.size() , m = mat[0].size();
	array<int,5>dir = {1,0,-1,0,1};
	
	while(pq.size()>0)
	{
		auto p = pq.top();
		pq.pop();
		
		
		if(p[1]==n-1 and p[2]==m-1)
			return p[0];
	
		for(int i = 1;i<=4;i++)
		{
			int x = p[1]+dir[i-1],y=p[2]+dir[i];
			if(x>=0 and x<n and y>=0 and y<m and mat[x][y]!=1001)
			{
				int cost = p[0] + mat[x][y];
				mat[x][y]=1001;
				
				pq.push({cost,x,y});
			}
		}
	}
		return -1;
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