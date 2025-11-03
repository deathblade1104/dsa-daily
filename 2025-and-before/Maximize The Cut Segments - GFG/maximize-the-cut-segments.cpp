// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
     unordered_map<int,int>mp;
    int getans(int n,int x,int y,int z)
    {
        if(n==0)
        return 0;
        
        if(mp.find(n)!=mp.end())
        return mp[n];
        
        int one=INT_MIN,two=INT_MIN,three=INT_MIN;
        
        if(x<=n)
        one = 1 + getans(n-x,x,y,z);
        
        if(y<=n)
        two = 1 + getans(n-y,x,y,z);
        
        if(z<=n)
        three = 1 + getans(n-z,x,y,z);
        
        mp[n]=max(one,max(two,three));
        
        return mp[n];
    }
    
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
        int ans=getans(n,x,y,z);
        
        if(ans<0)
        return 0;
        
        return ans;
    }

};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends