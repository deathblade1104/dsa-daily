class Solution {
public:
    
    int dp[102][102] = {};
    
    int helper(int i,int j,vector<int>&arr){
        
        //base case
        if(i>j)
            return 0;
        
        if(dp[i][j])
            return dp[i][j];
        
        int mini =INT_MAX;
        
        for(int k=i;k<=j;k++){
            int curr = arr[j+1] - arr[i-1] + helper(i,k-1,arr) +helper(k+1,j,arr);
            mini = min(mini,curr);
        }
        
        return dp[i][j] = mini;
       
        
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int sz = cuts.size();
        
        return helper(1,sz-2,cuts);
        
    }
};