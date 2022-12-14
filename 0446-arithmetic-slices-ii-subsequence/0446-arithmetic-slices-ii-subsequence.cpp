class Solution {
public:
    vector<unordered_map<long long,int>>dp;    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size(), ans = 0;
        dp.clear();
        dp.resize(n);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long long diff = 1LL *nums[i] - 1LL*nums[j];
                
                if(diff <= INT_MIN or diff>=INT_MAX)
                    continue;
                
                if(dp[j].count(diff) == 0)
                    dp[i][diff]++;
                
                else dp[i][diff] += dp[j][diff] + 1;
                
                ans+=dp[j][diff];
            }
        }
        
        return ans;
    }
};