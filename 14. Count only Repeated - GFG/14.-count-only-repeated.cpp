// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find repeated element and its frequency.
    pair<int, int> findRepeating(int *arr, int n){
        //code here
        pair<int,int>p=make_pair(-1,-1);
        int count = n-1 - (arr[n-1] - arr[0]);
        if(count ==0)
        return p;
        
        count+=1;
        int ele=-1,l=0,h=n-1;
        while(l<h)
        {
            int m = l + ((h-l)/2);
            
            if(arr[m]==(arr[0]+m))
            l=m+1;
            
            else
            h=m-1;
        }
        
        ele=arr[l];
        
        p.first=ele;
        p.second=count;
        
        return p;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    Solution obj;
	    pair<int, int> ans = obj.findRepeating(arr,n);
	    
	    cout << ans.first << " " << ans.second << endl;
	    
	}
	
}  // } Driver Code Ends