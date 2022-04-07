class Solution {
public:
    int get_ans(int curr, vector<int>&arr, vector<int>&dp)
    {
        if(curr<=2)
            return dp[curr]=curr;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        int ans = curr;
        for(int i=1;i<arr.size();i++)
        {
            int temp=INT_MAX;
            if(arr[i]<=curr)
                temp = 1 + get_ans(curr-arr[i],arr,dp);
            
            ans=min(temp,ans);
            
            if(arr[i]>curr)
                break;
        }
        
        return dp[curr]=ans;
    }
    
    
    int numSquares(int n) {
        vector<int>arr;
        
        for(int i=1;i*i<=n;i++)
            arr.push_back(i*i);
        
        vector<int>dp(n+1,-1);
        
        return get_ans(n,arr,dp);
    }
};