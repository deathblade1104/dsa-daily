// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int search(int A[], int l, int h, int k){
    //complete the function here
    while(l<=h)
    {
        int mid = l + ((h-l)/2);
        
        if(A[mid]==k)
        return mid;
        
        if(A[mid]>=A[l]) //which part is sorted
        {
            if(k>=A[l] and k<=A[mid])
            h=mid-1;
            
            else
            l=mid+1;
        }
        
        else
        {
            if(k>=A[mid+1] and k<=A[h])
            l=mid+1;
            
            else
            h=mid-1;
        }
        
    }
    
    return -1;
        
        
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends