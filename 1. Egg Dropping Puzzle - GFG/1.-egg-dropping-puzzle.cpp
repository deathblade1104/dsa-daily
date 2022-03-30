// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
     int get_ans(int floors, int eggs,vector<vector<int>>&dp)
    {
        if(floors==0 and eggs>0) return dp[floors][eggs]=0;
        else if (floors==1 and eggs>0) return dp[floors][eggs]=1;
        else if(eggs==0) return dp[floors][eggs]=INT_MAX/2;    
        else if(eggs==1 and floors>0) return dp[floors][eggs]=floors;
        
        if(dp[floors][eggs]!=-1) return dp[floors][eggs];
        
        int res =INT_MAX;
        
        for(int i=1;i<=floors;i++)
        {
            int curr = max(get_ans(i-1,eggs-1,dp),get_ans(floors-i,eggs,dp));
            res=min(res,curr);
        }
        
        return dp[floors][eggs]= 1 + res;           
    }
    int eggDrop(int eggs, int floors) 
    {
        // your code here
        vector<vector<int>>dp(floors+1,vector<int>(eggs+1,-1));
        return get_ans(floors,eggs,dp);  
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends