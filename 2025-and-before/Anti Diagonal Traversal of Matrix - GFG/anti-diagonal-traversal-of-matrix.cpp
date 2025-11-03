// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> mat) 
    {
        // Code her
        vector<int>ans;
        int n=mat.size()-1;
        
        for(int i=0;i<=n;i++)
        {
            int r=0,c=i;
            while(r<=n and c>=0)
            {
                ans.push_back(mat[r][c]);
                r++;
                c--;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            int r=i,c=n;
            while(r<=n and c>=0)
            {
                ans.push_back(mat[r][c]);
                r++;
                c--;

            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends