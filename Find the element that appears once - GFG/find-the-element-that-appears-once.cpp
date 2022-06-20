// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int arr[], int n){
	    //code
	    
        if(n==1)
        return arr[0];
        
        if(arr[n-1]!=arr[n-2])
            return arr[n-1];
        
        if(arr[0]!=arr[1])
            return arr[0];
        
        int l=1,r=n-2;
        while(l<=r){
            
            int mid=l+((r-l)/2);
            if(arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1])
                return arr[mid];
            
            else if((mid%2==0 && arr[mid]==arr[mid-1])
            or (mid%2==1 && arr[mid]==arr[mid+1]))
                r=mid-1;
            
            else
                l=mid+1;
            
        }
        return 0;
	}
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}
  // } Driver Code Ends