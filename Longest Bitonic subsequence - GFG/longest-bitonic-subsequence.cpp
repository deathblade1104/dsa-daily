// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	vector<int>LDS(int n , vector<int>&nums)
	{
	   vector<int>dp(n,1);
       for(int i=n-2;i>=0;i--)
       {
           for(int j=i+1;j<n;j++)
           {
               if(nums[j]<nums[i])
               dp[i]=max(dp[i],dp[j]+1);
           }
       }
       return dp;
	}
	
	vector<int>LIS(int n , vector<int>&nums)
	{
	   vector<int>dp(n,1);
       for(int i=1;i<n;i++)
       {
           for(int j=i-1;j>=0;j--)
           {
               if(nums[j]<nums[i])
               dp[i]=max(dp[i],dp[j]+1);
           }
       }
       
       return dp;
	}
	
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    vector<int>inc,dec;
	    inc=LIS(n,nums);
	    dec=LDS(n,nums);
	    
	    int ans=1;
	    
	    for(int i=0;i<n;i++)
	    ans= max (ans,(inc[i]+dec[i]-1));
	    
	    return ans;
	    

	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends