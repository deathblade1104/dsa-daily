// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int overlap(vector<pair<int,int>>intervals, int n){
        //Write your code heresort(intervals.begin(),intervals.end());
       
       vector<int>arr,dep;
       for(auto p: intervals)
       {
           arr.push_back(p.first);
           dep.push_back(p.second);
       }
       
       sort(arr.begin(),arr.end());
       sort(dep.begin(),dep.end());
       
       int plat=1,ans=1,prev=0,curr=1;
        
        while(curr<n)
        {
            if(arr[curr]<=dep[prev])
            {
                plat++;
                curr++;
            }
            
            else
            {
                prev++;
                plat--;
            }
            
            ans=max(ans,plat);
        }
        
        return ans;
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<pair<int,int>>intervals;
	    for(int i = 0; i < n; i++){
	        int a, b;
	        cin >> a >> b;
	        intervals.push_back({a, b});
	    }
	    Solution ob;
	    int ans = ob.overlap(intervals, n);
	    cout << ans <<endl;
	}
	return 0;
}
  // } Driver Code Ends