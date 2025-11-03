class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i : nums)
        {
            int idx = abs(i);
            
            if(nums[idx]<0)
                return idx;
            
            nums[idx]*=-1;
        }
        
        return -1;
        
        
    }
};