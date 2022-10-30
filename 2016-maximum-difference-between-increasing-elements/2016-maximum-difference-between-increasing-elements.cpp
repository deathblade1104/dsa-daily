class Solution {
public:
    int maximumDifference(vector<int>& nums) {
       
        int ans = INT_MIN,prev = nums[0];
        
        for(int i=1;i<nums.size();i++){
            
            ans = max(ans,nums[i] - prev);
            prev = min(nums[i],prev);
        }
        
        
        return (ans<=0)? -1 : ans;
    }
};