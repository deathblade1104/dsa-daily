// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int m=1000000007;
	int getans(int arr[],int curr,int n, int target,vector<vector<int>>&dp)
	{
	    if(curr==n)
	    {
	        if(target==0)
	        return 1;
	        
	        return 0;
	    }
	    
	    if(dp[curr][target]!=-1)
	    return dp[curr][target];
	    
	    int consider=0;
	    
	    if(arr[curr]<=target)
	    consider=(getans(arr,curr+1,n,target-arr[curr],dp)%m);
	    
	    int not_consider= (getans(arr,curr+1,n,target,dp)%m);
	    
	    dp[curr][target] = (consider + not_consider)%m;
	    
	    return dp[curr][target];
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        
        int ans= getans(arr,0,n,sum,dp);
        
        return ans;
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends