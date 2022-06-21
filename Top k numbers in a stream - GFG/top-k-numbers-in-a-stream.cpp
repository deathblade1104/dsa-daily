// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    struct mycomp
    {
        bool operator()(const array<int,2>&a, const array<int,2>&b)
        {
            if(a[1]!=b[1])
            return a[1]>b[1];
            
            return a[0]<b[0];
        }
    };
    unordered_map<int,int>mp;
    priority_queue<array<int,2>,vector<array<int,2>>,mycomp>pq;
    
    void insert_pq(int k)
    {
        for(auto&it : mp)
        {
            pq.push({it.first,it.second});
            
            if(pq.size()>k)
            pq.pop();
        }
    }
    
    vector<int>empty_pq()
    {
        vector<int>temp;
        
        while(pq.size()>0)
        {
            temp.push_back(pq.top()[0]);
            pq.pop();
        }
        
        reverse(temp.begin(),temp.end());
        return temp;
    }
    
    vector<int> kTop(int a[], int n, int k) 
    { 
        //code here.
       
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
            insert_pq(k);
            vector<int>temp = empty_pq();
            
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    long long k;
	    cin >> n;
	    cin >> k;
	    int a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	    }
	        Solution ob;
	        vector<int> ans;
	        ans=ob.kTop(a,n,k);
	        for(int i=0;i<ans.size();i++)
	        {
	        cout<<ans[i];
	        cout<<" ";
	        }
	        cout<<'\n';
	    }
	return 0;
}
  // } Driver Code Ends