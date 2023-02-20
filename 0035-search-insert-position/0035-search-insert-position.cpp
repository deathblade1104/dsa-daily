class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int l = 0, h = nums.size()-1;
        
        if(nums[l]>=target){
            return l;
        }
        
        if(nums[h]<target)
            return h+1;
        
        
        int ans = -1;
        while(l<=h){
            
            int mid  = l + ((h - l)/2);
            
            if(nums[mid]>=target){
                ans = mid;
                h = mid - 1;
            }
            else {
                l = mid+1;
            }
        }
        
        return ans;
    }
};