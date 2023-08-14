class Solution {
public:
    int getMax(vector<int>&arr,int i,int j){
        
        int ans = arr[i];
        for(int iter= i+1;iter<=j;iter++){
            ans = max(ans,arr[iter]);
        }
        
        return ans;
    }
    
    
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
        
        for(int k=i;k<i+K && k<N;k++){
            
            int maxEle  = getMax(arr,i,k);
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