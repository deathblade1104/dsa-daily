// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    void rotate(vector<vector<int> >& mat) {
        // Code here
        int r=mat.size();
        int c=mat[0].size();
        
        for(int i=0;i<r;i++)
        {
            int l=0,h=c-1;
            while(l<h)
            {
                swap(mat[i][l],mat[i][h]);
                l++;
                h--;
            }
        }
        
        int l=0,h=r-1;
        while(l<h)
        {
            vector<int>temp=mat[l];
            mat[l]=mat[h];
            mat[h]=temp;
            
            l++;
            h--;
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
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.rotate(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends