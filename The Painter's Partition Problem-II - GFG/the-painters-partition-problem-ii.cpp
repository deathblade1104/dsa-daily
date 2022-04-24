// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  private :
  bool isPossible(int arr[], int &n ,int&k , long long &mid)
  {
      int p=1;
      long long cs=0;
      
      for(int i=0;i<n;i++)
      {
          long long x=arr[i];
          
          if(x>mid)
          return false;
          
          if(x + cs  <=mid)
            cs+=x;
          
          else
          {
              p++;
              cs=x;
              
              
              if(p>k)
              return false;
          }
      }
      
      return true;
  }
  public:
    long long minTime(int arr[], int n, int k)
    {
        long long sum=0;
        for(int i=0;i<n;i++)
        sum+=arr[i];
    
        
        long long ans=-1,low=0,high=sum;
        while(low<=high)
        {
            long long mid = low + ((high-low)/2);
            
            if(isPossible(arr,n,k,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low = mid +1;
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
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends