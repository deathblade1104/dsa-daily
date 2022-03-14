class Solution {
    bool inc(vector<int>&nums)
    {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
                return false;
        }
        
        return true;
    }
    
    bool dec(vector<int>&nums)
    {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                return false;
        }
        
        return true;
    }
public:
    bool isMonotonic(vector<int>& nums) {
        
       if(!inc(nums) and !dec(nums))
           return false;
        
        return true;
        
    }
};