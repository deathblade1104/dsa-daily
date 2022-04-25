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
       
        int count[10000];
    	memset(count,0,sizeof(count));
    	int sz=0;
    	for(auto p : intervals)
    	{
    	    count[p.first]++;
    	    count[p.second+1]--;
    	    sz=max({sz,p.first,p.second});
    	}
    	
    	int ans=count[0];
    	
    	for(int i=1;i<=sz;i++)
    	{
    	    count[i]+=count[i-1];
    	    ans=max(ans,count[i]);
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