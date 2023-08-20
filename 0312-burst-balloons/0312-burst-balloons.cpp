class Solution {
public:
        vector<vector<int>> dp;
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> list = {1};
        for (int i = 0; i < n; i++) list.push_back(nums[i]);
        list.push_back(1);
        
        dp.assign(n + 2, vector<int>(n + 2, -1));
        
        return helper_max_coins(1, n, list);
    }
    
    int helper_max_coins(int i, int j, vector<int>& list) {
        if (i > j) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int maxi = INT_MIN;
        
        for (int ind = i; ind <= j; ind++) {
            int costs = list[i - 1] * list[ind] * list[j + 1] 
                          + helper_max_coins(i, ind - 1, list)   // left partition
                          + helper_max_coins(ind + 1, j, list);  // right partition
            maxi = max(maxi, costs);
        }
        return dp[i][j] = maxi;
    }
};