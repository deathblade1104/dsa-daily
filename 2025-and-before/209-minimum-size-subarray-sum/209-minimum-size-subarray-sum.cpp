class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int curr_sum=0,ans=INT_MAX,release=0;
                
        for(int acquire=0;acquire<nums.size();acquire++)
        {
            curr_sum+=nums[acquire];
            
            while(curr_sum>=target and release<=acquire)
            {
                ans = min(ans, (acquire - release + 1));
                
                curr_sum-=nums[release];
                release++;
            }
        }
        
        if(ans==INT_MAX)
            return 0;
        
        return ans;
        
    }
};