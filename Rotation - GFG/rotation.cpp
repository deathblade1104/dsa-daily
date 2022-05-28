// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

    int find_min(int arr[], int n )
    {
        if(arr[0]<arr[n-1])
        return 0;
        
        int x = arr[0], low = 0, high = n-1,ans;
        
        while(low<=high)
        {
            int mid = low + ((high - low)/2);
            
            if(arr[mid]<arr[0])
            {
                ans = mid;
                high = mid - 1;
            }
            
            
            else
            low = mid + 1;
        }
        
        return ans;
    }
	int findKRotation(int arr[], int n) {
	    // code here
	    
	    if(n==1)
	    return 0;
	    
	    return find_min(arr,n);
	    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends