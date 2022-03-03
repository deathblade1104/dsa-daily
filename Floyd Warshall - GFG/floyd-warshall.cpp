// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&costs){
	    // Code here
	    int v= costs.size();

	    for(int i=0;i<v;i++)
	    {
	        for(int j=0;j<v;j++)
            {
               if(costs[i][j]==-1)
                costs[i][j]=INT_MAX/2;
            }
	    }
	    
	    for(int inter=0;inter<v;inter++)
	    {
	        for(int src=0;src<v;src++)
	        {
	            for(int des=0;des<v;des++)
	            {
	                costs[src][des]= min(costs[src][des], costs[src][inter] + costs[inter][des]);
	            }
	        }
	    }
	    
	    for(int i=0;i<v;i++)
	    {
	        for(int j=0;j<v;j++)
	            if(costs[i][j]==INT_MAX/2)
	             costs[i][j]=-1;
	    }
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends