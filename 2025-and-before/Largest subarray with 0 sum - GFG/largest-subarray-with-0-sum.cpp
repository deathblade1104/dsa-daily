// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int ps=0,ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            ps+=A[i];
            
            if(ps==0)
            ans=i+1;
            
            if(mp.count(ps)==1)
            ans=max(ans,(i-mp[ps]));
            
            else
            mp[ps]=i;
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
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends