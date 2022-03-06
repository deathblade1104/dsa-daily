// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

 // } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
    
    bool isGood(long long int c , long long int x)
    {
        return (c*c<=x);
    }
    
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here  
        if(x==1)
        return 1;
        
        long long int l=1,h=INT_MAX,ans=1;
        while(l<=h)
        {
            long long int mid =  l + ((h-l)/2);
            
            if(isGood(mid,x))
            {
                ans=mid;
                l=mid+1;
            }
            
            else
            h=mid-1;
        }
        
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends