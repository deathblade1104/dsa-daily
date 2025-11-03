// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        // code here
        
        int l=0,h= n-1;
        
        while(l<h)
        {
            if(arr[l]==0)
            l++;
            
            if(arr[h]==1)
            h--;
            
            else if(arr[l]==1 and arr[h]==0)
            {
                swap(arr[l],arr[h]);;
                l++;
                h--;
            }
        }
        
        return;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregate0and1(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends