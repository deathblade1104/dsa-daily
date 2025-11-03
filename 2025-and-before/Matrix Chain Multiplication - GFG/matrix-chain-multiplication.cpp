//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int dp[1001][1001];
    int helper(int i,int j, int arr[]){
        
        if(i>=j)
            return 0;
            
        if(i==j-1)
            return arr[i-1] * arr[i] * arr[j];
            
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int ans = INT_MAX;
        
        for(int k=i;k<j;k++){
            int currAns = helper(i,k,arr) + helper(k+1,j,arr) + (arr[i-1] * arr[k] * arr[j]);
            ans = min(ans,currAns);
        }
        
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp,-1,sizeof dp);
        return helper(1,N-1,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends