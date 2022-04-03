// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
int maxSumBS(int arr[] , int n );

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
		
		cout<<maxSumBS(a,n)<<endl;
		
	}
}// } Driver Code Ends


vector<int>maxSumIS(int nums[], int n)  
{
    vector<int>dp(n);
    for(int i=0;i<n;i++)
    dp[i]=nums[i];
    
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(nums[j]<nums[i])
            dp[i]=max(dp[i],nums[i]+dp[j]);
        }
    }
    
    return dp;
}

vector<int>maxSumDS(int nums[], int n)  
{
    vector<int>dp(n);
    for(int i=0;i<n;i++)
    dp[i]=nums[i];
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            if(nums[j]<nums[i])
            dp[i]=max(dp[i],nums[i]+dp[j]);
        }
    }
    return dp;
}

int maxSumBS(int arr[] , int n )
{
    vector<int>inc,dec;
    inc=maxSumIS(arr,n);
    dec=maxSumDS(arr,n);
    
    
    int ans=-1;
    for(int i=0;i<n;i++)
    ans=max(ans,(inc[i]+dec[i]-arr[i]));
    
    
    return ans;
    
}
