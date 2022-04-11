// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int getans(int arr[],int curr,int curr_sum,int sum,int sz,vector<vector<int>>&dp)
    {
        if(curr_sum==sum)
        return 0;
        
        if(curr>=sz)
        {
            return abs(curr_sum - sum);
        }
        
        if(dp[curr][sum]!=-1)
        return dp[curr][sum];
        
        int consider =0;
        consider=getans(arr,curr+1,curr_sum+arr[curr],sum-arr[curr],sz,dp);
        
        int dont_consider= getans(arr,curr+1,curr_sum,sum,sz,dp);
        
        dp[curr][sum]=min(consider,dont_consider);
        
        return dp[curr][sum];
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    if(n==1)
	    return arr[0];
	    
	    int sum =0;
	    
	    for(int i=0;i<n;i++)
	    sum+= arr[i];
	    
	    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
	    
	    int ans=getans(arr,0,0,sum,n,dp);
	    
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
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends