class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            int it = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
            
            if(it == ans.size())
                ans.push_back(nums[i]);
            
            else
                ans[it] = nums[i];
            
            if(ans.size()>=3)
                return true;
        }
        
        return false;
        
    }
};