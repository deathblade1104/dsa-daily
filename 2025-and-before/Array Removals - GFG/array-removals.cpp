//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        //Code here
        
        sort(arr.begin(),arr.end());
        int n = arr.size();
        
        int start=0, ans = 0;
        
        for(int i=0;i<n;i++){
            
            while(start<=i and arr[i] - arr[start]>k)
            start++;
            
            ans = max(ans, i - start +1);
        }
        
        return n - ans;
        
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends