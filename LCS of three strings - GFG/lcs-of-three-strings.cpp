// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int get_ans(int i, int j, int k, string&A, string&B, string&C, int&n1,int&n2,int&n3, vector<vector<vector<int>>>&dp)
{
    
    if(i>=n1 or j>=n2 or k>=n3) return 0;
    
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    
    int ans=0;
    
    if(A[i]==B[j] and B[j]==C[k])
    ans= 1 + get_ans(i+1,j+1,k+1,A,B,C,n1,n2,n3,dp);
    
    else
    {
        int op1,op2,op3,op4,op5,op6;
        op1=op2=op3=op4=op5=op6=0;
        
        op1=get_ans(i+1,j,k,A,B,C,n1,n2,n3,dp);
        op2=get_ans(i+1,j+1,k,A,B,C,n1,n2,n3,dp);
        op3=get_ans(i,j+1,k,A,B,C,n1,n2,n3,dp);
        op4=get_ans(i,j+1,k+1,A,B,C,n1,n2,n3,dp);
        op5=get_ans(i,j,k+1,A,B,C,n1,n2,n3,dp);
        op6=get_ans(i+1,j,k+1,A,B,C,n1,n2,n3,dp);
        
        ans=max({op1,op2,op3,op4,op5,op6});
    }
    
    return dp[i][j][k]=ans;
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    vector<vector<vector<int>>>dp(n1, vector<vector<int>>(n2, vector<int>(n3, -1)));
    
    return get_ans(0,0,0,A,B,C,n1,n2,n3,dp);
}