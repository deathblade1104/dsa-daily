//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int N, vector<int> A) {
        // code here
        
        int carry = 1;
        for(int i=N-1;i>=0;i--){
            
            A[i] = A[i] + carry;
            
            if(A[i]>=10){
                A[i]=9;
                carry = 1;
            }
            
            else carry=0;
            
            if(!carry)
                return i+1;
            
        }
        
        return -1;
    }
    
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);

        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.solve(N, A) << "\n";
    }
    return 0;
}
    
// } Driver Code Ends