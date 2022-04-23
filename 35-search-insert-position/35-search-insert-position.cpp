class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if(target<nums[0])
            return 0;
        
        if(target>nums[nums.size()-1])
            return nums.size();
        
        int low=0,high=nums.size()-1;
        
        while(low<=high)
        {
            int mid= ((low+high)/2);
            
            if((nums[mid]==target) or (target<nums[mid] and target>nums[mid-1]))
                return mid;
            
            else if(nums[mid]<target)
                low=mid+1;
            
            else if(nums[mid]>target)
                high=mid-1;
        }
        
        return -1;
    }
};