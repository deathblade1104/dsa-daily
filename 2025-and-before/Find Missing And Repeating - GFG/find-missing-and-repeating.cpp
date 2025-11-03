// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        
        int missing, repeating;
        for(int i=0;i<n;i++)
        {
            int ele = abs(arr[i]);
            
            if(arr[ele-1]<0)
                repeating = ele;
                
            else
            arr[ele-1] = -arr[ele-1];
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                missing = i+1;
                break;
            }
        }
        
        int* res = new int(2);
        res[0]= repeating;
        res[1] = missing;
        
        return res;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends