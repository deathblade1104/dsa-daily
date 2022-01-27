// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    long long get_ans(vector<vector<long long>>&dp, int X, int N, int &M)
    {
        if(!X and !N) return  1;
        
        if(!X or !N) return 0;
        
        if(dp[N][X]!=-1)
        return  dp[N][X];
        
        long long ans=0;
        for(int i=1;i<=M;i++)
        {
            if(X>=i)
            ans+=get_ans(dp,X-i,N-1,M);
        }
        
        dp[N][X]=ans;
        
        return dp[N][X];
        
    }
    long long noOfWays(int M , int N , int X) {
        // code here
        vector<vector<long long>>dp(N+1,vector<long long >(X+1,-1));
        
        return get_ans(dp,X,N,M);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}  // } Driver Code Ends