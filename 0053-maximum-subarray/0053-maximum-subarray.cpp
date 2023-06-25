class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int curr,res;
        curr = res = nums[0];
        
        for(int i=1;i<nums.size();i++){
            
            curr = max(nums[i],nums[i]+curr);
            res = max(res,curr);
        }
        
        return res;
        
    }
};