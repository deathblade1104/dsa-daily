class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0], curr=nums[0];
        
        for(int j=1;j<nums.size();j++)
        {
            int i = nums[j];
            curr =  max(i, curr+i);
            ans = max(curr, ans);
        }
        
        return ans;
        
    }
};