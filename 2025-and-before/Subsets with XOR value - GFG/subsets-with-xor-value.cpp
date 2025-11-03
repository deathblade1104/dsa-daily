// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
    
    int get_ans(vector<int>&arr, int &N, int &K ,int curr,int val,vector<vector<int>>&dp)
    {
        if(curr>=N)
        {
            if(val==K)
            return 1;
            
            return 0;
        }
        
        if(dp[curr][val]!=-1)
        return dp[curr][val];
        
        int cons=get_ans(arr,N,K,curr+1,val^arr[curr],dp);
        
        int dont=get_ans(arr,N,K,curr+1,val,dp);
        
        dp[curr][val]=cons + dont;
        
        return dp[curr][val];
        
        
    }
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        vector<vector<int>>dp(N,vector<int>(10001,-1));
        return get_ans(arr,N,K,0,0,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends