// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int helper(int i,int j,int&n ,string&S1,string&S2,vector<vector<int>>&dp)
    {
        if(i>=n or j>=n)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(S1[i]==S2[j])
        return dp[i][j] = 1 + helper(i+1,j+1,n,S1,S2,dp);
        
        return dp[i][j] = max(helper(i+1,j,n,S1,S2,dp),helper(i,j+1,n,S1,S2,dp));
    }
    
    int longestPalinSubseq(string S1) {
        //code here
        string S2 = S1;
        reverse(S2.begin(),S2.end());
        
        int n = S1.size();
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        return helper(0,0,n,S1,S2,dp);
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends