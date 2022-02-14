// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int get_ans(int arr[], int n, int k)
    {
        int c=0;
        for(int i=0;i<n-2;i++)
        {
            int low=i+1,high=n-1;
            while(low<high)
            {
                if(arr[i]+arr[low]+arr[high]>k)
                high--;
                
                else
                {
                    c+=(high-low);
                    low++;
                }
            }
        }
        
        return c;
    }
    int countTriplets(int arr[], int N, int L, int R) {
        // code here
        sort(arr,arr+N);
        
        return get_ans(arr,N,R) - get_ans(arr,N,L-1);
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}  // } Driver Code Ends