// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long get_ans(int i,int j, int arr[],vector<vector<long long>>&dp)
    {
        if(i==j)
        return dp[i][j]= arr[i];
        
        else if((i+1)==j)
        return dp[i][j]=max(arr[i],arr[j]);
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        long long op1= arr[i] + min(get_ans(i+2,j,arr,dp) , get_ans(i+1,j-1,arr,dp));
        long long op2= arr[j] + min(get_ans(i,j-2,arr,dp) , get_ans(i+1,j-1,arr,dp));
        
        return dp[i][j] = max(op1,op2);
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        
        vector<vector<long long>>dp(n,vector<long long>(n,-1));
        return get_ans(0,n-1,arr,dp);
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends