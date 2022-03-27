class Solution {
public:
    int dp[300][5001];
    int getans(vector<int>arr,int curr,int amt,int n)
    {
        if(amt ==0)
            return 1;
        
        if(curr>=n)
            return 0;
        
        if(dp[curr][amt]!=-1)
            return dp[curr][amt];
        
        int same=0;
        
        if(arr[curr]<=amt)
            same=getans(arr,curr,amt-arr[curr],n);
        
        int not_same=getans(arr,curr+1,amt,n);
        
        dp[curr][amt]=same + not_same;
        
        return dp[curr][amt];       
        
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        
        memset(dp,-1,sizeof(dp));
        
        
        int ans=getans(coins,0,amount,n);
    
        return ans;
        
    }
};