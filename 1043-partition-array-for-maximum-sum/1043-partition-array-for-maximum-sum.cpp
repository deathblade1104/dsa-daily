class Solution {
public:
    
    int dp[501][501]={};
    int K,N;
    int helper(int i,int j, vector<int>&arr){
        
        if(i>j)
            return 0;
        
        if(i==j)
            return arr[i];
        
        if(dp[i][j])
            return dp[i][j];
        
        int mini = 0;
        int maxEle = arr[i];
        for(int k=i;k<i+K && k<N;k++){
            maxEle = max(arr[k],maxEle);
            int curr = maxEle*(k-i+1) + helper(k+1,j,arr);
            mini = max(mini,curr);
        }
        
        return dp[i][j] = mini;
        
        
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        K=k;
        N=arr.size();
        return helper(0,N-1,arr);
    }
};