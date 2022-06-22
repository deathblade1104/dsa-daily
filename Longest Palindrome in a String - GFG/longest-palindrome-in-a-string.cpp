// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
  bool helper(string &S,int l, int r, vector<vector<int>>&dp)
{
    if(l == r)
    return dp[l][r]=true;
    
    if(l + 1 == r)
    {
        if(S[l] == S[r])
        return dp[l][r] = true;
        
        return dp[l][r] = false;
    }
    
    if(dp[l][r]!=-1)
    return dp[l][r];
    
    bool ans = false;
    if(S[l] == S[r])
    ans = true and helper(S,l+1,r-1,dp);
    
    bool call1 = helper(S,l+1,r,dp) , call2 =helper(S,l,r-1,dp); 
    
    return dp[l][r] = ans;
}

    string longestPalin (string S) {
        // code here
    int n = S.size(),start=-1,end=-1,res=1;
    
    vector<vector<int>>dp(n,vector<int>(n,-1));
    bool temp = helper(S,0,n-1,dp);
    
    string ans = "";
    ans+=S[0];
                
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(dp[i][j]==1 and j - i + 1 > res)
            {
                end = j;
                start = i;
                res = j - i + 1;
            }
           
        }
    }
    
    if(end!= -1 and start!=-1)
        ans= S.substr(start,res);
    
    
    return ans;
    
    
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends