class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans =0,n = nums.size();
        unordered_map<int,int>dp[n];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                
                int diff = nums[i] - nums[j];
                
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                ans = max(ans,dp[i][diff]);
            }
        }
        
        return ans+1;
    }
};