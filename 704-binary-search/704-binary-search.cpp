class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int l=0,h=nums.size()-1;
        
        while(l<=h)
        {
            int mid = h - ((h-l)/2);
            
            if(nums[mid]==tar)
                return mid;
            
            else if(nums[mid]>tar)
                h=mid-1;
            
            else
                 l = mid +1;
        }
        
        return -1;
    }
};