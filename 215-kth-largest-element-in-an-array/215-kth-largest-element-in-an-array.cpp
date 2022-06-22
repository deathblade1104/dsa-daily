class Solution {
public:
    int quickselect(int l, int r, int&k, vector<int>&nums)
    {
        int pivot  = nums[r] , p = l;        
        
        for(int i=l;i<r;i++)
            if(nums[i]<=pivot)
            {
                swap(nums[p],nums[i]);
                p++;
            }        
        
        swap(nums[p],nums[r]);
        
        if(p>k)
            return quickselect(l,p-1,k,nums);
        
        else if(p<k)
            return quickselect(p+1,r,k,nums);
        
        else return nums[p];
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
     //Quick Select Algo -->
        
        k = nums.size() - k;
        int sz = nums.size()-1;
        
        return quickselect(0,sz,k,nums);
    
        
        
    }
};