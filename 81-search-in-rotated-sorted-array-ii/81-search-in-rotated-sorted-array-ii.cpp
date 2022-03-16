class Solution {
public:
    bool search(vector<int>& nums, int target) {
                  
        int l=0,h=nums.size()-1;
        
        
        while(l<=h)
        {
            int mid = l + ((h-l)/2);
            
            if(nums[mid]==target)
                return true;
            
            if(nums[l]==nums[mid] and nums[h]==nums[mid])
            ++l,--h;
            
            else if(nums[l]<=nums[mid])
            {
                if(nums[l]<=target and target<nums[mid])
                    h=mid-1;
                
                else
                    l=mid+1;
            }
            
            else
            {
                if(target<=nums[h] and target>nums[mid])
                    l=mid+1;
                
                else
                    h=mid-1;
            }
        }
        
        return false;
        
    }
};