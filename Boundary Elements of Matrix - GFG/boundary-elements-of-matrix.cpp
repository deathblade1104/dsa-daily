// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    vector<int> BoundaryElements(vector<vector<int>>&mat){
        // Code here
        int r=mat.size(),c=mat.size();
        
        vector<int>ans;
        
        for(int i=0;i<c;i++)
        ans.push_back(mat[0][i]);
        
        if(r>2)
        {
            for(int i=1;i<r-1;i++)
            {
                ans.push_back(mat[i][0]);
                
                if(c>1)
                ans.push_back(mat[i][c-1]);
            }
        }
        
        if(r>1)
        {
            for(int i=0;i<c;i++)
            ans.push_back(mat[r-1][i]);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		Solution obj;
		vector<int>ans = obj.BoundaryElements(matrix);
		for(auto i: ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends