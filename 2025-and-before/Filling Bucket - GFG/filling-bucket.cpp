//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long dp[100001];
    long long mod = 1e8; 
    long long helper(int curr,int&N){
        
        if(curr>N)
            return 0LL;
        if(curr == N)
            return 1LL;
            
        if(dp[curr]!=-1)
            return dp[curr];
            
        long long op1=0LL, op2=0LL;
        
        op1+=helper(curr+1,N)%mod;
        op2+=helper(curr+2,N)%mod;
        
        
        return dp[curr] = (op1 + op2)%mod;
    }
    int fillingBucket(int N) {
        // code here
        
        memset(dp,-1*1LL,sizeof dp);
        long long ans = helper(0,N)%mod;
        
        return (int)ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends