// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int res;
    vector<long long>merged(vector<long long>&a, vector<long long>&b)
    {
        if(a.size()==0)
        return b;
        if(b.size()==0)
        return a;
        
        if(a[a.size()-1]<=b[0])
        {
            a.insert(a.end(),b.begin(),b.end());
            return a;
        }
        
        vector<long long>ans(a.size()+b.size());
        int i= 0, j = 0, k=0;
        
        while(i<a.size() and j<b.size())
        {
            if(a[i]<=b[j])
            ans[k++]=a[i++];
            
            else 
            {
                res+=(a.size()-i);
                ans[k++]=b[j++];
            }
        }
        
        while(i<a.size())
            ans[k++]=a[i++];
        
        while(j<b.size())
             ans[k++]=b[j++];
             
        return ans;
        
    }
    
    vector<long long> merge_sort(long long start, long long end, long long arr[])
    {
        vector<long long>ans;
        
        if(start>end)
        return ans;
        
        if(start==end)
        {
            ans.push_back(arr[start]);
            return ans;
        }
        
        long long mid = start + ((end-start)/2);
        
        vector<long long>a = merge_sort(start,mid,arr), b = merge_sort(mid+1,end,arr);
        ans = merged(a,b);
        
        return ans;
        
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        res=0;
        vector<long long>ans= merge_sort(0,N-1,arr);
        
        return res;
        
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends