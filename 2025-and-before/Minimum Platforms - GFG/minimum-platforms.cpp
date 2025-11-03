// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int count[2361];
    	memset(count,0,sizeof(count));
    	
    	for(int i=0;i<n;i++)
    	{
    	    count[arr[i]]++;
    	    count[dep[i]+1]--;
    	}
    	

    	int ans=count[0];
    	
    	for(int i=1;i<2361;i++)
    	{
    	    count[i]+=count[i-1];
    	    ans=max(ans,count[i]);
    	}
    	
    	return ans;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends