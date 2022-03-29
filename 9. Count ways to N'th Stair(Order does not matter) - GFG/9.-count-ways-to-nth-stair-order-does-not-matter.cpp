// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long get_ans(int amt,int curr, vector<int>&coins, vector<vector<long long>>&dp)
    {
        if(amt<0 or curr>=coins.size())
            return 0;
        
        if(amt==0)
            return dp[0][curr]=1;
       
        if(dp[amt][curr]!=-1)
            return dp[amt][curr];
        
        long long op1=0,op2=0;
        
        if(coins[curr]<=amt)
            op1 = get_ans(amt-coins[curr],curr,coins,dp);
        
        op2= get_ans(amt,curr+1,coins,dp);
        
        return dp[amt][curr] = op1 + op2;
    }
    long long countWays(int m)
    {
        vector<vector<long long>>dp(m+1,vector<long long>(2,-1));
        vector<int>coins={1,2};
        
        return get_ans(m,0,coins,dp);
        // your code here
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  // } Driver Code Ends