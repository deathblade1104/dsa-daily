class Solution {
public:
    int dp[303][303];
    
    int helper(int i, int j, vector<int>& list) {
        if (i > j) 
            return 0;
        
        if (dp[i][j] != -1) 
            return dp[i][j];
        
        int maxi = 0;
        
        for (int ind = i; ind <= j; ind++) {
            int costs = list[i - 1] * list[ind] * list[j + 1] 
                          + helper(i, ind - 1, list)   // left partition
                          + helper(ind + 1, j, list);  // right partition
            
            maxi = max(maxi, costs);
        }
        
        return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        memset(dp,-1,sizeof dp);
        
        return helper(1, n, nums);
    }
    
    
};