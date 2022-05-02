class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if(nums.size()==1)
            return nums;
        
        vector<int>even,odd;
        
        for(int i : nums)
        {
            if(i&1)
                odd.push_back(i);
            
            else even.push_back(i);
        }
        
        int j=0;
        for(int i : even)
            nums[j++]=i;
        
        for(int i : odd)
            nums[j++]=i;
        
        return nums;
        
    }
};