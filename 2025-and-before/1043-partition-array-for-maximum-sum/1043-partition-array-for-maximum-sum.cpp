class Solution {
public:
    
    int dp[501]={};
    int K,N;
    int helper(int i,vector<int>&arr){
        
        if(i>=N)
            return 0;
        
        if(dp[i])
            return dp[i];
        
        int mini = 0;
        int maxEle = arr[i];
        for(int k=i;k<i+K && k<N;k++){
            maxEle = max(arr[k],maxEle);
            int curr = maxEle*(k-i+1) + helper(k+1,arr);
            mini = max(mini,curr);
        }
        
        return dp[i] = mini;
        
        
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        K=k;
        N=arr.size();
        return helper(0,arr);
    }
};