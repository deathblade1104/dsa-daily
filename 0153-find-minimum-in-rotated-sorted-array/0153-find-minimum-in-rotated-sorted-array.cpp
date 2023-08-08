class Solution {
public:
    int findMin(vector<int>& nums) {
       int low = 0, high = nums.size() - 1;
        
        if(nums[low]<=nums[high])
            return nums[low];
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(nums[mid+1]<nums[mid])
                return nums[mid+1];
            
            
            if(nums[low]>nums[mid])
                high = mid -1;
            
            else low = mid +1;
        }
        
        return -1;
    }
};