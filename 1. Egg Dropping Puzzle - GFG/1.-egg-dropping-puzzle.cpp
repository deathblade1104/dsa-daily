// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    //  int get_ans(int floors, int eggs,vector<vector<int>>&dp)
    // {
    //     if(floors==0 and eggs>0) return dp[floors][eggs]=0;
    //     else if (floors==1 and eggs>0) return dp[floors][eggs]=1;
    //     else if(eggs==0) return dp[floors][eggs]=INT_MAX/2;    
    //     else if(eggs==1 and floors>0) return dp[floors][eggs]=floors;
        
    //     if(dp[floors][eggs]!=-1) return dp[floors][eggs];
        
    //     int res =INT_MAX;
        
    //     for(int i=1;i<=floors;i++)
    //     {
    //         int curr = max(get_ans(i-1,eggs-1,dp),get_ans(floors-i,eggs,dp));
    //         res=min(res,curr);
    //     }
        
    //     return dp[floors][eggs]= 1 + res;           
    // }
    int eggDrop(int eggs, int floors) 
    {
        // your code here
        int dp[201][201]={-1};
        
        for(int i=0;i<=floors;i++)
        {
            dp[i][0]=INT_MAX;
            dp[i][1]=i;
        }
        
        for(int i=2;i<=eggs;i++)
        {
            dp[0][i]=0;
            dp[1][i]=1;
        }
        
        for(int i=2;i<=eggs;i++)
        {
            for(int j=2;j<=floors;j++)
            {
                dp[j][i] =INT_MAX;
                for(int k=1;k<=j;k++)
                {
                    int temp = 1 + max(dp[k-1][i-1],dp[j-k][i]);
                    dp[j][i]=min(temp,dp[j][i]);
                }
            }
        }  
       
        return dp[floors][eggs];  
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