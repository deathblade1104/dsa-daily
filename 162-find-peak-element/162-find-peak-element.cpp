class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        if(nums.size()==1)
            return 0;
        
        int low=0, high = nums.size()-1;
        if(nums[0]>nums[1]) return 0;
        if(nums[high]>nums[high-1]) return high;
        
        low++;
        high--;
        while(low<=high)
        {
            int mid = low + ((high - low)/2);
            
            if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1])
                return mid;
            
            if(nums[mid]<nums[mid-1])
                high = mid-1;
            
            else low = mid + 1;
        }
        
        return -1;
    }
};