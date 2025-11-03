class Solution {
public:
    static int dp[(int)(1e5 + 1)];
    int n;
    
    int helper(int curr,vector<vector<int>>&nums){
        
        if(curr>=n)
            return 0;
                
        if(dp[curr]!=-1)
            return dp[curr];
        
        int op1 = helper(curr+1,nums);
        
        int low = curr+1,high = n-1,ans = n;
        
        while(low<=high){
    
            int mid = low + ((high - low)/2);
            
            if(nums[mid][0]>nums[curr][1]){
                ans = mid;
                high = mid -1;
            }
            
            else low = mid + 1;
        }
        
        int op2 = helper(ans,nums) + nums[curr][2];
      
        return dp[curr] = max(op1,op2);
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {

        sort(offers.begin(),offers.end());
        memset(dp,-1,sizeof dp);
        this->n = offers.size();
    
        
        return helper(0,offers);
    }
};

int Solution::dp[(int)1e5 +1];