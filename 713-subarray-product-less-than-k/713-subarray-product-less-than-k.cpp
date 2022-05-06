class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start =0, prod =1,ans=0;
        
        for(int end=0;end<nums.size();end++)
        {
            prod*=nums[end];
            
            while(prod>=k and start<=end)
            {
                prod/=nums[start];
                start++;                
            }
            
            ans+=(end-start+1);
        }
        
        return ans;
    }
};