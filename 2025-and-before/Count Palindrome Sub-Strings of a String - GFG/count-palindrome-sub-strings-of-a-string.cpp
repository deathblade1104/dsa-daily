// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}

// } Driver Code Ends


bool helper(char S[],int l, int r, vector<vector<int>>&dp)
{
    if(l == r)
    return dp[l][r]=1;
    
    if(l + 1 == r)
    {
        if(S[l] == S[r])
        return dp[l][r] = 1;
        
        return dp[l][r] = 0;
    }
    
    if(dp[l][r]!=-1)
    return dp[l][r];
    
    bool ans = false;
    if(S[l] == S[r])
    ans = true and helper(S,l+1,r-1,dp);
    
    bool call1 = helper(S,l+1,r,dp) , call2 =helper(S,l,r-1,dp); 
    
    return dp[l][r] = ans;
}

int CountPS(char S[], int n)
{
    //code here
    vector<vector<int>>dp(n,vector<int>(n,-1));
    bool temp = helper(S,0,n-1,dp);
    
    int ans=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        if(dp[i][j])
        ans++;
    }
    
    return ans;
}