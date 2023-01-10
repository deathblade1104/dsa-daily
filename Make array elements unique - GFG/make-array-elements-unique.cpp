//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        
        sort(arr.begin(),arr.end());
        set<int>st;
        long long ans = 0LL;
        st.insert(arr[0]);
        
        for(int i=1;i<arr.size();i++){
            
            if(st.count(arr[i])){
                int last = *(st.rbegin()) - arr[i] + 1;
                ans+=(1LL * last);
                st.insert(arr[i] + last);
            }
            
            else 
            st.insert(arr[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends