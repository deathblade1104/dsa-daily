class Solution {
public:
   int dp1[1001][501],dp2[1001][501];
    int longestArithSeqLength(vector<int>& nums) {
        int ans =0,n = nums.size();
        memset(dp1,0,sizeof dp1);
        memset(dp2,0,sizeof dp2);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                
                int diff = nums[i] - nums[j];
                
                if(diff>0){
                    dp1[i][diff] = max(dp1[i][diff], dp1[j][diff] + 1);
                    ans = max(ans,dp1[i][diff]);
                }
                
                else {
                    diff = abs(diff);
                    dp2[i][diff] = max(dp2[i][diff], dp2[j][diff] + 1);
                    ans = max(ans,dp2[i][diff]);
                }
            }
        }
        
        return ans+1;
    }
};