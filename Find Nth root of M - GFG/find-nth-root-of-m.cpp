// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, long long  int m)
	{
	    // Code here.
	    
	    long long int low =1, high = floor(m/n) + 1;
	    
	    while(low<=high)
	    {
	        long long int mid = (low  + high)/2;
	        if(pow(mid,n) == m)
	        return mid;
	        
	        else if(pow(mid,n)<m)
	        low = mid+1;
	        
	        else high = mid -1;
	    }
	    
	    return -1;
	   
	    
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends