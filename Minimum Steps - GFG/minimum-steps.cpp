// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    int get_ans(int curr, int tar, vector<int>&v, vector<vector<int>>&dp)
    {
       if(tar==0)
        return 0;

       
       if(curr<0)
       return 1000000;
       
       if(dp[curr][tar]!=-1)
       return dp[curr][tar];
       
       int cons=1000000,dont=1000000;
       
       if(tar-v[curr]>=0)
       cons = 1 + get_ans(curr,tar-v[curr],v,dp);
       
       
       dont = get_ans(curr-1,tar,v,dp);
       
       dp[curr][tar]=min(cons,dont);
       
       return dp[curr][tar];
       
    }
    int moves(int n, int p, int q)
    {
        // Your code goes here
        vector<int>v;
        v.push_back(1);
        
        if(p>1)
        for(int i=p;i<=n;i=i*p)
        v.push_back(i);
        
        if(q>1)
        for(int i=q;i<=n;i=i*q)
        v.push_back(i);
        
        sort(v.begin(),v.end());

        vector<vector<int>>dp(v.size(),vector<int>(n+1,-1));

        int ans = get_ans(v.size()-1,n,v,dp);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int n,p,q,t;
    cin>>t;
    while(t--){
        cin>>n>>p>>q;
        Solution ob;
        cout<<ob.moves(n, p, q)<<endl;
    }
}
  // } Driver Code Ends