//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int dp[100001];
    long long countPairs(int n, int arr[], int k) {
        // code here
        
        memset(dp,0,sizeof dp);
        long long ans = 0LL;
        for(int i=0;i<n;i++){
            
            int rem = arr[i]%k;
            
            ans+=dp[rem];
            dp[rem]++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends