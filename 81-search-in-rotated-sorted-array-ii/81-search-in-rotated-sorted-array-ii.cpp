class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, h = nums.size()-1;
        
        while(l<=h)
        {
            int mid = h - ((h-l)/2);
            
            if(nums[mid]==target)
                return true;
            
            
            else if(nums[l]<nums[mid])
            {
                if(nums[mid]>target and target>=nums[l])
                    h=mid-1;
                else
                    l=mid+1;                
            }
            
            else if(nums[h]>nums[mid])
            {
                
                if(nums[mid]<target and target<=nums[h])
                    l=mid+1;
                
                else h=mid-1;
                
            }
            
            else
            {
                if(nums[l]==nums[mid])
                l++;
            
                if(nums[h]==nums[mid])
                h--;
            }
        }
        
        return false;
    }
};