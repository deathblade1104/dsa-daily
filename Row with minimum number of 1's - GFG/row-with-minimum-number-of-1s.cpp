// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRow(int N, int M, vector<vector<int>> A) {
        // code here
        int row_no=0,mini=M;
        
        for(int i=0;i<N;i++)
        {   
            int sum=0;
            for(int j=0;j<M;j++)
            {
                sum+=A[i][j];
            }
            if(sum<mini)
            {
                mini=sum;
                row_no=i+1;
            }
        }
        
        return row_no;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}  // } Driver Code Ends