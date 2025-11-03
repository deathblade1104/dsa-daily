// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
// Function to print the k numbers with most occurrences 

typedef pair<int,int> p;


class Solution
{
    public:
    struct mycomp
    {
        bool operator()(const p&a, const p&b)
        {
            return a.second>b.second;
        }
    };
        
    int kMostFrequent(int arr[], int n, int k) 
    { 
    	// Your code here	
    	unordered_map<int,int>mp;
    	for(int i=0;i<n;i++)
    	mp[arr[i]]++;
    	
    	priority_queue<p,vector<p>,mycomp>pq;
    	
    	for(auto it : mp)
    	{
    	    p var = make_pair(it.first,it.second);
    	    pq.push(var);
    	    
    	    if(pq.size()>k)
    	    pq.pop();
    	}
    	
    	int ans=0;
    	
    	while(pq.size()>0)
    	{
    	    p var = pq.top();
    	    ans+=var.second;
    	    
    	    pq.pop();
    	}
    	
    	return ans;
    	
    	
    	
    	
    	
    	
    } 
};

// { Driver Code Starts.
// Driver program to test above 
int main() 
{
	int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.kMostFrequent(arr, n, k) << endl; 
    }

	return 0; 
} 
  // } Driver Code Ends