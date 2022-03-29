// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int get_ans(int i,int j, int n, int m, string &s1, string &s2,vector<vector<int>>&dp)
    {
        if((i>=n) or (j>=m)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=0;
        
        if(s1[i]==s2[j])
        ans = 1 + get_ans(i+1,j+1,n,m,s1,s2,dp);
        
        int x = get_ans(i+1,j,n,m,s1,s2,dp);
        int y = get_ans(i,j+1,n,m,s1,s2,dp);
        
        return dp[i][j]=ans;
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int x = get_ans(0,0,n,m,S1,S2,dp),ans=-1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            ans=max(ans,dp[i][j]);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends